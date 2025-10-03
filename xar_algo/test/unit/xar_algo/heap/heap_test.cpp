#include <gtest/gtest.h>

#include <xar_algo/heap/heap.hpp>

namespace xar_algo
{
    struct HeapTestParams
    {
        std::vector<int> data;
    };

    class HeapTest : public testing::TestWithParam<HeapTestParams>
    {
    protected:
        using Heap = heap::Heap<int>;
    };

    TEST_P(HeapTest, heap_sort_all_cases)
    {
        const auto& [data] = GetParam();

        Heap heap(data.begin(), data.end());
        ASSERT_EQ(heap.size(), data.size());

        std::vector<Heap::ValueType> result;
        result.reserve(data.size());

        while (!heap.empty())
        {
            result.push_back(heap.pop());
        }

        ASSERT_EQ(result.size(), data.size());
        EXPECT_TRUE(std::is_sorted(
            result.begin(),
            result.end(),
            Heap::Comparator()));
    }

    INSTANTIATE_TEST_SUITE_P(
        heap_sort,
        HeapTest,
        ::testing::Values(
            HeapTestParams{{}},
            HeapTestParams{{1}},
            HeapTestParams{{1, 3, 6, 2, 4, 7}},
            HeapTestParams{{1, 3, 6, 2, 3, 2, 9, 1, 3}},
            HeapTestParams{{-1, 3, 6, -2, 3, 2, -9, 1, -3}}
        )
    );
}
