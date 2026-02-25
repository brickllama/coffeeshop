#include <gtest/gtest.h>
import ManualCoffeeGrinder;

namespace {
double standard_puck_size = 20.0;

CoffeeBeans coarse_beans() {
  return CoffeeBeans{15.0, CoffeeRoast::light, CoffeeGrind::coarse};
}

// CoffeeBeans fine_beans() {
//   return CoffeeBeans{15.0, CoffeeRoast::light, CoffeeGrind::fine};
// }
} // namespace

TEST(ManualCoffeeGrinder, grind_Should_Change_CoffeeBean_Grind) {
  auto beans = coarse_beans();
  auto target_grind = CoffeeGrind::fine;

  ManualCoffeeGrinder mcg{standard_puck_size};
  mcg.grind(beans, target_grind);
  ASSERT_EQ(beans.grind(), target_grind);
}
