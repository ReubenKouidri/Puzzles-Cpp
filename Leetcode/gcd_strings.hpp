#ifndef CODECHALLENGES_CPP_LEETCODE_GCD_STRINGS_HPP_
#define CODECHALLENGES_CPP_LEETCODE_GCD_STRINGS_HPP_

/*
For two strings s and t, we say "t divides s" if and only if
 s = t + t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x
 divides both str1 and str2.

Example 1:
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"

Example 2:
Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"

Example 3:
Input: str1 = "LEET", str2 = "CODE"
Output: ""

Constraints:
1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.
*/

#include <string>
#include <iostream>
#include <cassert>
#include <numeric>

std::string gcd_strings(const std::string& str1, const std::string& str2) {
  return str1 + str2 == str2 + str1 ?
         str1.substr(0, std::gcd(str1.size(), str2.size())) : "";
}

void test() {
  assert(gcd_strings("ABCABC", "ABC") == "ABC");
  assert(gcd_strings("ABABAB", "ABAB") == "AB");
  assert(gcd_strings("LEET", "CODE").empty());
}

#endif //CODECHALLENGES_CPP_LEETCODE_GCD_STRINGS_HPP_
