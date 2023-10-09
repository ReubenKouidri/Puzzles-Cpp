#include <iostream>
#include "reverse_ll/reverse_singly_linked_list.hpp"


int main() {
  constexpr int data_1 = 1;
  constexpr int data_2 = 2;
  auto node_1 = Node<int>(data_1);
  auto node_2 = Node<int>(data_2, &node_1);
  auto ll = LinkedList<int>(&node_2);

  std::cout << ll << '\n';



  return 0;
}
