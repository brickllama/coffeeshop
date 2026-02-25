add_executable(coffeemakers.tests)

target_sources(coffeemakers.tests
    PRIVATE
        coffee_beans_tests.cpp
)

target_link_libraries(coffeemakers.tests
    PRIVATE
        domain
        GTest::gtest_main
)
