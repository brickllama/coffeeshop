module; /* Global Module Fragment. */

export module BeanHopper;  /* Interface Unit. */
export import CoffeeBeans; /* CoffeeBeans; CoffeeGrind; CoffeeRoast */

export class BeanHopper {
public:
  explicit BeanHopper(double capacity) {}

  double capacity() const;

private:
  double capacity_;
};

module :private; /* Implementation Unit. */

double BeanHopper::capacity() const { return this->capacity_; }
