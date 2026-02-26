#include <gtest/gtest.h>
import Drinks;

TEST(Drinks, add_Should_Append_Liquid_To_Vector) {
  Drink drink;

  double volume = 300.0;
  double temperature = 4.0;
  Liquid milk{volume, temperature};
  drink.add(std::move(milk));

  ASSERT_EQ(drink.liquids_.size(), 1);
}
