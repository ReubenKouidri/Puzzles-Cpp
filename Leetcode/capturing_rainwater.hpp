#ifndef CODECHALLENGES_CPP_LEETCODE_CAPTURING_RAINWATER_HPP_
#define CODECHALLENGES_CPP_LEETCODE_CAPTURING_RAINWATER_HPP_

#include <vector>
#include <cassert>

int trap(const std::vector<int>& h) {
  if (h.empty()) return 0;

  int l = 0, r = static_cast<int>(h.size() - 1);
  int lmax = INT_MIN;
  int rmax = INT_MIN;

  int vol = 0;
  while (l < r) {
    lmax = std::max(lmax, h[l]);
    rmax = std::max(rmax, h[r]);
    vol +=
      lmax < rmax ? std::max(0, lmax - h[l++]) : std::max(0, rmax - h[r--]);
  }
  return vol;
}

void test() {
  assert(trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) == 6);
  assert(trap({4, 2, 0, 3, 2, 5}) == 9);
  assert(trap({5, 4, 1, 2}) == 1);
  assert(trap({6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4,
               6, 8, 1, 3}) == 83);
  assert(trap({9, 6, 8, 8, 5, 6, 3}) == 3);
  assert(trap({8, 8, 1, 5, 6, 2, 5, 3, 3, 9}) == 31);
}

#endif //CODECHALLENGES_CPP_LEETCODE_CAPTURING_RAINWATER_HPP_
