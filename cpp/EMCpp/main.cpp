#include <iostream>
#include "Chapter_5/move_semantics/move_and_forward.hpp"

int main() {
  auto w1 = Widget();
  w1.set_name("w1");
  auto w2 = Widget();
  w2.set_name("w2");

  std::cout << "w1: " << w1.get_name() << '\n';
  std::cout << "w2: " << w2.get_name() << '\n';

  auto w = make_new_widget(std::move(w1), w2);
  std::cout << "w: " << w.get_name() << '\n';

  return 0;
}