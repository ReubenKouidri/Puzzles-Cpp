/*
 * move doesn't move anything, forward doesn't forward anything
 * std::move casts the argument to a rvalue
 * move requests on const objects silently copies them.
 * std::forward is a conditional cast - it casts to rvalue iff the
 * its argument was initialized with an rvalue!
 *
 * "std::move conveys an unconditional cast to an rvalue,
 * while std::forward indicates a cast to an rvalue only for
 * references to which rvalues have been bound" - EMCpp
 *
 * neither std:move nor std::forward do anything at runtime
 */

#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>
#include <chrono>
#include <iomanip>
#include <utility>
#include "../../person.hpp"

using time_pt = std::chrono::system_clock::time_point;

inline void make_log_entry(const std::string& message, const time_pt& time) {
  std::time_t time_t = std::chrono::system_clock::to_time_t(time);
  std::tm now_tm = *std::localtime(&time_t);
  std::cout << "[" << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << "] "
            << message << '\n';
}

namespace demo25 {

template <class T>
[[maybe_unused]] decltype(auto) move(T&& param) {
  using ReturnType = std::remove_reference_t<T>&&;
  return static_cast<ReturnType>(param);
}

[[maybe_unused]] void process(const Person& p) {
  std::cout << "Processing const lvalue " << p << '\n';
}

[[maybe_unused]] void process(Person&& p) {
  std::cout << "Processing rvalue " << p << "\n";
}

template <class T>
[[maybe_unused]] void log_and_process(T&& param) {
  auto now = std::chrono::system_clock::now();
  make_log_entry("Calling 'process'", now);
  process(std::forward<T>(param));
}
} // namespace demo

/* ITEM 25 ==========================================================*/
/* use std::move for rvalue references, std::forward for universal references
 * rvalue references only bind to objects that can be moved, i.e. if you have
 * a rvalue reference, you KNOW it can be moved => use std::move

 * A universal reference may be either r- or lvalue. Therefore, you
 * conditionally cast.
*/

class Widget {
  struct DataStructure;
  std::string name;
  std::shared_ptr<DataStructure> p;
 public:
  /* type deduction => universal ref, not necessarily rvalue ref so use
   * std::forward */
  Widget() = default;
  template <typename T>
  [[maybe_unused]] void set_name(T&& new_name) {
    name = std::forward<T>(new_name);
  }
  /* no deduction => rhs is rvalue reference => use std::move */
  Widget(Widget&& rhs) noexcept
    : name(std::move(rhs.name))
    , p(std::move(rhs.p))
  {}

  [[nodiscard]] std::string get_name() const noexcept { return name; }
};

/* ================================================================ */

/* Functions returning by value...
 * If a func takes a rvalue ref and returns by VALUE, use std::move
 * Similarly, if a func takes a universal ref and returns by VALUE, use forward
*/

inline Widget make_new_widget(Widget&& lhs, const Widget& rhs) {
  lhs.set_name(lhs.get_name() + rhs.get_name());
  return std::move(lhs);
}
