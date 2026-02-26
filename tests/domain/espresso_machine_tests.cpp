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

EspressoMachine basic_espresso_machine(int coffee_grinder_calls,
                                       int steamer_calls) {
  auto bean_hopper = std::make_unique<BeanHopper>(200.0);
  auto beans = sample_beans();
  bean_hopper->add(beans);

  auto coffee_grinder = std::make_unique<MockCoffeeGrinder>();
  EXPECT_CALL(*coffee_grinder, grind(_, _)).Times(coffee_grinder_calls);

  auto steamer = std::make_unique<MockSteamer>();
  EXPECT_CALL(*steamer, steam(_, _)).Times(steamer_calls);

  return EspressoMachine{std::move(bean_hopper), std::move(coffee_grinder),
                         std::move(steamer)};
}

} // namespace

TEST(EspressoMachine, extract_espresso_Should_Return_Espresso_From_Beans) {
  EspressoMachine em = basic_espresso_machine(0, 0);
  auto liquid = em.extract_espresso();

  double expected_volume = 30.0;
  ASSERT_EQ(liquid.volume(), expected_volume);
}

TEST(EspressoMachine, brew_Should_Call_Grinder_And_Steamer) {
  EspressoMachine em = basic_espresso_machine(1, 1);
  auto macchiato = em.brew(Coffee::macchiato);
}
