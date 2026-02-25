module; /* Global Module Fragment. */

#include <cstdint>

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

module :private; /* Implementation Unit. */

constexpr int CoffeeGrind_difference(CoffeeGrind original, CoffeeGrind target) {
  return static_cast<int>(target) - static_cast<int>(original);
}
