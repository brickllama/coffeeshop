module; /* Global Module Fragment. */

#include <stdexcept>

export module Liquid; /* Interface Unit. */

export class Liquid {
public:
  explicit Liquid(double volume) {
    if (volume < 0) {
      throw std::runtime_error("LIQUIDS VOLUME CANNOT BE NEGATIVE!");
    }
    this->volume_ = volume;
  }

  virtual ~Liquid() {}

private:
  double volume_;
};

module :private; /* Implementation Unit. */
