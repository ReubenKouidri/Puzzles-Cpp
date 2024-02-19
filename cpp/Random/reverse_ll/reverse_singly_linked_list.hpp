
#ifndef REVERSE_SINGLY_LINKED_LIST_HPP
#define REVERSE_SINGLY_LINKED_LIST_HPP


#include <iostream>

template<typename T> class Node {
private:
  T data;
  Node<T>* next_node;

public:
  explicit Node(T new_data, Node<T>* next_node = nullptr);


  // Copy constructor
  Node(const Node<T>& other);

  // Copy assignment
  Node<T>& operator=(const Node<T>& other) {
    std::cout << "\nInside copy assignment\n";
    if (this != &other) {
      data = other.data;
      next_node = other.next_node;
    }
    return *this;
  }

  // Move constructor
  Node(Node<T>&& other) noexcept;

  // Move assignment
  Node<T>& operator=(Node<T>&& other) noexcept {
    std::cout << "\nInside move assignment\n";
    if (this != &other) {
      data = other.data;
      next_node = other.next_node;
      other.next_node = nullptr;
    }
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& out, const Node<T>& n);

  auto set_next_node(Node<T>* new_next_node) { this->next_node = new_next_node; }

  [[nodiscard]] auto get_next_node() const { return next_node; }

  [[nodiscard]] auto get_data() const { return data; }
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Node<T>& n) {
  out << n.data << ' ' << &n;
  return out;
}

template<typename T>
Node<T>::Node(const T new_data, Node* next_node) : data(new_data), next_node(next_node) {}

// copy constructor
template<typename T>
Node<T>::Node(const Node<T>& other) : data(other.data), next_node(other.next_node) {}

// Move constructor
template<typename T>
Node<T>::Node(Node&& other) noexcept : data(other.data), next_node(other.next_node) {
  std::cout << "\nInside move constructor\n";
  other.next_node = nullptr;
}



template<typename T>
class LinkedList {
private:
  Node<T>* head;
public:
  explicit LinkedList(Node<T>* head = nullptr) : head(head) {}

  explicit LinkedList(T data) { head = new Node<T>(data); }

  ~LinkedList();

  [[maybe_unused]] [[nodiscard]]
  auto get_head() const { return head; }

  [[maybe_unused]] [[nodiscard]]
  auto get_next_node() const { return head->next_node; }

  [[maybe_unused]] void insert_at_head(T data);

  void insert_at_head(Node<T>* new_node);

  friend std::ostream& operator<<(std::ostream& out, const LinkedList<T>& ll);

  void reverse();
};


template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& ll) {
  auto current_node = ll.get_head();
  while (current_node) {
    out << '(' << &current_node << ", " << current_node->get_data() << ")\n";
    current_node = current_node->get_next_node();
  }
  out << '\n';
  return out;
}

template<typename T>
LinkedList<T>::~LinkedList() {
  auto current_node = head;
  while (current_node) {
    std::cout << "deleting node at " << current_node << " with data " << current_node->get_data() << '\n';
    auto next_node = current_node->get_next_node();
    delete current_node;
    current_node = next_node;
  }
}

template<typename T>
[[maybe_unused]]
void LinkedList<T>::insert_at_head(T data) {
  auto new_node = new Node<T>(data);
  new_node -> set_next_node(head);
  head = new_node;
}

template<typename T>
void LinkedList<T>::insert_at_head(Node<T>* new_node) {
  new_node->set_next_node(head);
  head = new_node;
}


template<typename T>
void LinkedList<T>::reverse() {
  Node<T>* prev = nullptr;
  Node<T>* current = head;
  Node<T>* next = nullptr;

  while (current != nullptr) {
    next = current->next; // Save the next node
    current->next = prev; // Reverse the link

    // Move pointers one position ahead
    prev = current;
    current = next;
  }

  head = prev; // Update the head of the linked list
}


#endif //REVERSE_SINGLY_LINKED_LIST_HPP
