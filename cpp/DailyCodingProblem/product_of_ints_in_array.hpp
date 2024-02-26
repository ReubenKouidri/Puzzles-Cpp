#ifndef CODECHALLENGES_DAILYCODINGPROBLEM_PRODUCT_OF_INTS_IN_ARRAY_HPP_
#define CODECHALLENGES_DAILYCODINGPROBLEM_PRODUCT_OF_INTS_IN_ARRAY_HPP_

/* Given an array of integers, return a new array such that each element
 * at index i of the new array is the product of all the numbers in the
 * original array except the one at i.

 * For example, if our input was [1, 2, 3, 4, 5],
 * the expected output would be [120, 60, 40, 30, 24].
 * If our input was [3, 2, 1], the expected output would be [2, 3, 6].

 * Follow-up: what if you can't use division? */

#include <concepts>
#include <iostream>
#include <numeric>
#include <vector>
#include <ranges>

template <typename T>
concept is_num = std::is_floating_point<T>::value || std::is_integral<T>::value;

template <is_num T>
constexpr void print(const std::vector<T>& v) noexcept {
  std::ranges::copy(v, std::ostream_iterator<T>(std::cout, " "));
  std::cout << '\n';
}

template <is_num T>
std::vector<T> part1(const std::vector<T>& v) {
  std::vector<T> new_vec;
  new_vec.reserve(v.size());

  for (size_t i{0}; i < v.size(); i++) {
    new_vec.emplace_back(
      std::reduce(v.begin(), v.end(), 1, std::multiplies<T>{}) / v[i]);
  }
  return new_vec;
}

template <is_num T>
std::vector<T> part2(const std::vector<T>& v) {
  std::vector<T> new_vec;
  new_vec.reserve(v.size());

  for (size_t i{0}; i < v.size(); i++) {
    is_num auto sum = static_cast<T>(1);
    for (size_t j{0}; j < v.size(); j++) {
      sum *= j != i ? v[j] : static_cast<T>(1);
    }
    new_vec.emplace_back(sum);
  }
  return new_vec;
}

#endif//CODECHALLENGES_DAILYCODINGPROBLEM_PRODUCT_OF_INTS_IN_ARRAY_HPP_
