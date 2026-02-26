#include <gtest/gtest.h>
import SteamWand;

namespace {

class Milk : public Liquid {
public:
  explicit Milk(double volume, double temperature)
      : Liquid(volume, temperature) {}
};

} // namespace

TEST(SteamWand, steam_Should_Increase_Liquid_Temperature) {
  SteamWand sw;
  Milk m{250.0, 4.0};
  double boiling = 100.0;

  sw.steam(m, boiling);
  ASSERT_EQ(m.temperature(), boiling);
}
