#ifndef CODECHALLENGES_CPP_LEETCODE_MERGE_STRINGS_ALTERNATIVELY_HPP_
#define CODECHALLENGES_CPP_LEETCODE_MERGE_STRINGS_ALTERNATIVELY_HPP_


/*
You are given two strings word1 and word2.
Merge the strings by adding letters in alternating order, starting with word1.
If a string is longer than the other, append the additional letters onto the
 end of the merged string.

Return the merged string.

Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"

 Example 2:
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s

Example 3:
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q
merged: a p b q c   d

Constraints:
1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
*/

#include <string>
#include <iostream>
#include <cassert>

std::string merge_alt(const std::string& word1, const std::string& word2) {
  std::string str;
  size_t i = 0;
  while (i < word1.size() && i < word2.size()) {
    str += word1[i];
    str += word2[i];
    i++;
  }
  if (i < word1.size()) {
    str += word1.substr(i, std::string::npos);
  }
  if (i < word2.size()) {
    str += word2.substr(i, std::string::npos);
  }
  return str;
}

void test() {
  assert(merge_alt("pqr", "ab") == "paqbr");
  assert(merge_alt("pqrs", "abcd") == "paqbrcsd");
  assert(merge_alt("ab", "cde") == "acbde");
}

#endif //CODECHALLENGES_CPP_LEETCODE_MERGE_STRINGS_ALTERNATIVELY_HPP_
