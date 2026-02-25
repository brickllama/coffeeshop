#include <gtest/gtest.h>
import CoffeeBeans;

TEST(CoffeeBeans,
     CoffeeGrind_difference_Should_Be_Positive_From_Coarse_To_Fine) {
  CoffeeGrind original = CoffeeGrind::coarse;
  CoffeeGrind target = CoffeeGrind::fine;
  ASSERT_EQ(CoffeeGrind_difference(original, target), 4);
}

TEST(CoffeeBeans,
     CoffeeGrind_difference_Should_Be_Negative_From_Fine_To_Coarse) {
  CoffeeGrind original = CoffeeGrind::fine;
  CoffeeGrind target = CoffeeGrind::coarse;
  ASSERT_EQ(CoffeeGrind_difference(original, target), -4);
}

TEST(CoffeeBeans, CoffeeBeans_Should_Not_Allow_Negative_Weight) {
  double illegal_grams = -1;
  ASSERT_THROW(
      CoffeeBeans(illegal_grams, CoffeeRoast::light, CoffeeGrind::whole),
      std::runtime_error);
}

CoffeeBeans coarse_beans() {
  return CoffeeBeans{15.0, CoffeeRoast::light, CoffeeGrind::coarse};
}

CoffeeBeans fine_beans() {
  return CoffeeBeans{15.0, CoffeeRoast::light, CoffeeGrind::fine};
}

TEST(CoffeeBeans, grams_Should_Return_Correct_Value) {
  auto beans = coarse_beans();
  double expected_weight = 15.0;
  ASSERT_EQ(beans.grams(), expected_weight);
}

TEST(CoffeeBeans, roast_Should_Return_Correct_Value) {
  auto beans = coarse_beans();
  CoffeeRoast expected_roast = CoffeeRoast::light;
  ASSERT_EQ(beans.roast(), expected_roast);
}

TEST(CoffeeBeans, grind_Should_Return_Correct_Value) {
  auto beans = coarse_beans();
  CoffeeGrind expected_grind = CoffeeGrind::coarse;
  ASSERT_EQ(beans.grind(), expected_grind);
}
