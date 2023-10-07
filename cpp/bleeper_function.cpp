#include <iostream>
#include <string>
#include <algorithm>


void bleep(const std::string& word, std::string& text) {
  const char replacement = '*';
  size_t pos = text.find(word);
  std::transform(text.begin(), text.end(), text.begin(),
                 [](unsigned char c) { return std::tolower(c); });

  while (pos != std::string::npos) {
    std::fill(text.begin() + pos, text.begin() + pos + word.length(), replacement);
    pos = text.find(word, pos + 1);
  }
}

int main() {
  std::string word{"broccoli"};
  std::string text{"For lunch, i ate broccoli. I also ate broccoli for dinner... Broccoli!"};
  bleep(word, text);
  std::cout << text << '\n';
  return 0;
};
