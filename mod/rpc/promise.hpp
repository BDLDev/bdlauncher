#pragma once
#include <functional>
#include <map>
#include <type_traits>
#include <vector>

template <typename T> class promise;

template <typename T> struct promise_ref { using type = T const &; };
template <typename T> struct promise_ref<promise<T>> { using type = T &&; };

template <typename T, typename R = void> struct void_fn { using type = std::function<R(T const &)>; };
template <typename R> struct void_fn<void, R> { using type = std::function<R()>; };
template <typename T, typename R = void> using void_fn_t = typename void_fn<T, R>::type;

template <typename T> struct unpromise;
template <typename T> struct unpromise<promise<T>> { using type = T; };
template <typename T> using unpromise_t = typename unpromise<T>::type;

template <typename T> struct is_promise { constexpr static auto value = false; };
template <typename T> struct is_promise<promise<T>> { constexpr static auto value = true; };
template <typename T> constexpr auto is_promise_v = is_promise<T>::value;

template <typename T> class promise {
  using then_fn                            = void_fn_t<T>;
  template <typename R> using transform_fn = void_fn_t<T, R>;
  using fail_fn                            = std::function<void(std::exception_ptr ex)>;

  then_fn _then;
  fail_fn _fail;
  std::function<void(then_fn, fail_fn)> body;

public:
  class resolver {
    then_fn _then;
    fail_fn _fail;
    resolver(then_fn _then, fail_fn _fail) : _then(_then), _fail(_fail) {}

  public:
    template <typename X, typename = std::enable_if_t<std::is_same_v<T, X> && !std::is_void_v<T>>>
    void resolve(X const &value) const {
      _then(value);
    }
    void resolve() const {
      static_assert(std::is_void_v<T>, "Non-void value required");
      _then();
    }
    void reject(std::exception_ptr ex) const { _fail(ex); }
    template <typename E> void reject(E ex) const { _fail(std::make_exception_ptr(ex)); }

    friend class promise;
  };
  promise(const promise &) = delete;
  promise &operator=(const promise &) = delete;
  promise(promise &&rhs) : body(rhs.body), _then(rhs._then), _fail(rhs._fail) { rhs.body = nullptr; }
  promise(std::function<void(then_fn, fail_fn)> f) : body(f) {}
  promise(std::function<void(resolver)> f) : body([=](auto th, auto fn) { f({th, fn}); }){};
  ~promise() {
    if (body) {
      try {
        if constexpr (std::is_void_v<T>) {
          body(
              _then ?: []() {}, _fail ?: [](auto) {});
        } else {
          body(
              _then ?: [](T const &) {}, _fail ?: [](auto) {});
        }
      } catch (...) {
        (_fail ?: [](auto) {})(std::current_exception());
      }
    }
  }
  promise<T> &then(then_fn _then) {
    if constexpr (std::is_void_v<T>)
      this->_then = this->_then ?
                        [last = this->_then, _then] {
                          last();
                          _then();
                        } :
                        _then;
    else
      this->_then = this->_then ?
                        [last = this->_then, _then](auto v) {
                          last(v);
                          _then(v);
                        } :
                        _then;
    return *this;
  }
  template <typename R> auto then(transform_fn<R> fn) {
    auto next = body;
    body      = nullptr;
    if constexpr (std::is_void_v<T>) {
      if constexpr (is_promise_v<R>)
        return R{[=](auto th, auto fa) { next([=] { fn().then(th).fail(fa); }, fa); }};
      else if constexpr (std::is_void_v<R>)
        return promise<R>{[=](auto th, auto fa) { next([=]() { fn(), th(); }, fa); }};
      else
        return promise<R>{[=](auto th, auto fa) { next([=]() { th(fn()); }, fa); }};
    } else {
      if constexpr (is_promise_v<R>)
        return R{[=](auto th, auto fa) { next([=](T const &t) { fn(t).then(th).fail(fa); }, fa); }};
      else if constexpr (std::is_void_v<R>)
        return promise<R>{[=](auto th, auto fa) { next([=](T const &t) { fn(t), th(); }, fa); }};
      else
        return promise<R>{[=](auto th, auto fa) { next([=](T const &t) { th(fn(t)); }, fa); }};
    }
  }
  promise<T> &fail(fail_fn _fail) {
    this->_fail = _fail;
    return *this;
  }

  template <
      typename X, typename F,
      typename = std::enable_if_t<std::is_same_v<promise<T>, std::invoke_result_t<F, X>> && !std::is_void_v<T>>>
  static promise<std::vector<T>> map_all(std::vector<X> &&inputs, F &&f) {
    return promise<std::vector<T>>{[inputs{std::move(inputs)}, f{std::move(f)}](auto resolver) {
      size_t i         = 0;
      const size_t max = inputs.size();
      for (auto &val : inputs) {
        f(val)
            .then([=, cur = 0, results = std::map<size_t, T>{}](auto value) mutable {
              results[i] = value;
              if (++cur == max) {
                std::vector<T> res;
                std::transform(
                    results.begin(), results.end(), std::back_inserter(res), [](auto pair) { return pair.second; });
                resolver.resolve(res);
              }
            })
            .fail([=, invoked = false](auto e) mutable {
              if (!invoked) {
                invoked = true;
                resolver.reject(e);
              }
            });
        i++;
      }
    }};
  }

  template <
      typename X, typename F,
      typename = std::enable_if_t<std::is_same_v<promise<T>, std::invoke_result_t<F, X>> && std::is_void_v<T>>>
  static promise<void> map_all(std::vector<X> &&inputs, F &&f) {
    return promise<T>{[inputs{std::move(inputs)}, f{std::move(f)}](auto resolver) {
      const size_t max = inputs.size();
      for (auto &val : inputs) {
        f(val)
            .then([=, cur = 0]() mutable {
              if (++cur == max) { resolver.resolve(); }
            })
            .fail([=, invoked = false](auto e) mutable {
              if (!invoked) {
                invoked = true;
                resolver.reject(e);
              }
            });
      }
    }};
  }

  template <typename X, typename F, typename = std::enable_if_t<std::is_same_v<promise<T>, std::invoke_result_t<F, X>>>>
  static promise<T> map_any(std::vector<X> &&inputs, F &&f) {
    return promise<T>{[inputs{std::move(inputs)}, f{std::move(f)}](auto resolver) {
      const size_t max = inputs.size();
      for (auto &val : inputs) {
        if constexpr (std::is_void_v<T>)
          f(val)
              .then([=, invoked = false]() mutable {
                if (!invoked) {
                  invoked = true;
                  resolver.resolve();
                }
              })
              .fail([=, cur = 0](auto e) mutable {
                if (++cur == max) { resolver.reject(e); }
              });
        else
          f(val)
              .then([=, invoked = false](auto val) mutable {
                if (!invoked) {
                  invoked = true;
                  resolver.resolve(val);
                }
              })
              .fail([=, cur = 0](auto e) mutable {
                if (++cur == max) { resolver.reject(e); }
              });
      }
    }};
  }
};