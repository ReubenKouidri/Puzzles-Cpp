#ifndef CODECHALLENGES_DAILYCODINGPROBLEM_FIRST_MISSING_INTEGER_HPP_
#define CODECHALLENGES_DAILYCODINGPROBLEM_FIRST_MISSING_INTEGER_HPP_

/* Given an array of integers, find the first missing positive integer
 * in linear time and constant space.
 * In other words, find the lowest positive integer that
 * does not exist in the array.
 * The array can contain duplicates and negative numbers as well.
 *
 * For example, the input [3, 4, -1, 1] should give 2.
 * The input [1, 2, 0] should give 3.
 *
 * You can modify the input array in-place.
 *
 * METHOD = Index mapping:
 * each value should be moved to it's POSITION in the array (NOT INDEX)
 * e.g. 1 -> first position <=> index 0
 * e.g. 2 -> second position <=> index 1
 * => if 0 < v <= N, map v -> v - 1
 * ignore values larger than N or less than 0
 * You will end up with a sorted array which you can iterate through.
 * The first gap in the array is the missing number and will occur
 * at index i + 1.
 * e.g. [3, 4, -1, 1] -> [1, -1, 3, 4] => missing number = 2
*/

#include <iostream>
#include <vector>

template <std::size_t N>
constexpr void map_idices(std::array<int, N>& arr) {
  for (size_t i = 0; i < N; ++i) {
    while (arr[i] != int(i + 1) && arr[i] > 0 && arr[i] <= int(N)) {
      int v = arr[i];
      if (arr[size_t(v - 1)] == v) {
        break;
      }
      std::swap(arr[i], arr[size_t(v - 1)]);
    }
  }
}

template <std::size_t N>
constexpr size_t find_missing_int(std::array<int, N>& arr) {
  if (arr.empty()) { return 1; }
  map_idices(arr);

  for (size_t i = 0; i < N; ++i) {
    if ((size_t)arr[i] != i + 1) { return i + 1; }
  }
  return N;
}

#endif//CODECHALLENGES_DAILYCODINGPROBLEM_FIRST_MISSING_INTEGER_HPP_
