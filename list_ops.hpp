#ifndef CODECHALLENGES_LIST_OPS_HPP
#define CODECHALLENGES_LIST_OPS_HPP

#include <iostream>
#include <list>

class SensorData {
  std::list<double> data_;
public:
  void add_reading(double&& reading) {
    data_.emplace_back(reading);
  }

  void smooth_data() {
    auto it2 = data_.begin();
    auto it1 = data_.begin();

    while (it1++ != data_.end()) {
      if (*it1 >= 2 * (*it2) || *it1 <= 0.5 * (*it2)) {
        *it1 = *it2;
      }
      ++it2;
    }
  }

  void print_data() const {
    for (double d : data_) {
      std::cout << d << " ";
    }
  }
};

void list_ops() {
  SensorData s;
  s.add_reading(1.0);
  s.add_reading(1.1);
  s.add_reading(1.5);
  s.add_reading(7);
  s.add_reading(2);
  s.add_reading(0.1);
  s.add_reading(0.5);
  s.print_data();
  s.smooth_data();
  std::cout << '\n';
  s.print_data();
}

#endif //CODECHALLENGES_LIST_OPS_HPP
