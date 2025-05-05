add_executable(algo_test_unit)

target_sources(algo_test_unit
        PRIVATE
            algo/dummy_test.cpp)

target_link_libraries(algo_test_unit
        PRIVATE
            algo
            GTest::gtest_main)
