module; /* Global Module Fragment. */

export module ElectricSteamer; /* Interface Unit. */
export import Steamer;         /* Steamer */

export class ElectricSteamer : public Steamer {
public:
  void steam(Liquid &liquid, double target_temperature) override;
};

module :private; /* Implementation Unit. */

void ElectricSteamer::steam(Liquid &liquid, double target_temperature) {
  liquid.set_temperature(target_temperature);
}
