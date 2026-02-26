module; /* Global Module Fragment. */

export module Steamer; /* Interface Unit. */
export import Liquid;  /* Liquid */

/**
 * @brief A steamer (intended for milk).
 *
 * @note This is an abstract class (or base class).
 */
export class Steamer {
public:
  /**
   * @brief Heats the liquid to its desired temperature.
   *
   * @param liquid The liquid.
   * @param target_temperature The desired temperature.
   */
  virtual void steam(Liquid &liquid, double target_temperature) = 0;

  /**
   * @brief Default destructor.
   */
  virtual ~Steamer() = default;
};

module :private; /* Implementation Unit. */
