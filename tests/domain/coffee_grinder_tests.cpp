#include <gtest/gtest.h>
import CoffeeGrinder;

class StubCoffeeGrinder : public CoffeeGrinder {
public:
  explicit StubCoffeeGrinder(double capacity) : CoffeeGrinder(capacity) {}
};

TEST(CoffeeGrinder, CoffeeGrinder_Should_Throw_If_Capacity_Negative) {
  double illegal_capacity = -15.0;
  EXPECT_THROW((StubCoffeeGrinder{illegal_capacity}), std::runtime_error);
}
