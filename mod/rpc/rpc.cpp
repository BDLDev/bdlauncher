#include <exception>
#include <iostream>
#include "rpc.hpp"

namespace rpc {

RPC::RPC(decltype(io) &&io) : io(std::move(io)) {
  reg("rpc.on", [this](std::shared_ptr<server_io::client> client, Json::Value const &input) -> Json::Value {
    if (input.isArray()) {
      Json::Value lists{Json::objectValue};
      for (auto item : input) {
        if (item.isString()) {
          lists[item.asString("")] = "provided event invalid";
        } else
          throw InvalidParams{};
      }
      for (auto i = lists.begin(); i != lists.end(); i++) {
        auto k  = i.key().asString("");
        auto it = std::find(server_events.begin(), server_events.end(), k);
        if (it != server_events.end()) {
          server_event_map[k].emplace(client);
          *it = "ok";
        }
      }
      return lists;
    } else
      throw InvalidParams{};
  });
  reg("rpc.off", [this](std::shared_ptr<server_io::client> client, Json::Value const &input) -> Json::Value {
    if (input.isArray()) {
      Json::Value lists{Json::objectValue};
      for (auto item : input) {
        if (item.isString()) {
          lists[item.asString("")] = "provided event invalid";
        } else
          throw InvalidParams{};
      }
      for (auto i = lists.begin(); i != lists.end(); i++) {
        auto k  = i.key().asString("");
        auto it = std::find(server_events.begin(), server_events.end(), k);
        if (it != server_events.end()) {
          if (server_event_map[k].erase(client) == 0)
            *it = "not subscribed";
          else
            *it = "ok";
        }
      }
      return lists;
    } else
      throw InvalidParams{};
  });
}

RPC::~RPC() {}

void RPC::event(std::string_view name) {
  std::lock_guard guard{mtx};
  server_events.emplace_back(name);
}

void RPC::emit(std::string const &name, Json::Value const &data) {
  auto obj = ({
    Json::Value ret{Json::ValueType::objectValue};
    ret["notification"] = {name};
    ret["params"]       = {data};
    Json::FastWriter writer;
    writer.write(ret);
  });
  std::lock_guard guard{mtx};
  auto it = server_event_map.find(name);
  if (it != server_event_map.end()) {
    auto set = it->second;
    auto p   = set.begin();
    auto end = set.end();
    while (p != end) {
      auto ptr = p->lock();
      if (ptr) {
        ptr->send(obj);
        ++p;
      } else {
        set.erase(p++);
      }
    }
  }
}

void RPC::reg(std::string_view name, maybe_async_handler cb) {
  std::lock_guard guard{mtx};
  methods.emplace(name, cb);
}

size_t RPC::reg(std::regex rgx, maybe_async_proxy_handler cb) {
  std::lock_guard guard{mtx};
  proxied_methods.emplace_back(rgx, cb, unqid++);
  return unqid - 1;
}

void RPC::unreg(std::string const &name) {
  std::lock_guard guard{mtx};
  methods.erase(name);
}

void RPC::unreg(size_t uid) {
  std::lock_guard guard{mtx};
  proxied_methods.erase(
      std::remove_if(proxied_methods.begin(), proxied_methods.end(), [&](auto x) { return std::get<2>(x) == uid; }),
      proxied_methods.end());
}

void RPC::start() {
  io->accept([](auto...) {}, [this](auto... x) { incoming(x...); });
}

void RPC::stop() { io->shutdown(); }

struct Invalid : std::runtime_error {
  Invalid(char const *msg) : runtime_error(msg) {}
};

template <typename MsgType> static inline Json::Value build_err(int code, MsgType msg, Json::Value const &data = {}) {
  Json::Value ret{Json::ValueType::objectValue};
  ret["code"] = {code};
  ret["msg"]  = msg;
  if (!data.isNull()) ret["data"] = data;
  return ret;
}

template <typename MsgType> static inline Json::Value build_result(MsgType result, Json::Value const &id) {
  Json::Value ret{Json::ValueType::objectValue};
  ret["result"] = result;
  ret["id"]     = id;
  return ret;
}

static inline Json::Value build_err_obj(Json::Value const &err, Json::Value const &id = {}) {
  Json::Value ret{Json::ValueType::objectValue};
  ret["jsonrpc"] = {"2.0"};
  ret["error"]   = err;
  ret["id"]      = id;
  return ret;
}

static inline void handle_exception(
    std::exception_ptr ep, std::recursive_mutex &mtx, std::shared_ptr<server_io::client> client,
    Json::Value const &id) {
  Json::FastWriter writer;
  try {
    if (ep) std::rethrow_exception(ep);
  } catch (InvalidParams const &e) {
    std::lock_guard guard{mtx};
    auto err = build_err(-32602, e.what());
    auto ret = build_err_obj(err, id);
    client->send(writer.write(ret));
  } catch (RemoteException const &e) {
    auto ret = build_err_obj(e.full, id);
    client->send(writer.write(ret));
  } catch (std::exception const &e) {
    auto err = build_err(-32000, e.what());
    auto ret = build_err_obj(err, id);
    client->send(writer.write(ret));
  }
}

template <class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template <class... Ts> overloaded(Ts...)->overloaded<Ts...>;

void RPC::incoming(std::shared_ptr<server_io::client> client, std::string_view data) {
  Json::FastWriter writer;
  try {
    Json::Reader reader;
    Json::Value parsed;
    if (!reader.parse(&data[0], data.size(), parsed, false))
      throw std::runtime_error(reader.getFormattedErrorMessages());
    if (!parsed.isObject()) throw Invalid{"object required"};
    if (parsed["jsonrpc"] != "2.0") throw Invalid{"jsonrpc version mismatch"};
    auto method_ = parsed["method"];
    auto params  = parsed["params"];
    auto id      = parsed["id"];
    if (!method_.isString()) throw Invalid{"method need to be a string"};
    if (!params.isArray() && !params.isObject()) throw Invalid{"params need to be a object or array"};
    if (!id.isNull() || !id.isString() || !id.isIntegral()) throw Invalid{"id need to be a primitive"};
    auto method = method_.asString("");

    std::lock_guard guard{mtx};
    if (auto it = methods.find(method); it == methods.end()) {
      bool matched = false;
      for (auto &[k, v, _] : proxied_methods) {
        if (std::smatch res; std::regex_match(method, res, k)) {
          std::visit(
              overloaded{
                  [&](std::function<Json::Value(std::shared_ptr<server_io::client>, std::smatch, Json::Value const &)>
                          sync) {
                    try {
                      auto result = sync(client, res, params);
                      if (!id.isNull()) {
                        auto ret = build_result(result, id);
                        client->send(writer.write(ret));
                      }
                    } catch (...) { handle_exception(std::current_exception(), mtx, client, id); }
                  },
                  [&](std::function<promise<Json::Value>(
                          std::shared_ptr<server_io::client>, std::smatch, Json::Value const &)>
                          async) {
                    async(client, res, params)
                        .then([=](Json::Value const &result) {
                          if (!id.isNull()) {
                            Json::FastWriter writer;
                            auto ret = build_result(result, id);
                            client->send(writer.write(ret));
                          }
                        })
                        .fail([=](std::exception_ptr ptr) { handle_exception(ptr, mtx, client, id); });
                  },
              },
              v);
          matched = true;
          break;
        }
      }
      if (!matched) {
        std::lock_guard guard{mtx};
        auto err = build_err(-32601, "method not found");
        auto ret = build_err_obj(err, id);
        client->send(writer.write(ret));
      }
    } else {
      std::visit(
          overloaded{
              [&](std::function<Json::Value(std::shared_ptr<server_io::client>, Json::Value const &)> const &sync) {
                try {
                  auto result = sync(client, params);
                  if (!id.isNull()) {
                    auto ret = build_result(result, id);
                    client->send(writer.write(ret));
                  }
                } catch (...) { handle_exception(std::current_exception(), mtx, client, id); }
              },
              [&](std::function<promise<Json::Value>(std::shared_ptr<server_io::client>, Json::Value const &)> const
                      &async) {
                async(client, params)
                    .then([=](Json::Value const &result) {
                      if (!id.isNull()) {
                        Json::FastWriter writer;
                        auto ret = build_result(result, id);
                        client->send(writer.write(ret));
                      }
                    })
                    .fail([=](std::exception_ptr ptr) { handle_exception(ptr, mtx, client, id); });
              },
          },
          it->second);
    }
  } catch (Invalid const &e) {
    std::lock_guard guard{mtx};
    auto err = build_err(-32600, e.what());
    auto ret = build_err_obj(err);
    client->send(writer.write(ret));
  } catch (...) {
    std::lock_guard guard{mtx};
    auto err = build_err(-32000, "Unknown error");
    auto ret = build_err_obj(err);
    client->send(writer.write(ret));
  }
}

RPC::Client::Client(std::unique_ptr<client_io> &&io) : io(std::move(io)) {}

RPC::Client::~Client() { io->shutdown(); }

promise<Json::Value> RPC::Client::call(std::string const &name, Json::Value const &data) {
  return {[=](auto resolver) {
    Json::FastWriter writer;
    Json::Value req{Json::ValueType::objectValue};
    req["jsonrpc"] = {"2.0"};
    req["method"]  = {name};
    req["params"]  = {data};
    req["id"]      = {last_id};
    {
      std::lock_guard guard{mtx};
      regmap.emplace(last_id++, resolver);
    }
    io->send(writer.write(req));
  }};
}

void RPC::Client::notify(std::string_view name, Json::Value const &data) {
  Json::FastWriter writer;
  Json::Value req{Json::ValueType::objectValue};
  req["jsonrpc"] = {"2.0"};
  req["method"]  = {name};
  req["params"]  = {data};
  io->send(writer.write(req));
}

promise<bool> RPC::Client::on(std::string_view name, RPC::Client::data_fn list) {
  event_map.emplace(name, list);
  Json::Value names{Json::ValueType::arrayValue};
  names[0] = {name};
  return call("rpc.on", names).then<bool>([name = std::string(name)](Json::Value const &ret) {
    return ret.isObject() && ret[name].asString("error") == "ok";
  });
}

promise<bool> RPC::Client::off(std::string const &name) {
  event_map.erase(name);
  Json::Value names{Json::ValueType::arrayValue};
  names[0] = {name};
  return call("rpc.off", names).then<bool>([name = name](Json::Value const &ret) {
    return ret.isObject() && ret[name].asString("error") == "ok";
  });
}

void RPC::Client::incoming(std::string_view data) {
  try {
    Json::Reader reader;
    Json::Value parsed;
    if (!reader.parse(&data[0], data.size(), parsed, false))
      throw std::runtime_error(reader.getFormattedErrorMessages());
    if (!parsed.isObject()) throw Invalid{"object required"};
    auto &notification = parsed["notification"];
    if (notification.isString()) {
      auto name = parsed["notification"].asString("");
      std::lock_guard guard{mtx};
      if (auto it = event_map.find(name); it != event_map.end()) {
        auto &[k, fn] = *it;
        fn(parsed["params"]);
      }
    } else {
      if (parsed["jsonrpc"] != "2.0") throw Invalid{"jsonrpc version mismatch"};
      auto result = parsed["result"];
      auto error  = parsed["error"];
      auto id     = parsed["id"];

      std::lock_guard guard{mtx};
      if (auto it = regmap.find(id.asUInt(0)); it != regmap.end()) {
        auto &[_, resolver] = *it;
        if (error.isObject()) {
          resolver.reject(RemoteException{error});
        } else {
          resolver.resolve(result);
        }
        regmap.erase(it);
      }
    }
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    stop();
  }
}

promise<void> RPC::Client::start() {
  return {[this](auto resolver) { this->io->recv([=](auto data) { incoming(data); }, resolver); }};
}

void RPC::Client::stop() {
  std::lock_guard guard{mtx};
  this->io->shutdown();
}

} // namespace rpc
