module; /* Global Module Fragment. */

export module SteamWand;
export import Steamer;

export class SteamWand : public Steamer {
public:
  explicit SteamWand() {}
  void steam(Liquid &liquid, double target_temperature) override;
};

module :private;

void SteamWand::steam(Liquid &liquid, double target_temperature) {
  //
}
