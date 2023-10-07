
#include "profile.hpp"

Profile::Profile(
    int age,
    std::string name = "No name provided",
    std::string city = "No city provided",
    std::string country = "No country provided",
    std::vector<std::string> hobbies = std::vector<std::string>(),
    std::string pronouns = "they/them"
) : age(age)
, name(std::move(name))
, city(std::move(city))
, country(std::move(country))
, hobbies(std::move(hobbies))
, pronouns(std::move(pronouns)) {}

std::string Profile::view_profile() const {
  std::string bio;
  bio += "Name: " + name + '\n';
  bio += "Age: " + std::to_string(age) + '\n';
  bio += "City: " + city + '\n';
  bio += "Country: " + country + '\n';
  bio += "Hobbies: \n";
  for (const auto& hobby: hobbies) {
    bio += "  " + hobby + '\n';
  }
  bio += "Pronouns: " + pronouns + '\n';
  return bio;
}

void Profile::add_hobby(std::string new_hobby) {
  hobbies.push_back(std::move(new_hobby));
}
