#ifndef CODECHALLENGES_CPP_CPP_CON_RANGES_OVERVIEW_OF_RANGES_2_HPP
#define CODECHALLENGES_CPP_CPP_CON_RANGES_OVERVIEW_OF_RANGES_2_HPP

/*
 * Section 1/3: Least Element in an Array
 * Given a non-empty array of integers, find the least element
 */

#include <vector>
#include <ranges>

constexpr std::vector<int> get_input() {
  return std::vector<int> {0, -1, 2, -3, 4, -5, 6, -7, 8, -9};
}

void part_1() {
  std::vector<int> input = get_input();
  // pre-ranges
  auto iter = std::min_element(input.begin(), input.end());
  // using ranges:
  auto iter2 = std::ranges::min_element(input);
  /* Usually, once the statement is executed, the rvalue from get_input()
   is destroyed. This would leave a dangling iterator
   (pointing to freed memory). However, ranges handles this and sets the
   return type to be std::ranges::dangling.
  */
  auto iter3 = std::ranges::min_element(get_input());
}

#endif //CODECHALLENGES_CPP_CPP_CON_RANGES_OVERVIEW_OF_RANGES_2_HPP
