#include <gtest/gtest.h>
import CoffeeGrinder;

class StubCoffeeGrinder : public CoffeeGrinder {
public:
  explicit StubCoffeeGrinder(double capacity) : CoffeeGrinder(capacity) {}
};

TEST(CoffeeGrinder, CoffeeGrinder_Should_Throw_If_Capacity_Negative) {
  double illegal_capacity = -15.0;
  ASSERT_THROW((StubCoffeeGrinder{illegal_capacity}), std::runtime_error);
}

TEST(CoffeeGrinder, capacity_Should_Return_Correct_Value) {
  double expected_capacity = 20.0;
  StubCoffeeGrinder scg{expected_capacity};
  ASSERT_EQ(scg.capacity(), expected_capacity);
}
