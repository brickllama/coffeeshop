#include <gtest/gtest.h>
#include <print>
import BeanHopper;

namespace {

CoffeeBeans light_roast() {
  return CoffeeBeans{15.0, CoffeeRoast::light, CoffeeGrind::whole};
}

CoffeeBeans big_bag() {
  return CoffeeBeans{250.0, CoffeeRoast::dark, CoffeeGrind::whole};
}

} // namespace

TEST(BeanHopper, BeanHopper_Should_Throw_If_Capacity_Negative) {
  double illegal_capacity = -200.0;
  ASSERT_THROW((BeanHopper{illegal_capacity}), std::runtime_error);
}

TEST(BeanHopper, add_Should_Throw_If_CoffeeGrind_Is_Not_Whole) {
  double capacity = 200.0;
  BeanHopper bh{capacity};
  auto beans = light_roast();
  beans.set_grind(CoffeeGrind::coarse);
  ASSERT_THROW(bh.add(beans), std::runtime_error);
}

TEST(BeanHopper, add_Should_Return_Beans_If_Surplus_Amount) {
  double capacity = 200.0;
  BeanHopper bh{capacity};
  auto beans = big_bag();
  double expected_remainder = beans.grams() - capacity;

  auto leftover = bh.add(beans);
  ASSERT_EQ(leftover->grams(), expected_remainder);
}
