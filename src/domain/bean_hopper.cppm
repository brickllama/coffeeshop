module; /* Global Module Fragment. */

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

  double capacity() const;

private:
  double capacity_;
};

module :private; /* Implementation Unit. */

double BeanHopper::capacity() const { return this->capacity_; }
