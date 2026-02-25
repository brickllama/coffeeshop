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
   *
   * @throws std::runtime_error If `volume` value is negative.
   */
  explicit Liquid(double volume) {
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
   * @brief Default destructor.
   */
  virtual ~Liquid() {}

private:
  double volume_;
};

module :private; /* Implementation Unit. */

double Liquid::volume() const { return this->volume_; }
