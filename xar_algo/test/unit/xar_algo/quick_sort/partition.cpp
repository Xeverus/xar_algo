#include <gtest/gtest.h>

#include <xar_algo/quick_sort/quick_sort.hpp>

namespace xar_algo
{
    struct QuickSortPartitionTestParams
    {
        std::vector<int> numbers;
        int pivot;
    };

    class QuickSortPartitionTest : public testing::TestWithParam<QuickSortPartitionTestParams> {
    protected:
        using Comparator = std::less<int>;
    };

    TEST_P(QuickSortPartitionTest, all_cases) {
        auto params = GetParam();

        const auto end_iter = quick_sort::partition(
            params.numbers.begin(),
            params.numbers.end(),
            params.pivot);


        const auto predicate = [&params](const auto& value){
            return Comparator{}(value, params.pivot);
        };

        const bool is_partitioned = std::is_partitioned(
            params.numbers.begin(),
            params.numbers.end(),
            predicate
        );

        const auto expected_end_iter = std::partition(
            params.numbers.begin(),
            params.numbers.end(),
            predicate);

        EXPECT_TRUE(is_partitioned);
        EXPECT_EQ(end_iter, expected_end_iter);
    }

    INSTANTIATE_TEST_SUITE_P(
        all_cases_test,
        QuickSortPartitionTest,
        ::testing::Values(
            QuickSortPartitionTestParams{std::vector<int>{}, 0},
            QuickSortPartitionTestParams{std::vector<int>{1}, 0},
            QuickSortPartitionTestParams{std::vector<int>{8, 123, 33, 2, 11, 99}, 12},
            QuickSortPartitionTestParams{std::vector<int>{8, 123, 33, 2, 11, 99, 3, 44, 12, 78, 12, 12, 12, 11}, 15},
            QuickSortPartitionTestParams{std::vector<int>{3, 3, 3, 3, 3}, 6},
            QuickSortPartitionTestParams{std::vector<int>{3, 3, 3, 3, 3}, 1},
            QuickSortPartitionTestParams{std::vector<int>{9, 8, 7, 6, 5, 4, 3, 2, 1}, 3},
            QuickSortPartitionTestParams{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3}
        )
    );
}