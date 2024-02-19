#ifndef CODECHALLENGES_BLEEPER_FUNCTION_HPP
#define CODECHALLENGES_BLEEPER_FUNCTION_HPP

#include <iostream>
#include <string>
#include <algorithm>


inline void bleep(const std::string& word, std::string& text) {
  const char replacement = '*';
  long pos = static_cast<long>(text.find(word));
  std::transform(text.begin(), text.end(), text.begin(),
                 [](unsigned char c) { return std::tolower(c); });

  while (pos != std::string::npos) {
    std::fill(text.begin() + pos,
              text.begin() + pos + static_cast<long>(word.length()),
              replacement);
    pos = static_cast<long>(text.find(word, static_cast<size_t>(pos + 1)));
  }
}

inline void bleeper_function() {
  std::string word{"broccoli"};
  std::string text{"For lunch, i ate broccoli. I also ate broccoli for dinner... Broccoli!"};
  bleep(word, text);
  std::cout << text << '\n';
};

#endif  // CODECHALLENGES_BLEEPER_FUNCTION_HPP
