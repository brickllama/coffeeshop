#include <gtest/gtest.h>
import ManualCoffeeGrinder;

TEST(ManualCoffeeGrinder,
     ManualCoffeeGrinder_Should_Throw_If_Capacity_Is_Negative) {
  double illegal_capacity = -1.0;
  ASSERT_THROW((ManualCoffeeGrinder{illegal_capacity}), std::runtime_error);
}
