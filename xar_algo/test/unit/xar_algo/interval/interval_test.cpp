#include <gtest/gtest.h>

#include <xar_algo/interval/interval.hpp>


namespace xar_algo
{
    namespace
    {
        class IntervalTest
            : public testing::Test
        {
        public:
            using IntervalType = interval::TInterval<int>;
        };
    
    
        TEST_F(IntervalTest, contains)
        {
            const auto interval = IntervalType{10, 100};
    
            EXPECT_FALSE(interval::contains(interval, 9));
            EXPECT_TRUE(interval::contains(interval, 10));
            EXPECT_TRUE(interval::contains(interval, 100));
            EXPECT_FALSE(interval::contains(interval, 101));
        }
    
        TEST_F(IntervalTest, overlap)
        {
            const auto interval_0 = IntervalType{10, 90};
            const auto interval_1 = IntervalType{0, 100};
            const auto interval_2 = IntervalType{101, 199};
            const auto interval_3 = IntervalType{100, 200};
            const auto interval_4 = IntervalType{200, 300};
    
            EXPECT_TRUE(interval::overlap(interval_1, interval_0));
            EXPECT_TRUE(interval::overlap(interval_0, interval_1));
    
            EXPECT_FALSE(interval::overlap(interval_1, interval_2));
            EXPECT_FALSE(interval::overlap(interval_2, interval_1));
    
            EXPECT_TRUE(interval::overlap(interval_1, interval_3));
            EXPECT_TRUE(interval::overlap(interval_3, interval_1));
    
            EXPECT_TRUE(interval::overlap(interval_3, interval_4));
            EXPECT_TRUE(interval::overlap(interval_4, interval_3));
    
            EXPECT_FALSE(interval::overlap(interval_2, interval_4));
            EXPECT_FALSE(interval::overlap(interval_4, interval_2));
        }
    
        TEST_F(IntervalTest, merge__overlapping_ranges__new_contains_both)
        {
            const auto result = interval::merge(IntervalType{0, 5}, IntervalType{2, 7});
            EXPECT_EQ(result.begin, 0);
            EXPECT_EQ(result.end, 7);
        }

        TEST_F(IntervalTest, merge__non_overlapping_ranges__new_contains_both)
        {
            const auto result = interval::merge(IntervalType{0, 2}, IntervalType{5, 7});
            EXPECT_EQ(result.begin, 0);
            EXPECT_EQ(result.end, 7);
        }
    }
}