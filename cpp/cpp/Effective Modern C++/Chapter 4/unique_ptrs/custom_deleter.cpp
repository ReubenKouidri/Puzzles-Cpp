#include <iostream>
#include <string>
#include <string_view>
#include <map>
#include <cmath>
#include <typeinfo>

class Investment {
  double _start {};
  double _interest {};
public:
  virtual ~Investment() = default;
  Investment() = default;
  Investment(const double start, const double interest)
    : _start(start) , _interest(interest) {}

  [[nodiscard]] auto start() const { return _start; }
  [[nodiscard]] auto interest() const { return _interest; }
  [[nodiscard]] double project(const int years) const {
    return _start * std::pow(_interest, years);
  }
  virtual void print() const {
    printf("Start: %f, Interest: %f\n", _start, _interest);
  }
};

class Stock : public Investment {
public:
  ~Stock() override = default;
  using Investment::Investment;
};

class Bond : public Investment {
public:
  ~Bond() override = default;
  using Investment::Investment;
};

class RealEstate : public Investment {
public:
  ~RealEstate() override = default;
  using Investment::Investment;
};

void make_log_entry(const Investment* inv) {
  static std::map<std::string, size_t> quantity;
  auto clean_type_name = [](const std::string& name) -> std::string {
    size_t i = 0;
    while (i < name.size() && std::isdigit(name[i])) ++i;
    return name.substr(i);
  };

  const auto& name = clean_type_name(typeid(*inv).name());
  if (quantity.find(name) != quantity.end())
    quantity[name]++;
  else quantity[name] = 1;
  printf("Log Entry: %s, Quantity: %zu\n", name.c_str(), quantity[name]);
}

auto delInv = [](Investment* pInv) {
  make_log_entry(pInv);
  delete pInv;
};

template <class InvestmentType, typename... Ts>
std::unique_ptr<Investment, decltype(delInv)> makeInvestment(Ts&&... params) {
  return std::unique_ptr<Investment, decltype(delInv)>(
      new InvestmentType(std::forward<Ts>(params)...), delInv);
}

int main() {
  auto stock = makeInvestment<Stock>(100.0, 1.05);
  auto bond = makeInvestment<Bond>(100.0, 1.03);
  auto realEstate = makeInvestment<RealEstate>(100.0, 1.06);

  // Additional objects for testing log entry updates
  auto anotherStock = makeInvestment<Stock>(150.0, 1.07);
  auto anotherBond = makeInvestment<Bond>(200.0, 1.04);

  return 0;
}
