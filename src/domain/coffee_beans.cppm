module; /* Global Module Fragment. */

#include <cstdint>
#include <stdexcept>

export module CoffeeBeans; /* Interface Unit. */

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
export constexpr int CoffeeGrind_difference(CoffeeGrind original,
                                            CoffeeGrind target);

export class CoffeeBeans {
public:
  explicit CoffeeBeans(double grams, CoffeeRoast roast,
                       CoffeeGrind grind = CoffeeGrind::whole)
      : roast_(roast), grind_(grind) {
    if (grams < 0) {
      throw std::runtime_error("COFFEE BEAN QUANTITY CANNOT BE NEGATIVE!");
    }
    this->grams_ = grams;
  }

  double grams() const;

  CoffeeRoast roast() const;

  CoffeeGrind grind() const;

private:
  double grams_;
  CoffeeRoast roast_;
  CoffeeGrind grind_;
};

module :private; /* Implementation Unit. */

constexpr int CoffeeGrind_difference(CoffeeGrind original, CoffeeGrind target) {
  return static_cast<int>(target) - static_cast<int>(original);
}

double CoffeeBeans::grams() const { return this->grams_; }

CoffeeRoast CoffeeBeans::roast() const { return this->roast_; }

CoffeeGrind CoffeeBeans::grind() const { return static_cast<CoffeeGrind>(-1); }
