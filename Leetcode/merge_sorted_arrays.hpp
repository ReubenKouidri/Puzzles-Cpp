#ifndef CODECHALLENGES_CPP_LEETCODE_MERGE_SORTED_ARRAYS_HPP_
#define CODECHALLENGES_CPP_LEETCODE_MERGE_SORTED_ARRAYS_HPP_

#include <iostream>
#include <vector>

void merge(std::vector<int>& vec1, const int m,
           const std::vector<int>& vec2, const int n) {
  int i = m - 1;
  int j = n - 1;
  int k = m + n - 1;
  while (j >= 0) {
    if (i >= 0 && vec1[i] > vec2[j]) {
      vec1[--k] = vec1[--i];
    } else { vec1[--k] = vec2[--j]; }
  }
}

#endif //CODECHALLENGES_CPP_LEETCODE_MERGE_SORTED_ARRAYS_HPP_
