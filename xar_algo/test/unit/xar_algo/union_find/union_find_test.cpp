#include <gtest/gtest.h>

#include <xar_algo/union_find/union_find.hpp>


namespace xar_algo
{
    namespace
    {
        using UnionFind = union_find::UnionFind<int>;

        class UnionFindTest
            : public testing::Test
        {
        };


        TEST_F(UnionFindTest, are_connected__empty_data__return_false)
        {
            UnionFind data;
            EXPECT_FALSE(union_find::are_connected(data, 0, 1));
        }

        TEST_F(UnionFindTest, are_connected__2_non_connected_trees__return_false)
        {
            UnionFind data;
            data.data.insert(std::make_pair(0, 1));
            data.data.insert(std::make_pair(2, 3));

            EXPECT_TRUE(union_find::are_connected(data, 0, 1));
            EXPECT_TRUE(union_find::are_connected(data, 1, 0));

            EXPECT_FALSE(union_find::are_connected(data, 0, 2));
            EXPECT_FALSE(union_find::are_connected(data, 2, 0));

            EXPECT_TRUE(union_find::are_connected(data, 2, 3));
            EXPECT_TRUE(union_find::are_connected(data, 3, 2));

            EXPECT_FALSE(union_find::are_connected(data, 3, 1));
            EXPECT_FALSE(union_find::are_connected(data, 1, 3));
        }
    }
}