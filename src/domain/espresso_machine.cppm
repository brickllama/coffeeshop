module; /* Global Module Fragment. */

#include <memory>
#include <utility>

export module EspressoMachine; /* Interface Unit. */
export import BeanHopper;      /* BeanHopper */
export import CoffeeGrinder;   /* CoffeeGrinder */
export import Drinks;          /* Coffee; Drink */
export import Steamer;         /* Steamer */

export constexpr double single_shot = 10.0;
export constexpr double double_shot = 20.0;
export constexpr double espresso_pull_ratio = 3.0;
export constexpr double fresh_espresso_temperature = 94.0;

export class EspressoMachine {
public:
  explicit EspressoMachine(std::unique_ptr<BeanHopper> bean_hopper,
                           std::unique_ptr<CoffeeGrinder> coffee_grinder,
                           std::unique_ptr<Steamer> steamer)
      : bean_hopper_(std::move(bean_hopper)),
        coffee_grinder_(std::move(coffee_grinder)),
        steamer_(std::move(steamer)) {}

  Drink brew(Coffee coffee);
  Liquid extract_espresso();

private:
  Drink americano();
  Drink espresso();
  Drink macchiato();

  std::unique_ptr<BeanHopper> bean_hopper_;
  std::unique_ptr<CoffeeGrinder> coffee_grinder_;
  std::unique_ptr<Steamer> steamer_;
};

module :private; /* Implementation Unit. */

Drink EspressoMachine::brew(Coffee coffee) {
  switch (coffee) {
  case Coffee::americano:
    return americano();
  case Coffee::espresso:
    return espresso();
  case Coffee::macchiato:
    return macchiato();
  [[unlikely]] default:
    std::unreachable();
  }
}

Liquid EspressoMachine::extract_espresso() {
  CoffeeBeans beans = this->bean_hopper_->dispense(single_shot);
  double volume = beans.grams() * espresso_pull_ratio;
  return Liquid{volume, fresh_espresso_temperature};
}

Drink EspressoMachine::americano() {
  Drink drink;

  CoffeeBeans beans = this->bean_hopper_->dispense(single_shot);
  this->coffee_grinder_->grind(beans, CoffeeGrind::fine);
  Liquid espresso_shot = this->extract_espresso();
  drink.add(std::move(espresso_shot));

  Liquid water{120.0, 90.0};
  drink.add(std::move(water));

  return drink;
}

Drink EspressoMachine::espresso() {
  Drink drink;

  CoffeeBeans beans = this->bean_hopper_->dispense(single_shot);
  this->coffee_grinder_->grind(beans, CoffeeGrind::fine);
  Liquid espresso_shot = this->extract_espresso();
  drink.add(std::move(espresso_shot));

  return drink;
}

Drink EspressoMachine::macchiato() {
  Drink drink;

  CoffeeBeans beans = this->bean_hopper_->dispense(single_shot);
  this->coffee_grinder_->grind(beans, CoffeeGrind::fine);
  Liquid espresso = this->extract_espresso();
  drink.add(std::move(espresso));

  Liquid milk{5.0, 4.0};
  this->steamer_->steam(milk, 65.0);
  drink.add(std::move(milk));

  return drink;
}
