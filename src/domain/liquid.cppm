module;

#include <limits>

export module Liquid; /* Interface Unit. */
import std;

/**
 * @brief Any sort of liquid.
 */
export class Liquid {
public:
  /**
   * @brief Explicit constructor that accepts volume.
   *
   * @param volume The volume of the liquid.
   * @param temperature The temperature of the liquid.
   *
   * @throws std::runtime_error If `volume` value is negative.
   */
  explicit Liquid(double volume, double temperature) {
    if (volume < 0) {
      throw std::runtime_error("LIQUIDS VOLUME CANNOT BE NEGATIVE!");
    }
    this->volume_ = volume;
  }

  /**
   * @brief Returns the current volume.
   * @return Volume as a double.
   */
  double volume() const;

  /**
   * @brief Returns the current temperature.
   * @return Temperature as a double.
   */
  double temperature() const;

  /**
   * @brief Default destructor.
   */
  virtual ~Liquid() {}

private:
  double volume_;
};

module :private; /* Implementation Unit. */

double Liquid::volume() const { return this->volume_; }

double Liquid::temperature() const { return std::numeric_limits<int>::min(); }
