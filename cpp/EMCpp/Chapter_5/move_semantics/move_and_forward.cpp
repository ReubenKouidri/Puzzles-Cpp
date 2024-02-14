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
#include "../../person.hpp"

using time_pt = std::chrono::system_clock::time_point;

inline void make_log_entry(const std::string &message, const time_pt &time) {
  std::time_t time_t = std::chrono::system_clock::to_time_t(time);
  std::tm now_tm = *std::localtime(&time_t);
  std::cout << "[" << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << "] "
            << message << '\n';
}


namespace demo {

template <class T>
decltype(auto) move(T &&param) {
  using ReturnType = std::remove_reference_t<T> &&;
  return static_cast<ReturnType>(param);
}

[[maybe_unused]] void process(const Person& p) {
  std::cout << "Processing const lvalue " << p << '\n';
}

[[maybe_unused]] void process(Person&& p) {
  std::cout << "Processing rvalue " << p << "\n";
}

template <class T>
void log_and_process(T &&param) {
  auto now = std::chrono::system_clock::now();
  make_log_entry("Calling 'process'", now);
  process(std::forward<T>(param));
}

} // namespace demo

int main() {
  auto p = Person();
  demo::log_and_process(p);

  auto p2 = Person();
  demo::log_and_process(std::move(p2));
  return 0;
}