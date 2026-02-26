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

TEST(BeanHopper, add_Should_Increase_Beans) {
  double capacity = 200.0;
  BeanHopper bh{capacity};
  auto beans = light_roast();

  auto leftover = bh.add(beans);
  EXPECT_FALSE(leftover.has_value());

  ASSERT_EQ(bh.grams(), beans.grams());
}

TEST(BeanHopper, dispense_Should_Throw_If_Request_Negative) {
  double capacity = 200.0;
  BeanHopper bh{capacity};
  auto beans = light_roast();
  auto leftover = bh.add(beans);
  EXPECT_FALSE(leftover.has_value());

  ASSERT_THROW(bh.dispense(-1), std::runtime_error);
}

TEST(BeanHopper, dispense_Should_Throw_If_Empty) {
  double capacity = 250.0;
  BeanHopper bh{capacity};

  double desired_grams = 20.0;
  ASSERT_THROW(bh.dispense(desired_grams), std::runtime_error);
}
