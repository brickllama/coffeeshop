import EspressoMachine;
import ElectricCoffeeGrinder;
import SteamWand;
import std.compat;

constexpr double hopper_capacity = 200.0;
constexpr double nonexistent_capacity = 0.0;

constexpr std::string_view coffee_selection_prompt = R"(
Choose a coffee:
1: Americano
2: Espresso
3: Macchiato
0: Exit
)";

constexpr std::string_view roast_selection_prompt = R"(
  Choose roast
  1: Light,
  2: Medium,
  3: Dark
  0: Exit
)";

void refill_menu(EspressoMachine &espresso_machine) {
  std::println("Enter grams of beans to add: ");
  double grams;
  std::cin >> grams;

  std::println("{}", roast_selection_prompt);
  int choice;
  std::cin >> choice;

  CoffeeRoast roast = static_cast<CoffeeRoast>(choice - 1);
  CoffeeBeans new_beans{grams, roast, CoffeeGrind::whole};

  try {
    espresso_machine.refill_hopper(new_beans);
    std::println("HOPPER REFILLED!");
  } catch (std::runtime_error &e) {
    std::println("Error: {}", e.what());
  }
}

void main_menu(EspressoMachine &espresso_machine) {
  while (true) {
    std::println("{}", coffee_selection_prompt);
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
    try
    {
      Drink beverage = espresso_machine.brew(coffee);
      std::println("Enjoy your {}!", Coffee_as_string(coffee));
    } catch(std::runtime_error& e) {
      if (std::string(e.what()) == "BEAN HOPPER NEEDS TO BE REFILLED!") {
        refill_menu(espresso_machine);
      } else {
        std::println("Error: {}", e.what());
      }
    }
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
