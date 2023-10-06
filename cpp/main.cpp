#include "profile.hpp"


int main() {
  constexpr int num_profiles = 1000000;
  std::vector<std::string> new_hobbies = {"listening to audiobooks and podcasts",
                                          "playing rec sports like bowling and kickball",
                                          "writing a speculative sailing novel",
                                          "reading advice columns"};
  for (int p = 0; p < num_profiles; p++) {
    Profile sam(20, "Sam", "London", "UK", {"music", "skiing"}, "he/him");
    for (const auto& hobby: new_hobbies) {
      sam.add_hobby(hobby);
    }
  }
  exit(0);
};
