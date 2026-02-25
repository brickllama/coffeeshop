export module CoffeeBeans; /* Interface Unit. */
import std.compat;         /* <cstdint>; <stdexcept> */

/**
 * @brief Different kinds of coffee roasts.
 */
export enum class CoffeeRoast : std::uint8_t {
  light,  /* Light brown color; mellow flavor; best suited for pour over. */
  medium, /* Medium brown color; balanced flavor; best suited for pour over and
             drip coffee. */
  dark    /* Black color; smoky, intense flavor; best suited for espresso. */
};

/**
 * @brief Different kinds of coffee grinds.
 */
export enum class CoffeeGrind : std::uint8_t {
  whole,          /* Completely unaltered beans. */
  extreme_coarse, /* 1.3 - 1.5mm */
  coarse,         /* 1mm */
  medium_coarse,  /* 0.7 - 0.85mm */
  medium,         /* 0.6 - 0.65mm */
  medium_fine,    /* 0.45 - 0.55mm */
  fine,           /* 0.2 - 0.35mm */
  extreme_fine    /* 0.1mm */
};

/**
 * @brief Quick comparison between different CoffeeGrind stages.
 *
 * @param orignal The original grind.
 * @param target The target grind.
 * @return An integer.
 */
export int CoffeeGrind_difference(CoffeeGrind original, CoffeeGrind target);

/**
 * @brief Coffee Beans.
 */
export class CoffeeBeans {
public:
  /**
   * @brief Explicit constructor that accepts weight, roast, and grind
   * (optional).
   *
   * @param grams The weight of the coffee beans in grams.
   * @param roast The roast of the coffee beans.
   * @param grind The grind size. Defaults to whole beans.
   *
   * @throws std::runtime_error If `grams` value is negative.
   */
  explicit CoffeeBeans(double grams, CoffeeRoast roast,
                       CoffeeGrind grind = CoffeeGrind::whole)
      : roast_(roast), grind_(grind) {
    if (grams < 0) {
      throw std::runtime_error("COFFEE BEAN QUANTITY CANNOT BE NEGATIVE!");
    }
    this->grams_ = grams;
  }

  /**
   * @brief Returns the weight of the coffee bean portion.
   * @return Weight in grams.
   */
  double grams() const;

  /**
   * @brief Returns the roast of the coffee beans.
   * @return CoffeeRoast enum.
   */
  CoffeeRoast roast() const;

  /**
   * @brief Returns the grind of the coffee beans.
   * @return CoffeeGrind enum.
   */
  CoffeeGrind grind() const;

  /**
   * @brief Sets the grind size of the coffee bean portion.
   *
   * @param grind The new grind size. Must be equal to or finer than the current
   * grind.
   * @throws std::runtime_error if attempting to 'un-grind' the beans.
   */
  void set_grind(CoffeeGrind target);

private:
  double grams_;
  CoffeeRoast roast_;
  CoffeeGrind grind_;
};

module :private; /* Implementation Unit. */

int CoffeeGrind_difference(CoffeeGrind original, CoffeeGrind target) {
  return static_cast<int>(target) - static_cast<int>(original);
}

double CoffeeBeans::grams() const { return this->grams_; }

CoffeeRoast CoffeeBeans::roast() const { return this->roast_; }

CoffeeGrind CoffeeBeans::grind() const { return this->grind_; }

void CoffeeBeans::set_grind(CoffeeGrind target) {
  if (CoffeeGrind_difference(this->grind_, target) < 0) {
    throw std::runtime_error("COFFEE BEANS CANNOT BE UNGROUND!");
  }
  this->grind_ = target;
}
