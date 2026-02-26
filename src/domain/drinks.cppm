module; /* Global Module Fragment. */

#include <cstdint>
#include <vector>

export module Drinks; /* Interface Unit. */
export import Liquid;

export enum class Coffee : std::uint8_t { americano, espresso, macchiato };

export class Drink {
public:
  void add(Liquid liquid);

  std::vector<Liquid> liquids() const;

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