#include <gtest/gtest.h>
import ElectricCoffeeGrinder;

namespace {
double electric_grinder_capacity = 80.0;

CoffeeBeans coarse_beans() {
  return CoffeeBeans{15.0, CoffeeRoast::light, CoffeeGrind::coarse};
}

CoffeeBeans fine_beans() {
  return CoffeeBeans{15.0, CoffeeRoast::light, CoffeeGrind::fine};
}
} // namespace

TEST(ElectricCoffeeGrinder, grind_Should_Change_CoffeeBean_Grind) {
  auto beans = coarse_beans();
  auto target_grind = CoffeeGrind::extreme_fine;

  ElectricCoffeeGrinder ecg{electric_grinder_capacity};
  ecg.grind(beans, target_grind);
  ASSERT_EQ(beans.grind(), target_grind);
}
