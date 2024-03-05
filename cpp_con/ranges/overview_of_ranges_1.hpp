#ifndef CODECHALLENGES_OVERVIEW_OF_RANGES_1_HPP
#define CODECHALLENGES_OVERVIEW_OF_RANGES_1_HPP

#include <iostream>
#include <ranges>
#include <string>
#include <vector>

namespace iterators { /* A range is a type on which you can call begin() and end()
 * begin() returns an iterator.
 * Ranges build on iterators, not replace them
 *
 * Ranges provide range-based iterators, meaning instead of
 * >>> std::vector<int> vec = {1, 2, 3, 4, 5};
 * >>> std::sort(vec.begin(), vec.end());
 * you can write >>> std::ranges::sort(vec);
 *
 * in stl containers, end() must return an iterator.
 * in the ranges library, end() returns a sentinel.
 * A sentinel marks the end of a range.
 * It is std::equality_comparable_with its corresponding iterator
 * Using a sentinel helps the optimisers generate better code
 * -----------------------------------------------------------*/

template <class It, typename Val>
It find_normally(It first, It last, const Val &val) {
  /* Implementation of std::find
   * Since we are guaranteed to end in '\n' for a std::string, the
   * first != last is ALWAYS true, so we are wasting time checking. */
  while (first != last) {
    if (*first == val)
      break;
    ++first;
  }
  return first;
}

template <class It, typename Val>
It find_with_sentinel(It first,
                      std::unreachable_sentinel_t last,
                      const Val &val) {
  /* Comparison with unreachable_sentinel is always false
   * Therefore first != last => true. The compiler removes the comparison */
  while (first != last) {
    if (*first == val)
      break;
    ++first;
  }
  return first;
}

[[maybe_unused]] void overview_of_ranges_1() {
  const std::string long_str = "this is a string with implicit end character";
  /* std::string guarantees presence of '\n' */
  [[maybe_unused]] auto it = iterators::find_normally(long_str.begin(),
                                                      long_str.end(),
                                                      '\n');
  /* this version is faster as it does not perform the initial comparison */
  [[maybe_unused]] auto it2 = iterators::find_with_sentinel(long_str.begin(),
                                                            std::unreachable_sentinel,
                                                            '\n');
}
}// namespace iterators

namespace sort { /* Projections
 * A unary callable which may be passed to most algorithms
 * They modify the view of the data that the algorithm sees
 *
 * f1 shows one way to make sure that the payslips line up with the employees
 * f2: shows how to achieve this using ranges
 */

struct Employee {
  std::string name;
  std::size_t id;
};

struct Payslip {
  std::size_t amount;
  std::size_t e_id;
};

std::vector<Employee> employees;
std::vector<Payslip> payslips;

[[maybe_unused]] void f1() {
  std::sort(employees.begin(), employees.end(),
            [](const Employee &e1, const Employee &e2) {
              return e1.id < e2.id;
            });

  std::sort(payslips.begin(), payslips.end(),
            [](const Payslip &p1, const Payslip &p2) {
              return p1.e_id < p2.e_id;
            });

  [[maybe_unused]] auto is_equal = std::equal(
    employees.begin(), employees.end(),
    payslips.begin(), payslips.end(),
    [](const Employee &e, const Payslip &p) {
      return e.id == p.e_id;
    });
}

[[maybe_unused]] void f2() {
  //    without a projection, we would need to do this:
  std::ranges::sort(employees, [](const Employee &e1, const Employee &e2) {
    return e1.id < e2.id;
  });
  //    with a projection, where ranges::less{} is a comparator, the lambda
  //    is the projection: (Employee) e -> (int) e.id
  //    This version of sort operates on (sees) int, not Employee
  std::ranges::sort(employees, std::ranges::less{}, [](const Employee &e) {
    return e.id;
  });
  //    Projections are passed through an implementation of std::invoke.
  //    std::invoke treats pointers to members as callables.
  //    This allows us to replace these lambdas with pointers to member data
  std::ranges::sort(employees, std::ranges::less{}, &Employee::id);
  //    Finally, the default comparator is std::ranges::less{}, so we don't
  //    need to specify anything. Same goes for equal. Therefore...

  std::ranges::sort(employees, {}, &Employee::id);
  std::ranges::sort(payslips, {}, &Payslip::e_id);
  [[maybe_unused]] auto eq = std::ranges::equal(employees, payslips, {},
                                                &Employee::id,
                                                &Payslip::e_id);
}
}// namespace sort

namespace view_demo { /* stl algorithms are great, but they don't compose well
 * they perform their operations eagerly.
 * ranges::views are range adaptors. They allow lazy evaluation.
 * Lazy: delays the evaluation of an op until it is needed. Can work with
 * infinite streams of data.
 * Eager: operation is executed as soon as it is encountered.
 *
 * In the 2nd two functions, the filters and transforms are executed on the
 * fly - when they are called by ranges::copy.
 */
[[maybe_unused]] void print_squares(const std::vector<int> &vec) {
  std::ranges::transform(vec, std::ostream_iterator<int>{std::cout, " "},
                         [](int i) { return i * i; });
}

[[maybe_unused]] void print_even_squares(const std::vector<int> &vec) {
  auto square = [](auto i) { return i * i; };
  auto is_even = [](auto i) { return i % 2 == 0; };
  auto view = std::ranges::views::transform(
    std::ranges::views::filter(vec, is_even),
    square);
  std::ranges::copy(view, std::ostream_iterator<int>{std::cout, " "});
}

[[maybe_unused]] void print_even_squares_pipe(const std::vector<int> &vec) {
  /* Pipe operator is composition of functions */
  auto square = [](auto i) { return i * i; };
  auto is_even = [](auto i) { return i % 2 == 0; };
  auto view =
    vec
    | std::ranges::views::filter(is_even)
    | std::ranges::views::transform(square);
  std::ranges::copy(view, std::ostream_iterator<int>{std::cout, " "});
}
}// namespace view_demo

#endif//CODECHALLENGES_OVERVIEW_OF_RANGES_1_HPP
