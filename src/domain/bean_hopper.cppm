module; /* Global Module Fragment. */

#include <limits>
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

  double current_grams;
  CoffeeRoast most_common_roast;
  if (this->beans_.has_value()) {
    current_grams = this->beans_->grams();
    most_common_roast = (this->beans_->grams() >= beans.grams())
                            ? this->beans_->roast()
                            : beans.roast();
  } else {
    current_grams = 0.0;
    most_common_roast = beans.roast();
  }
  double total_grams = current_grams + beans.grams();

  if (total_grams > this->capacity()) {
    return CoffeeBeans{std::numeric_limits<int>::max(), beans.roast(),
                       CoffeeGrind::whole};
  }

  return std::nullopt;
}

double BeanHopper::grams() const {
  return this->beans_ ? this->beans_->grams() : 0.0;
}

double BeanHopper::capacity() const { return this->capacity_; }
