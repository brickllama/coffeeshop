#include <gtest/gtest.h>
import BeanHopper;

TEST(BeanHopper, BeanHopper_Should_Throw_If_Capacity_Negative) {
  double big_hopper_capacity = 200.0;
  BeanHopper bh{big_hopper_capacity};
  ASSERT_EQ(bh.capacity(), big_hopper_capacity);
}
