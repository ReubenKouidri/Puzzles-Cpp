#ifndef CODECHALLENGES_CPP_LEETCODE_PRODUCT_OF_ARRAY_HPP_
#define CODECHALLENGES_CPP_LEETCODE_PRODUCT_OF_ARRAY_HPP_

/*
Given an integer array nums, return an array answer such that answer[i]
 is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums
 is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time
 and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Constraints:
2 <= nums.length <= 105
-30 <= nums[i] <= 30

Follow up: Can you solve the problem in O(1) extra space complexity?
(The output array does not count as extra space for space complexity analysis.)
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <ranges>

std::vector<int> product_of_array(std::vector<int>&& nums) {
  const auto n = nums.size();
  std::vector<int> left_prods(n, 1);
  std::vector<int> right_prods(n, 1);
  std::vector<int> result(n);

  for (size_t i{0}; i < n; i++) {

  }
  return result;
}

void test() {
  assert(product_of_array({1, 2, 3, 4}) == std::vector<int>({24, 12, 8, 6}));
  assert(product_of_array({-1, 1, 0, -3, 3}) ==
    std::vector<int>({0, 0, 9, 0, 0}));
}

#endif //CODECHALLENGES_CPP_LEETCODE_PRODUCT_OF_ARRAY_HPP_
