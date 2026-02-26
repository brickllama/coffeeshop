module; /* Global Module Fragment. */

#include <optional>
#include <stdexcept>

export module BeanHopper;  /* Interface Unit. */
export import CoffeeBeans; /* CoffeeBeans; CoffeeGrind; CoffeeRoast */

export class BeanHopper {
public:
  explicit BeanHopper(double capacity) {
    if (capacity < 0) {
      throw std::runtime_error("BEAN HOPPER CAPACITY CANNOT BE NEGATIVE!");
    }
    this->capacity_ = capacity;
  }

  std::optional<CoffeeBeans> add(const CoffeeBeans &beans);

  double grams() const;

  double capacity() const;

private:
  double capacity_;
  std::optional<CoffeeBeans> beans_;
};

module :private; /* Implementation Unit. */

std::optional<CoffeeBeans> BeanHopper::add(const CoffeeBeans &beans) {
  if (beans.grind() != CoffeeGrind::whole) {
    throw std::runtime_error(
        "BEAN HOPPER DOES NOT ALLOW NON-WHOLE COFFEE BEANS!");
  }
  return std::nullopt;
}

double BeanHopper::grams() const {
  return this->beans_ ? this->beans_->grams() : 0.0;
}

double BeanHopper::capacity() const { return this->capacity_; }
