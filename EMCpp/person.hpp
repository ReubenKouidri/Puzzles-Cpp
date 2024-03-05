#ifndef CODECHALLENGES_CPP_EMCPP_PERSON_HPP
#define CODECHALLENGES_CPP_EMCPP_PERSON_HPP

#include <string>

class Person {
  std::string name_{};

  friend std::ostream &operator<<(std::ostream &os, const Person &person) {
    return os << person.name_;
  }

 public:
  constexpr Person() noexcept = default;
  Person(const Person &rhs);
  Person(Person &&rhs) noexcept;
};

Person::Person(const Person &rhs) {
  name_ = rhs.name_;
}

Person::Person(Person &&rhs) noexcept
  : name_(std::move(rhs.name_)) {}

#endif //CODECHALLENGES_CPP_EMCPP_PERSON_HPP
