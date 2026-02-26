module; /* Global Module Fragment. */

#include <gmock/gmock.h>

export module MockCoffeeGrinder; /* Implementation Unit. */
import CoffeeGrinder;

export class MockCoffeeGrinder : public CoffeeGrinder {
public:
  explicit MockCoffeeGrinder() : CoffeeGrinder(200.0) {}
  MOCK_METHOD(void, grind, (CoffeeBeans & beans, CoffeeGrind target_grind),
              (override));
};
