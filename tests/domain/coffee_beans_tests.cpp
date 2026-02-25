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

TEST(CoffeeBeans, grams_Should_Not_Allow_Negative_Value) {
  ASSERT_THROW(CoffeeBeans(-1, CoffeeRoast::light, CoffeeGrind::whole),
               std::runtime_error);
}
