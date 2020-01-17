#pragma once

#include <type_traits>

template <typename, template <typename...> class Op, typename... T>
struct is_detected_impl : std::false_type {};
template <template <typename...> class Op, typename... T>
struct is_detected_impl<std::void_t<Op<T...>>, Op, T...> : std::true_type {};

template <template <typename...> class Op, typename... T>
using is_detected = is_detected_impl<void, Op, T...>;