import EspressoMachine;
import ElectricCoffeeGrinder;
import SteamWand;
import std.compat;

constexpr double hopper_capacity = 200.0;
constexpr double nonexistent_capacity = 0.0;

constexpr std::string_view selection_prompt = R"(
Choose a coffee:
1: Americano
2: Espresso
3: Macchiato
0: Exit
)";

void main_menu(EspressoMachine &espresso_machine) {
  while (true) {
    std::println("{}", selection_prompt);
    int choice;
    std::cin >> choice;

    if (choice == 0) {
      std::println("Exiting");
      break;
    }

    if (choice < 1 || choice > 3) {
      std::println("Invalid selection.");
      continue;
    }

    Coffee coffee = static_cast<Coffee>(choice - 1);
    Drink beverage = espresso_machine.brew(coffee);
    std::println("Enjoy your {}!", Coffee_as_string(coffee));
    break;
  }
}

int main() {
  CoffeeBeans beans{250.0, CoffeeRoast::dark, CoffeeGrind::whole};
  auto hopper = std::make_unique<BeanHopper>(hopper_capacity);
  hopper->add(beans);

  auto internal_grinder =
      std::make_unique<ElectricCoffeeGrinder>(nonexistent_capacity);

  auto steam_wand = std::make_unique<SteamWand>();

  EspressoMachine espresso_machine{
      std::move(hopper), std::move(internal_grinder), std::move(steam_wand)};

  main_menu(espresso_machine);

  return 0;
}
