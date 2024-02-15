#include <vector>
#include <utility>
#include "../../person.hpp"

/* If a function template parameter has type T&& for a deduced type T,
 * or if an object is declared using auto&&, the parameter or object is
 * a universal reference.

 * If the form of the type declaration isn’t precisely type&&, or if type
 * deduction does not occur, type&& denotes an rvalue reference.

  * Universal references correspond to rvalue references if they’re
  * initialized with rvalues.
  * They correspond to lvalue references if they’re initialized with lvalues.
*/


/* If the type is being deduced, it is NOT rvalue reference
 * If the type is explicit then it IS rvalue reference */

// [[maybe_unused]] void f(Person&& p);  // rvalue reference

template <typename T>
[[maybe_unused]] void fv(std::vector<T>&& v);  // rvalue reference

template <typename T>
[[maybe_unused]] void f([[maybe_unused]] T&& t) {}  // universal reference!

[[maybe_unused]] inline int var1;
[[maybe_unused]] inline auto&& var2 = var1; // universal reference!


void run() {
  [[maybe_unused]] Person&& p1 = Person();  // rvalue reference
  /* Universal references must be initialized
  * The initializer determines whether it is rvalue or lvalue reference
  * c.f. the following example: */
  Person p;
  f(p);  // p passed as lvalue reference => T&& is lvalue reference
  f(std::move(p));  // p passed as rvalue reference => T&& is rvalue reference

  std::vector<int> v;
  /* fv(v): this generates an error since v is lvalue ref but the type
   * std::vector<T>&& has std::vector defined, so it is rvalue not universal */
  fv(std::move(v));  // unconditional-cast to rvalue
}
