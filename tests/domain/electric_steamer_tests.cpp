#include <gtest/gtest.h>
import ElectricSteamer;

namespace {

class Milk : public Liquid {
public:
  explicit Milk(double volume, double temperature)
      : Liquid(volume, temperature) {}
};

} // namespace

TEST(ElectricSteamer, steam_Should_Increase_Liquid_Temperature) {
  ElectricSteamer es;
  Milk m{250.0, 4.0};
  double boiling = 100.0;

  es.steam(m, boiling);
  ASSERT_EQ(m.temperature(), boiling);
}
