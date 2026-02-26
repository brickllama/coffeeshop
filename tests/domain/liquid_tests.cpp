#include <gtest/gtest.h>
import Liquid;

namespace {

class StubLiquid : public Liquid {
public:
  explicit StubLiquid(double volume, double temperature)
      : Liquid(volume, temperature) {}
};

constexpr double fridge_temp = 4.0;

} // namespace

TEST(Liquid, Liquid_Should_Throw_If_Volume_Negative) {
  double illegal_volume = -1.0;
  ASSERT_THROW((StubLiquid{illegal_volume, fridge_temp}), std::runtime_error);
}

TEST(Liquid, volume_Should_Return_Correct_Value) {
  double expected_volume = 400.0;
  StubLiquid sl{expected_volume, fridge_temp};
  ASSERT_EQ(sl.volume(), expected_volume);
}

TEST(Liquid, temperature_Should_Return_Correct_Value) {
  double expected_volume = 250.0;
  double expected_temperature = -3.0;
  StubLiquid sl{expected_volume, expected_temperature};
  ASSERT_EQ(sl.temperature(), expected_temperature);
}

TEST(Liquid, set_temperature_Should_Change_Temperature) {
  double expected_volume = 333.0;
  StubLiquid sl{expected_volume, fridge_temp};
  double desired_temperature = 100.0;
  sl.set_temperature(desired_temperature);
  ASSERT_EQ(sl.temperature(), desired_temperature);
}
