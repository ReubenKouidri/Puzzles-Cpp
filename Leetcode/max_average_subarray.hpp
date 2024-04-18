
#ifndef CODECHALLENGES_CPP_LEETCODE_MAX_AVERAGE_SUBARRAY_HPP_
#define CODECHALLENGES_CPP_LEETCODE_MAX_AVERAGE_SUBARRAY_HPP_

#include <vector>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <iostream>

double max_average_subarray(const std::vector<int>&& v, const int k) {
  double max = std::accumulate(v.begin(),v.begin() + k,0);
  for (size_t i = 0; i < v.size() - k; i++)
    max = std::max(max, max + v[i + k] - v[i]);
  return max / k;
}

void test() {
  assert(max_average_subarray({1, 12, -5, -6, 50, 3}, 4) == 12.75);
  assert(max_average_subarray({5}, 1) == 5);
}

#endif //CODECHALLENGES_CPP_LEETCODE_MAX_AVERAGE_SUBARRAY_HPP_
