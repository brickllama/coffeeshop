module; /* Global Module Fragment. */

#include <stdexcept>

export module Liquid; /* Interface Unit. */

export class Liquid {
public:
  explicit Liquid(double volume) {}
  virtual ~Liquid() {}
};

module :private; /* Implementation Unit. */
