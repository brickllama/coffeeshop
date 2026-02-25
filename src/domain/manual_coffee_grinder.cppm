module; /* Global Module Fragment. */

#include <chrono>
#include <cmath>
#include <print>
#include <thread>

export module ManualCoffeeGrinder; /* Interface Unit. */
export import CoffeeGrinder;

export class ManualCoffeeGrinder : public CoffeeGrinder {
public:
  explicit ManualCoffeeGrinder(double capacity) : CoffeeGrinder(capacity) {}
  void grind(CoffeeBeans &beans, CoffeeGrind target_grind) override;
};

module :private; /* Implementation Unit. */

void ManualCoffeeGrinder::grind(CoffeeBeans &beans, CoffeeGrind target_grind) {
  ///
}
