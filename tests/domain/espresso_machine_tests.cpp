#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
import EspressoMachine;
import BeanHopper;
import MockCoffeeGrinder;
import MockSteamer;

using ::testing::_;

namespace {

CoffeeBeans sample_beans() {
  return CoffeeBeans{200.0, CoffeeRoast::dark, CoffeeGrind::whole};
}

} // namespace

TEST(EspressoMachine, brew_Should_Call_Grinder_And_Steamer) {
  auto bean_hopper = std::make_unique<BeanHopper>(200.0);
  auto beans = sample_beans();
  bean_hopper->add(beans);

  auto coffee_grinder = std::make_unique<MockCoffeeGrinder>();
  EXPECT_CALL(*coffee_grinder, grind(_, _)).Times(1);

  auto steamer = std::make_unique<MockSteamer>();
  EXPECT_CALL(*steamer, steam(_, _)).Times(1);

  EspressoMachine em{std::move(bean_hopper), std::move(coffee_grinder),
                     std::move(steamer)};
  Liquid milk = em.brew();
}
