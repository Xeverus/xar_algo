#include <gtest/gtest.h>

#include <xar_algo/quick_sort/quick_sort.hpp>

namespace xar_algo
{
    struct QuickSortTestParams
    {
        std::vector<int> numbers;
    };

    class QuickSortTest : public testing::TestWithParam<QuickSortTestParams> {
    protected:
        using Comparator = std::less<int>;

    protected:
        [[nodiscard]]
        static std::vector<int> get_expected();
    };

    std::vector<int> QuickSortTest::get_expected()
    {
        auto numbers = GetParam().numbers;
        std::sort(numbers.begin(), numbers.end(), Comparator{});
        return numbers;
    }

    TEST_P(QuickSortTest, all_cases) {
        auto numbers = GetParam().numbers;
        quick_sort::sort(numbers.begin(), numbers.end(), Comparator{});

        EXPECT_EQ(numbers, get_expected());
    }

    INSTANTIATE_TEST_SUITE_P(
        all_cases_test,
        QuickSortTest,
        ::testing::Values(
            std::vector<int>{},
            std::vector<int>{1},
            std::vector<int>{8, 123, 33, 2, 11, 99},
            std::vector<int>{8, 123, 33, 2, 11, 99, 3, 44, 12, 78, 12, 12, 12, 11},
            std::vector<int>{3, 3, 3, 3, 3},
            std::vector<int>{9, 8, 7, 6, 5, 4, 3, 2, 1},
            std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}
        )
    );
}