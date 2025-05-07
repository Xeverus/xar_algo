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


        TEST_F(UnionFindTest, find_topmost_node__empty_state__return_the_same_value)
        {
            UnionFind state;
            EXPECT_EQ(union_find::find_topmost_node(state, 0), 0);
            EXPECT_EQ(union_find::find_topmost_node(state, 10), 10);
        }

        TEST_F(UnionFindTest, find_topmost_node__state_with_data__return_correct_value)
        {
            UnionFind state;
            state.data.insert(std::make_pair(0, 1));
            state.data.insert(std::make_pair(2, 3));

            EXPECT_EQ(union_find::find_topmost_node(state, 0), 1);
            EXPECT_EQ(union_find::find_topmost_node(state, 1), 1);

            EXPECT_EQ(union_find::find_topmost_node(state, 2), 3);
            EXPECT_EQ(union_find::find_topmost_node(state, 3), 3);
        }

        TEST_F(UnionFindTest, find_topmost_node__state_with_complex_data__return_correct_value)
        {
            UnionFind state;
            state.data.insert(std::make_pair(10, 0));
            state.data.insert(std::make_pair(0, 1));
            state.data.insert(std::make_pair(1, 4));
            state.data.insert(std::make_pair(2, 4));
            state.data.insert(std::make_pair(3, 10));

            EXPECT_EQ(union_find::find_topmost_node(state, 10), 4);
            EXPECT_EQ(union_find::find_topmost_node(state, 1), 4);
            EXPECT_EQ(union_find::find_topmost_node(state, 2), 4);
            EXPECT_EQ(union_find::find_topmost_node(state, 3), 4);
        }

        TEST_F(UnionFindTest, are_connected__empty_data__return_false)
        {
            UnionFind state;
            EXPECT_FALSE(union_find::are_connected(state, 0, 1));
        }

        TEST_F(UnionFindTest, are_connected__2_non_connected_trees__return_false)
        {
            UnionFind state;
            state.data.insert(std::make_pair(0, 1));
            state.data.insert(std::make_pair(2, 3));

            EXPECT_TRUE(union_find::are_connected(state, 0, 1));
            EXPECT_TRUE(union_find::are_connected(state, 1, 0));

            EXPECT_FALSE(union_find::are_connected(state, 0, 2));
            EXPECT_FALSE(union_find::are_connected(state, 2, 0));

            EXPECT_TRUE(union_find::are_connected(state, 2, 3));
            EXPECT_TRUE(union_find::are_connected(state, 3, 2));

            EXPECT_FALSE(union_find::are_connected(state, 3, 1));
            EXPECT_FALSE(union_find::are_connected(state, 1, 3));
        }
    }
}