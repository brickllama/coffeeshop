add_executable(domain.tests)

target_sources(domain.tests
    PRIVATE
        coffee_beans_tests.cpp
        coffee_grinder_tests.cpp
        electric_coffee_grinder_tests.cpp
        liquid_tests.cpp
        manual_coffee_grinder_tests.cpp
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
