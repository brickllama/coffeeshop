module;

export module ElectricCoffeeGrinder;
export import CoffeeGrinder;

export class ElectricCoffeeGrinder : public CoffeeGrinder {
public:
  explicit ElectricCoffeeGrinder(double capacity) : CoffeeGrinder(capacity) {}

  void grind(CoffeeBeans &beans, CoffeeGrind target_grind) override;
};

module :private;

void ElectricCoffeeGrinder::grind(CoffeeBeans &beans,
                                  CoffeeGrind target_grind) {
  //
}
