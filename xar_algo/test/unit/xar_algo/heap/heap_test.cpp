#include <gtest/gtest.h>

#include <xar_algo/heap/heap.hpp>

namespace xar_algo
{
    struct HeapTestParams
    {
    };

    class HeapTest : public testing::TestWithParam<HeapTestParams> {
    protected:
        using Comparator = std::less<int>;
    };

    TEST_P(HeapTest, all_cases) {
        auto params = GetParam();
    }

    INSTANTIATE_TEST_SUITE_P(
        all_cases_test,
        HeapTest,
        ::testing::Values(
            HeapTestParams{}
        )
    );
}