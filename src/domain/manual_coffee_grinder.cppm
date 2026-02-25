export module ManualCoffeeGrinder; /* Interface Unit. */
export import CoffeeGrinder;       /* CoffeeGrinder */

/**
 * @brief A manual (typically hand-held) coffee grinder.
 *
 * @note This class derives from `CoffeeGrinder`.
 */
export class ManualCoffeeGrinder : public CoffeeGrinder {
public:
  /**
   * @brief Explicit constructor that accepts the supported capacity.
   *
   * @param capacity The supported capacity.
   *
   * @note See base class' constructor.
   */
  explicit ManualCoffeeGrinder(double capacity) : CoffeeGrinder(capacity) {}

  /**
   * @brief Grinds the beans to their desired grind.
   *
   * @param beans The coffee beans.
   * @param target_grind The desired grind.
   *
   * @note This will hold unique logic in the future.
   */
  void grind(CoffeeBeans &beans, CoffeeGrind target_grind) override;
};

module :private; /* Implementation Unit. */

void ManualCoffeeGrinder::grind(CoffeeBeans &beans, CoffeeGrind target_grind) {
  beans.set_grind(target_grind);
}
