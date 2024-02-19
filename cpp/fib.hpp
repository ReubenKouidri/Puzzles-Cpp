#ifndef CODECHALLENGES_FIB_HPP
#define CODECHALLENGES_FIB_HPP

#include <array>
#include <iostream>

template <typename T, std::size_t N>
constexpr std::size_t arraySize(std::array<T, N>) noexcept {
  return N;
}

template <std::size_t N>
std::size_t fib(const std::size_t n) {
  static std::array<std::size_t, N> cache{};
  if (n == 0 || n == 1) return 1;
  if (cache[n] == 0)
    cache[n] = fib<N>(n - 1) + fib<N>(n - 2);
  return cache[n];
}

inline void run_fib() {
  constexpr std::size_t n = 100;
  auto combinations = fib<n>(n);
  std::cout << combinations;
}

#endif //CODECHALLENGES_FIB_HPP
