#ifndef CODECHALLENGES_CPP_LEETCODE_GREATEST_NUM_SWEETS_HPP_
#define CODECHALLENGES_CPP_LEETCODE_GREATEST_NUM_SWEETS_HPP_
/*
There are n kids with candies. You are given an integer array candies, where
 each candies[i] represents the number of candies the ith kid has,
 and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if,
 after giving the ith kid all the extraCandies,
 they will have the greatest number of candies among all the kids,
 or false otherwise.

Note that multiple kids can have the greatest number of candies.

Example 1:
Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true]

 Example 2:
Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false]

 Example 3:
Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]

Constraints:
n == candies.length
2 <= n <= 100
1 <= candies[i] <= 100
1 <= extraCandies <= 50
 */

#include <vector>
#include <cassert>

constexpr inline std::vector<bool> sweets(const std::vector<uint8_t>& candies,
                                          const uint8_t extra_candies) {
  std::vector<bool> results;
  results.reserve(candies.size());
  for (const auto candy : candies) {
    results.emplace_back(candy + extra_candies >= *std::max_element(
      candies.begin(), candies.end()));
  }
  return results;
}

void test() {
  assert(sweets({2, 3, 5, 1, 3}, 3) == std::vector<bool>({true, true, true, false, true}));
  assert(sweets({4, 2, 1, 1, 2}, 1) == std::vector<bool>({true, false, false, false, false}));
  assert(sweets({12, 1, 12}, 10) == std::vector<bool>({true, false, true}));
}

#endif //CODECHALLENGES_CPP_LEETCODE_GREATEST_NUM_SWEETS_HPP_
