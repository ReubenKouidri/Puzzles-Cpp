#ifndef CODECHALLENGES_QUEUE_OPS_HPP
#define CODECHALLENGES_QUEUE_OPS_HPP

#include <iostream>
#include <queue>
#include <optional>

struct Order {
  int id{};
  int value{};
  constexpr explicit Order(int order_id, int order_value) noexcept
    : id(order_id), value(order_value) {}
};

class MerchOrderSystem {
private:
  std::queue<Order> standard_orders_;
  std::queue<Order> priority_orders_;
public:
  void place_order(Order&& o, const bool is_priority) {
    if (is_priority) {
      priority_orders_.emplace(o);
    } else {
      standard_orders_.emplace(o);
    }
  }

  [[nodiscard]] constexpr std::optional<Order> fulfill_order() {
    if (!priority_orders_.empty()) {
      auto order = priority_orders_.front();
      priority_orders_.pop();
      return std::optional<Order>{order};
    } else if (!standard_orders_.empty()) {
      auto order = standard_orders_.front();
      standard_orders_.pop();
      return std::optional<Order>{order};
    } else return {};
  }
};

void queue_ops() {
  MerchOrderSystem system;
  system.place_order(Order(1, 10), false);
  system.place_order(Order(2, 20), false);
  system.place_order(Order(3, 30), true);

  while (auto fulfilled_order = system.fulfill_order()) {
    std::cout << "Order: " << fulfilled_order->id << " "
              << fulfilled_order->value << '\n';
  }
}

#endif //CODECHALLENGES_QUEUE_OPS_HPP
