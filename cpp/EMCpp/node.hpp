#ifndef CODECHALLENGES_CPP_EMCPP_NODE_HPP_
#define CODECHALLENGES_CPP_EMCPP_NODE_HPP_

#include <iostream>
#include <string>

class Node {
  int val_{};
  std::string name_{};
  static inline size_t count_{};
 public:
  ~Node();
  Node() noexcept = default;
  explicit Node(const int v, std::string&& name)
      : val_(v), name_(std::forward<std::string>(name)) {}

  Node(const Node& rhs) = default;

  Node(Node&& rhs) noexcept
      : val_(rhs.val_), name_(std::move(rhs.name_)) {}

  Node &operator=(const Node& rhs) {
    val_ = rhs.val_;
    name_ = rhs.name_;
    std::cout << "copy assignment\n";
    return *this;
  }

  Node &operator=(Node&& rhs) noexcept {
    val_ = rhs.val_;
    name_ = std::move(rhs.name_);
    std::cout << "move assignment\n";
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const Node& node);
  friend Node operator+(Node&& lhs, const Node& rhs);

  Node& operator+=(const Node& rhs) {
    printf("lval operator+=\n");
    val_ += rhs.val_;
    return *this;
  }

  Node& operator+=(Node&& rhs) {
    printf("rval operator+=\n");
    val_ += rhs.val_;
    return *this;
  }

  [[maybe_unused]]
  [[nodiscard]] constexpr auto val() const noexcept {
    return val_;
  }

  [[maybe_unused]]
  [[nodiscard]] auto name() const noexcept {
    return name_;
  }
};

Node operator+(Node&& lhs, const Node& rhs) {
  printf("friend operator+\n");
  lhs += rhs;
  return std::move(lhs);
}

Node::~Node() {
  std::cout << "Destructor " << ++count_ << "\n";
}

std::ostream& operator<<(std::ostream& os, const Node& node) {
  os << "Node(" << node.val_ << ", " << node.name_ << ")\n";
  return os;
}

#endif //CODECHALLENGES_CPP_EMCPP_NODE_HPP_
