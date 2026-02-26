export module ElectricSteamer; /* Interface Unit. */
export import Steamer;         /* Steamer */

/**
 * @brief An electric steamer.
 *
 * @note This class derives from `Steamer`.
 */
export class ElectricSteamer : public Steamer {
public:
  /**
   * @brief Heats the liquid to its desired temperature.
   *
   * @param liquid The liquid.
   * @param target_temperature The desired temperature.
   */
  void steam(Liquid &liquid, double target_temperature) override;
};

module :private; /* Implementation Unit. */

void ElectricSteamer::steam(Liquid &liquid, double target_temperature) {
  liquid.set_temperature(target_temperature);
}
