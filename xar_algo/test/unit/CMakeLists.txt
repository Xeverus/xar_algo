add_executable(xar_algo_test_unit)

target_sources(xar_algo_test_unit
        PRIVATE
            xar_algo/dummy_test.cpp
            xar_algo/interval/interval_test.cpp)

target_link_libraries(xar_algo_test_unit
        PRIVATE
            xar_algo
            GTest::gtest_main)
