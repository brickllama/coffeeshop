module; /* Global Module Fragment. */

#include <memory>

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

  Liquid extract_espresso();

private:
  std::unique_ptr<BeanHopper> bean_hopper_;
  std::unique_ptr<CoffeeGrinder> coffee_grinder_;
  std::unique_ptr<Steamer> steamer_;
};

module :private; /* Implementation Unit. */

Liquid EspressoMachine::extract_espresso() {
  CoffeeBeans beans = this->bean_hopper_->dispense(single_shot);
  double volume = beans.grams() * espresso_pull_ratio;
  return Liquid{volume, fresh_espresso_temperature};
}
