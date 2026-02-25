add_subdirectory(domain)

add_executable(coffeeshop2)

target_sources(coffeeshop2
    PRIVATE
        main.cpp
)

target_link_libraries(coffeeshop2
    PRIVATE
        domain
)
