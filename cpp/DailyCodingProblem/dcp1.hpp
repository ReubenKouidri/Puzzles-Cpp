#ifndef CODECHALLENGES_DCP1_HPP
#define CODECHALLENGES_DCP1_HPP

/*
 * Given a list of numbers and a number k,
 * return whether any two numbers from the list add up to k.
 * For example, given [10, 15, 3, 7] and k of 17,
 * return true since 10 + 7 is 17.
 */

#include <vector>
#include <iostream>

template <typename T>
bool dp1(const std::vector<T>& vec, const T k) {
  for (std::size_t i{0}; i < vec.size() - 1; i++) {
    for (auto j{i + 1}; j < vec.size(); j++) {
      if (vec[i] + vec[j] == k) {
        return true;
      }
    }
  }
  return false;
}

void dcp1() {
  auto v = std::vector<int>{10, 15, 3, 7};
  auto val = dp1(const_cast<std::vector<int>&>(v), 11);
  std::cout << std::boolalpha << val << '\n';
}
#endif //CODECHALLENGES_DCP1_HPP
