#include <gtest/gtest.h>
import BeanHopper;

TEST(BeanHopper, BeanHopper_Should_Throw_If_Capacity_Negative) {
  double illegal_capacity = -200.0;
  ASSERT_THROW((BeanHopper{illegal_capacity}), std::runtime_error);
}
