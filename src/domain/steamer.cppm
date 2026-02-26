module; /* Global Module Fragment. */

export module Steamer; /* Interface Unit. */
export import Liquid;  /* Liquid */

export class Steamer {
public:
  virtual void steam(Liquid &liquid, double target_temperature) = 0;
  virtual ~Steamer() = default;
};

module :private; /* Implementation Unit. */
