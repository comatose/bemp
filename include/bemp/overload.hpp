#pragma once

#include <type_traits>
#include <utility>

template <class... Ts>
struct overload : Ts... {
  using Ts::operator()...;
  template <typename T>
  constexpr void operator()(T) const {}
};

template <class... Ts>
overload<std::decay_t<Ts>...> make_overload(Ts&&... ts) {
  return {std::forward<Ts>(ts)...};
}
