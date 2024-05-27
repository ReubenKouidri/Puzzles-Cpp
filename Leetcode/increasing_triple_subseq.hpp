#ifndef CODECHALLENGES_CPP_INCREASING_TRIPLE_SUBSEQ_HPP
#define CODECHALLENGES_CPP_INCREASING_TRIPLE_SUBSEQ_HPP

#include <iostream>
#include <vector>

bool increasing_triplet(const std::vector<int>& nums) {
  if (nums.size() < 3) return false;
  int a = INT32_MAX;
  int b = INT32_MAX;
  for (const auto num : nums) {
    if (num <= a)
      a = num;
    else if (num <= b)  // a < num <= b
      b = num;
    else
      return true;  // a < b < num <=> triplet found
  }
  return false;
}

#endif //CODECHALLENGES_CPP_INCREASING_TRIPLE_SUBSEQ_HPP
