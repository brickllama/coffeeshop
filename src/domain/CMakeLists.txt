add_library(domain STATIC)

target_sources(domain
    PUBLIC FILE_SET
        CXX_MODULES FILES
            bean_hopper.cppm
            coffee_beans.cppm
            coffee_grinder.cppm
            electric_coffee_grinder.cppm
            electric_steamer.cppm
            espresso_machine.cppm
            liquid.cppm
            manual_coffee_grinder.cppm
            steamer.cppm
            steam_wand.cppm
)
