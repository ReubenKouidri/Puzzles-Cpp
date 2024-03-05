#ifndef CODECHALLENGES_STRING_OPS_HPP
#define CODECHALLENGES_STRING_OPS_HPP

#include <iostream>
#include <string>
#include <ranges>
#include <vector>

namespace rng = std::ranges;

template <class Range>
constexpr void print(const Range& rng) {
  for (const auto& i : rng) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

template <class T>
constexpr void print(const std::vector<T>& v) {
  for (const auto& i : v) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

#ifdef REV_WITH_STACK
std::string reverse_string(const std::string& str) {
  std::string reversed;
  reversed.reserve(str.length());
  std::stack<char> stack;

  for (const char c : str) {
    stack.emplace(c);
  }

  while (!stack.empty()) {
    reversed += stack.top();
    stack.pop();
  }

  return reversed;
}
#endif
#ifdef REV_WITH_RANGES
inline std::string reverse_string(const std::string& str) {
  std::string reversed;
  reversed.reserve(str.length());
  for (const char c : str | std::views::reverse) {
    reversed.push_back(c);
  }
  return reversed;
}

void run() {
  std::cout << "Running reverse_string\n";
  std::string str = "hello";
  auto rts = reverse_string(str);
  std::cout << rts << '\n';
}
#endif

#ifdef FIB_ITER

struct FibIterator {
  using value_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::forward_iterator_tag;

  const value_type& operator*() const { return curr_; }

  FibIterator& operator++() {
    curr_ = std::exchange(next_, curr_ + next_);
    return *this;
  }

  FibIterator operator++(int) {
    FibIterator tmp{*this};
    ++(*this);
    return tmp;
  }

  bool operator==(const FibIterator&) const = default;

private:
  value_type curr_{0};
  value_type next_{1};
};

namespace views
{
  constexpr auto fib = rng::subrange<FibIterator, std::unreachable_sentinel_t>{};
}


[[maybe_unused]] void fib(const std::size_t n, const std::size_t k) {
  auto view = views::fib
              | std::views::filter([k](auto i) { return i % k == 0; })
              | std::views::take(n);
  rng::copy(view, std::ostream_iterator<std::size_t>{std::cout, ", "});
  std::cout << '\n';
}

#endif // FIB_ITER
#ifdef FIB_TRAD
void fib_trad(std::size_t n, std::size_t k) {
  std::size_t found = 0;
  std::size_t curr = 0;
  std::size_t next = 1;

  while (found < n) {
    if (curr % k == 0) {
      ++found;
      std::cout << curr << ", ";
    }
    curr = std::exchange(next, curr + next);
    // curr <- next
    // next <- curr+next
  }
  std::cout << '\n';
}
#endif



#ifdef TRANSFORMS
auto transforms() {
  auto vec = {1, 2, 3, 4, 5};
  print(vec);
  auto view = vec | std::views::transform([](int i) { return i * i; });
  print(view);
}

#endif

void string_ops() {
#ifdef TRANSFORMS
  transforms();
#endif
#ifdef FIB_ITER
  fib(10, 3);
#endif
#ifdef FIB_TRAD
  fib_trad(10, 3);
#endif

}

#endif //CODECHALLENGES_STRING_OPS_HPP
