module; /* Global Module Fragment. */

#include <stdexcept>

export module CoffeeGrinder; /* Interface Unit. */
export import CoffeeBeans;

export class CoffeeGrinder {
public:
  explicit CoffeeGrinder(double capacity) {
    if (capacity < 0) {
      throw std::runtime_error("COFFEE GRINDER CAPACITY CANNOT BE NEGATIVE!");
    }
    this->capacity_ = capacity;
  }

  double capacity() const;

  virtual ~CoffeeGrinder() {}

private:
  double capacity_;
};

module :private; /* Implementation Unit. */

double CoffeeGrinder::capacity() const { return -1.0; }
