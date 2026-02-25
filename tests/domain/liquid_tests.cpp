#include <gtest/gtest.h>
import Liquid;

TEST(Liquid, Liquid_Should_Throw_If_Volume_Negative) {
  double illegal_volume = -1.0;
  ASSERT_THROW((Liquid{illegal_volume}), std::runtime_error);
}
