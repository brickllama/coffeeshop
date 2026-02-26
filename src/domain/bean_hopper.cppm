module; /* Global Module Fragment. */

#include <limits>
#include <optional>
#include <stdexcept>

export module BeanHopper;  /* Interface Unit. */
export import CoffeeBeans; /* CoffeeBeans; CoffeeGrind; CoffeeRoast */

/**
 * @brief A bean hopper.
 */
export class BeanHopper {
public:
  /**
   * @brief Explicit constructor that accepts the supported capacity.
   *
   * @param capacity The supported capacity.
   *
   * @throw std::runtime_error if `capacity` is negative.
   */
  explicit BeanHopper(double capacity) {
    if (capacity < 0) {
      throw std::runtime_error("BEAN HOPPER CAPACITY CANNOT BE NEGATIVE!");
    }
    this->capacity_ = capacity;
  }

  /**
   * @brief Adds `CoffeeBeans` to the bean hopper.
   *
   * @param beans The coffee beans.
   * @return `CoffeeBeans` IF LEFTOVERS PERSIST.
   */
  std::optional<CoffeeBeans> add(const CoffeeBeans &beans);

  CoffeeBeans dispense(double grams);

  /**
   * @brief Returns the current amount of beans in grams.
   * @return Grams as a double.
   */
  double grams() const;

  /**
   * @brief Returns the supported capacity.
   * @return Capacity as a double.
   */
  double capacity() const;

private:
  /**
   * @brief Returns the roast of the greater `CoffeeBean` quantity.
   *
   * @param a The former set of beans.
   * @param b The latter set of beans.
   * @return `CoffeeRoast` as the most-common roast.
   */
  CoffeeRoast common_roast(const CoffeeBeans &a, const CoffeeBeans &b);

  /**
   * @brief Sets the beans used by the bean hopper.
   *
   * @param grams The weight in grams.
   * @param roast The type of roast.
   */
  void set_beans(double grams, CoffeeRoast roast);

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
  CoffeeRoast roast;
  if (this->beans_.has_value()) {
    current_grams = this->beans_->grams();
    roast = common_roast(this->beans_.value(), beans);
  } else {
    current_grams = 0.0;
    roast = beans.roast();
  }
  double total_grams = current_grams + beans.grams();

  if (total_grams > this->capacity()) {
    double leftover_grams = total_grams - this->capacity();
    this->set_beans(this->capacity(), roast);

    return CoffeeBeans{leftover_grams, beans.roast(), CoffeeGrind::whole};
  }

  this->set_beans(total_grams, roast);

  return std::nullopt;
}

CoffeeBeans BeanHopper::dispense(double grams) {
  return CoffeeBeans{0.00, this->beans_->roast(), this->beans_->grind()};
}

double BeanHopper::grams() const {
  return this->beans_.has_value() ? this->beans_->grams() : 0.0;
}

double BeanHopper::capacity() const { return this->capacity_; }

CoffeeRoast BeanHopper::common_roast(const CoffeeBeans &a,
                                     const CoffeeBeans &b) {
  return (a.roast() >= b.roast()) ? a.roast() : b.roast();
}

void BeanHopper::set_beans(double grams, CoffeeRoast roast) {
  this->beans_ = CoffeeBeans{grams, roast, CoffeeGrind::whole};
}
