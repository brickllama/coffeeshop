export module Drinks; /* Interface Unit. */
export import Liquid; /* Liquid */
import std.compat;    /* <cstdint>; <string_view>; utility>; <vector> */

/**
 * @brief Basic coffees.
 */
export enum class Coffee : std::uint8_t {
  americano, /* ~30ml espresso, ~120ml water. */
  espresso,  /* ~30ml espresso. */
  macchiato  /* ~30ml espresso, ~5ml milk. */
};

export constexpr std::string_view Coffee_as_string(Coffee coffee) {
  switch (coffee) {
  case Coffee::americano:
    return "Americano";
  case Coffee::espresso:
    return "Espresso";
  case Coffee::macchiato:
    return "Macchiato";
  [[unlikely]] default:
    std::unreachable();
  }
}

/**
 * @brief A basic drink.
 */
export class Drink {
public:
  /**
   * @brief Adds `Liquid` to the drink.
   *
   * @param Liquid The liquid.
   */
  void add(Liquid liquid);

  /**
   * @brief Returns the list of liquids in the drink.
   *
   * @return The liquids as a vector.
   */
  std::vector<Liquid> liquids() const;

  /**
   * @brief Returns the total volume of the drink.
   *
   * @return The volume as a double.
   */
  double volume() const;

private:
  std::vector<Liquid> liquids_;
};

module :private; /* Implementation Unit. */

void Drink::add(Liquid liquid) { this->liquids_.push_back(liquid); }

std::vector<Liquid> Drink::liquids() const { return this->liquids_; }

double Drink::volume() const {
  double volume = 0;
  for (const auto &l : this->liquids_) {
    volume += l.volume();
  }
  return volume;
}