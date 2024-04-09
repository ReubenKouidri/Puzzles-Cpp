#ifndef CODECHALLENGES_CPP_LEETCODE_FLOWERBED_HPP_
#define CODECHALLENGES_CPP_LEETCODE_FLOWERBED_HPP_

/*
You have a long flowerbed in which some of the plots are planted,
 and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's,
 where 0 means empty and 1 means not empty, and an integer n,
 return true if n new flowers can be planted in the flowerbed without
 violating the no-adjacent-flowers rule and false otherwise.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

Constraints:
1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length
*/

#include <vector>
#include <cassert>
#include <iostream>

bool can_place_flowers(std::vector<int>&& flowerbed, int n) {
  int count = 0; // Counter for available spots
  const size_t size = flowerbed.size();

  for (size_t i = 0; i < size && count < n; ++i) {
    // Check if current, previous, and next spots are empty
    if (flowerbed[i] == 0 &&
      (i == 0 || flowerbed[i - 1] == 0) &&
      (i == size - 1 || flowerbed[i + 1] == 0)) {
      flowerbed[i] = 1; // Place a flower here
      ++count; // Increment count as we have placed a flower
    }
  }

  return count >= n;
}


void test() {
  assert(can_place_flowers({1, 0, 0, 0, 1}, 1) == true);
  assert(can_place_flowers({1, 0, 0, 0, 1}, 2) == false);
  assert(can_place_flowers({1, 0, 0, 0, 0}, 2) == true);
  assert(can_place_flowers({1, 0, 0, 0, 0, 1}, 2) == false);
  assert(can_place_flowers({0}, 1) == true);
  assert(can_place_flowers({0, 1}, 1) == false);
  assert(can_place_flowers({0, 0, 1}, 1) == true);
  assert(can_place_flowers({0, 0, 1, 0, 1}, 1) == true);
}

#endif //CODECHALLENGES_CPP_LEETCODE_FLOWERBED_HPP_