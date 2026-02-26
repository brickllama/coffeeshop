#include <gtest/gtest.h>
import Drinks;

TEST(Drinks, add_Should_Append_Liquid_To_Vector) {
  Drink drink;

  double volume = 300.0;
  double temperature = 4.0;
  Liquid milk{volume, temperature};
  drink.add(std::move(milk));

  ASSERT_EQ(drink.liquids().size(), 1);
}

TEST(Drinks, volume_Should_Return_Total_Volume) {
  Drink drink;

  double milk_volume = 120.0;
  double milk_temperature = 4.0;
  Liquid milk{milk_volume, milk_temperature};
  drink.add(std::move(milk));

  double espresso_volume = 30.0;
  double espresso_temperature = 90.0;
  Liquid espresso{espresso_volume, espresso_temperature};
  drink.add(std::move(espresso));

  double total_volume = milk_volume + espresso_volume;
  ASSERT_EQ(drink.volume(), total_volume);
}
