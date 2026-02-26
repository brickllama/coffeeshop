add_library(domain STATIC)

target_sources(domain
    PUBLIC FILE_SET
        CXX_MODULES FILES
            coffee_beans.cppm
            coffee_grinder.cppm
            electric_coffee_grinder.cppm
            liquid.cppm
            manual_coffee_grinder.cppm
            steamer.cppm
            steam_wand.cppm
)
