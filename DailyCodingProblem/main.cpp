#include "dcp2.hpp"

int main() {
  std::vector<int> ov = {1, 2, 3, 4, 5};
  std::vector<double> ov2 {1.0, 2.0, 3.0, 4.0, 5.0};
  auto vec = part1(ov);
  auto vec2 = part2(ov);
  auto vec3 = part2(ov2);
  print(vec);
  print(vec2);
  return 0;
}