add_library(domain STATIC)

target_sources(domain
    PUBLIC FILE_SET
        CXX_MODULES FILES
            coffee_beans.cppm
)
