export module ElectricCoffeeGrinder; /* Interface Unit. */
export import CoffeeGrinder;         /* CoffeeGrinder */

/**
 * @brief An electric coffee grinder.
 *
 * @note This class derives from `CoffeeGrinder`.
 */
export class ElectricCoffeeGrinder : public CoffeeGrinder {
public:
  /**
   * @brief Explicit constructor that accepts the supported capacity.
   *
   * @param capacity The supported capacity.
   *
   * @note See base class' constructor.
   */
  explicit ElectricCoffeeGrinder(double capacity) : CoffeeGrinder(capacity) {}

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

void ElectricCoffeeGrinder::grind(CoffeeBeans &beans,
                                  CoffeeGrind target_grind) {
  beans.set_grind(target_grind);
}
