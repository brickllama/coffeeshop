export module SteamWand;
export import Steamer;

/**
 * @brief A rod which extends from the espresso machine.
 *
 * @note This class derives from `Steamer`.
 */
export class SteamWand : public Steamer {
public:
  /**
   * @brief Heats the liquid to its desired temperature.
   *
   * @param liquid The liquid.
   * @param target_temperature The desired temperature.
   */
  void steam(Liquid &liquid, double target_temperature) override;
};

module :private;

void SteamWand::steam(Liquid &liquid, double target_temperature) {
  liquid.set_temperature(target_temperature);
}
