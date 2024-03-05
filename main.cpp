#include <iostream>
#include "fib.hpp"

int main() {
  constexpr size_t n = 10;
  size_t value = fib<n>(n);
  std::cout << value << '\n';
  return 0;
}
