#include <gtest/gtest.h>
import Liquid;

class StubLiquid : public Liquid {
public:
  explicit StubLiquid(double volume) : Liquid(volume) {}
};

TEST(Liquid, Liquid_Should_Throw_If_Volume_Negative) {
  double illegal_volume = -1.0;
  ASSERT_THROW((Liquid{illegal_volume}), std::runtime_error);
}

TEST(Liquid, volume_Should_Return_Correct_Value) {
  double expected_volume = 400;
  StubLiquid sl{expected_volume};
  ASSERT_EQ(sl.volume(), expected_volume);
}
