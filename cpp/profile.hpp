
#ifndef PROFILE_HPP
#define PROFILE_HPP

#include <string>
#include <vector>

class Profile {
private:
  int age;
  std::string name;
  std::string city;
  std::string country;
  std::string pronouns;
  std::vector<std::string> hobbies;

public:
  Profile(
      int age,
      std::string name,
      std::string city,
      std::string country,
      std::vector<std::string> hobbies,
      std::string pronouns);

  [[nodiscard]] std::string view_profile() const;
  void add_hobby(std::string new_hobby);

};


#endif //PROFILE_HPP
