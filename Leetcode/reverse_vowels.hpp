#ifndef CODECHALLENGES_CPP_LEETCODE_REVERSE_VOWELS_HPP_
#define CODECHALLENGES_CPP_LEETCODE_REVERSE_VOWELS_HPP_

/*
Given a string s, reverse only all the vowels in the string and return it.

Example 1:
Input: s = "hello"
Output: "holle"

Example 2:
Input: s = "leetcode"
Output: "leotcede"

Constraints:
1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/

#include <string>
#include <unordered_set>
#include <cassert>

std::string reverse_vowels(std::string&& s) {
  const std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                 'A', 'E', 'I', 'O', 'U'};
  auto left_it = s.begin();
  auto right_it = s.end() - 1;
  while (left_it < right_it) {
    while (left_it != right_it && !vowels.contains(*left_it)) {
      left_it++;
    }
    while (right_it != left_it && !vowels.contains(*right_it)) {
      right_it--;
    }
    if (left_it < right_it) {
      std::iter_swap(left_it, right_it);
      left_it++;
      right_it--;
    }
  }
  return s;
}

void test() {
  assert(reverse_vowels("hello") == "holle");
  assert(reverse_vowels("leetcode") == "leotcede");
}

#endif //CODECHALLENGES_CPP_LEETCODE_REVERSE_VOWELS_HPP_
