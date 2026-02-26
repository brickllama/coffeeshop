add_executable(domain.tests)

target_sources(domain.tests
    PUBLIC FILE_SET
        CXX_MODULES FILES
            mock_steamer.cppm
            mock_coffee_grinder.cppm
    PRIVATE
        bean_hopper_tests.cpp
        coffee_beans_tests.cpp
        coffee_grinder_tests.cpp
        drinks_tests.cpp
        electric_coffee_grinder_tests.cpp
        electric_steamer_tests.cpp
        espresso_machine_tests.cpp
        liquid_tests.cpp
        manual_coffee_grinder_tests.cpp
        steam_wand_tests.cpp
)

target_link_libraries(domain.tests
    PRIVATE
        domain
        GTest::gtest_main
        gmock
)

if(ENABLE_CODE_COVERAGE)
    target_compile_options(domain PRIVATE ${COVERAGE_COMPILE_FLAGS})
    target_link_options(domain.tests PRIVATE ${COVERAGE_LINK_FLAGS})
endif()
