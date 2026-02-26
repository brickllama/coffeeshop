module; /* Global Module Fragment. */

#include <memory>

export module EspressoMachine; /* Interface Unit. */
export import BeanHopper;      /* BeanHopper */
export import CoffeeGrinder;   /* CoffeeGrinder */
export import Steamer;         /* Steamer */

export class EspressoMachine {
public:
  explicit EspressoMachine(std::unique_ptr<BeanHopper> bean_hopper,
                           std::unique_ptr<CoffeeGrinder> coffee_grinder,
                           std::unique_ptr<Steamer> steamer)
      : bean_hopper_(std::move(bean_hopper)),
        coffee_grinder_(std::move(coffee_grinder)),
        steamer_(std::move(steamer)) {}

  Liquid brew();

private:
  std::unique_ptr<BeanHopper> bean_hopper_;
  std::unique_ptr<CoffeeGrinder> coffee_grinder_;
  std::unique_ptr<Steamer> steamer_;
};

module :private; /* Implementation Unit. */

Liquid EspressoMachine::brew() { return Liquid{300.0, 4.0}; }
