module; /* Global Module Fragment. */

#include <cstdint>
#include <vector>

export module Drinks; /* Interface Unit. */
export import Liquid;

export enum class Coffee : std::uint8_t { americano, espresso, macchiato };

export class Drink {
public:
  void add(Liquid liquid);
  std::vector<Liquid> liquids_;
};

module :private; /* Implementation Unit. */

void Drink::add(Liquid liquid) { this->liquids_.push_back(liquid); }
