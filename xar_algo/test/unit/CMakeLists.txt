add_executable(xar_algo_test_unit)

target_sources(xar_algo_test_unit
        PRIVATE
            xar_algo/dummy_test.cpp
            xar_algo/interval/interval_container_test.cpp
            xar_algo/interval/interval_test.cpp
            xar_algo/partition/partition_test.cpp
            xar_algo/quick_sort/quick_sort_test.cpp
            xar_algo/union_find/union_find_test.cpp)

target_link_libraries(xar_algo_test_unit
        PRIVATE
            xar_algo
            GTest::gtest_main)
