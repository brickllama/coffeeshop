module; /* Global Module Fragment. */

export module ManualCoffeeGrinder; /* Interface Unit. */
export import CoffeeGrinder;

export constexpr double STANDARD_PUCK_SIZE =
    20.0; /* An average espresso puck is 20 grams. */

export class ManualCoffeeGrinder : public CoffeeGrinder {
public:
  explicit ManualCoffeeGrinder(double capacity = STANDARD_PUCK_SIZE)
      : CoffeeGrinder(capacity) {}
};

module :private; /* Implementation Unit. */
