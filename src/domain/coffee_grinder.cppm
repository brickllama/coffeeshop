module; /* Global Module Fragment. */

export module CoffeeGrinder; /* Interface Unit. */
export import CoffeeBeans;

export class CoffeeGrinder {
public:
  explicit CoffeeGrinder(double capacity) {
    //
  }
  virtual ~CoffeeGrinder() {}

private:
  double capacity_;
};

module :private; /* Implementation Unit. */
