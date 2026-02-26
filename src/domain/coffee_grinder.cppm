export module CoffeeGrinder; /* Interface Unit. */
export import CoffeeBeans;   /* CoffeeBeans; CoffeeGrind */
import std;                  /* <stdexcept> */

/**
 * @brief A coffee grinder.
 *
 * @note This is an abstract class (or base class).
 */
export class CoffeeGrinder {
public:
  /**
   * @brief Explicit constructor that accepts the supported capacity.
   *
   * @param capacity The supported capacity.
   *
   * @throws std::runtime_error if `capacity` is negative.
   */
  explicit CoffeeGrinder(double capacity) {
    if (capacity < 0) {
      throw std::runtime_error("COFFEE GRINDER CAPACITY CANNOT BE NEGATIVE!");
    }
    this->capacity_ = capacity;
  }

  /**
   * @brief Returns the supported capacity.
   *
   * @return Capacity as a double.
   */
  double capacity() const;

  /**
   * @brief Grinds the beans to their desired grind.
   *
   * @param beans The coffee beans.
   * @param target_grind The desired grind.
   */
  virtual void grind(CoffeeBeans &beans, CoffeeGrind target_grind) = 0;

  /**
   * @brief Default destructor.
   */
  virtual ~CoffeeGrinder() {}

private:
  double capacity_;
};

module :private; /* Implementation Unit. */

double CoffeeGrinder::capacity() const { return this->capacity_; }
