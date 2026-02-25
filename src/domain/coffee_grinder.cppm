module; /* Global Module Fragment. */

#include <stdexcept>

export module CoffeeGrinder; /* Interface Unit. */
export import CoffeeBeans;

export class CoffeeGrinder {
public:
  explicit CoffeeGrinder(double capacity) {}
  virtual ~CoffeeGrinder() = default;

private:
  double capacity_;
};

module :private; /* Implementation Unit. */
