#include <gtest/gtest.h>

#include <xar_algo/union_find/union_find.hpp>


namespace xar_algo
{
    namespace
    {
        using UnionFind = union_find::UnionFind<int>;
        using UnionFindSet = std::set<std::pair<UnionFind::ValueType, UnionFind::ValueType>>;

        class UnionFindTest
            : public testing::Test
        {
        protected:
            static UnionFindSet to_set(const UnionFind& state);
        };

        UnionFindSet UnionFindTest::to_set(const UnionFind& state)
        {
            UnionFindSet entries;
            for (const auto& entry : state.forest)
            {
                entries.insert(entry);
            }
            return entries;
        }


        TEST_F(UnionFindTest, find_topmost_value__empty_state__return_the_same_value)
        {
            UnionFind state;
            EXPECT_EQ(union_find::find_topmost_value(state, 0), 0);
            EXPECT_EQ(union_find::find_topmost_value(state, 10), 10);
        }

        TEST_F(UnionFindTest, find_topmost_value__state_with_data__return_correct_value)
        {
            UnionFind state;
            state.forest.insert(std::make_pair(0, 1));
            state.forest.insert(std::make_pair(2, 3));

            EXPECT_EQ(union_find::find_topmost_value(state, 0), 1);
            EXPECT_EQ(union_find::find_topmost_value(state, 1), 1);

            EXPECT_EQ(union_find::find_topmost_value(state, 2), 3);
            EXPECT_EQ(union_find::find_topmost_value(state, 3), 3);
        }

        TEST_F(UnionFindTest, find_topmost_value__state_with_complex_data__return_correct_value)
        {
            UnionFind state;
            state.forest.insert(std::make_pair(10, 0));
            state.forest.insert(std::make_pair(0, 1));
            state.forest.insert(std::make_pair(1, 4));
            state.forest.insert(std::make_pair(2, 4));
            state.forest.insert(std::make_pair(3, 10));

            EXPECT_EQ(union_find::find_topmost_value(state, 10), 4);
            EXPECT_EQ(union_find::find_topmost_value(state, 1), 4);
            EXPECT_EQ(union_find::find_topmost_value(state, 2), 4);
            EXPECT_EQ(union_find::find_topmost_value(state, 3), 4);
        }

        TEST_F(UnionFindTest, are_connected__empty_data__return_false)
        {
            UnionFind state;
            EXPECT_FALSE(union_find::are_connected(state, 0, 1));
        }

        TEST_F(UnionFindTest, are_connected__2_non_connected_trees__return_false)
        {
            UnionFind state;
            state.forest.insert(std::make_pair(0, 1));
            state.forest.insert(std::make_pair(2, 3));

            EXPECT_TRUE(union_find::are_connected(state, 0, 1));
            EXPECT_TRUE(union_find::are_connected(state, 1, 0));

            EXPECT_FALSE(union_find::are_connected(state, 0, 2));
            EXPECT_FALSE(union_find::are_connected(state, 2, 0));

            EXPECT_TRUE(union_find::are_connected(state, 2, 3));
            EXPECT_TRUE(union_find::are_connected(state, 3, 2));

            EXPECT_FALSE(union_find::are_connected(state, 3, 1));
            EXPECT_FALSE(union_find::are_connected(state, 1, 3));
        }

        TEST_F(UnionFindTest, connect__single_pair__result_ok)
        {
            UnionFind state;
            union_find::connect(state, 1, 2);

            EXPECT_EQ(to_set(state), (UnionFindSet{{1, 2}}));
        }

        TEST_F(UnionFindTest, connect__three_unrelated_pairs__result_ok)
        {
            UnionFind state;
            union_find::connect(state, 1, 2);
            union_find::connect(state, 3, 4);
            union_find::connect(state, 5, 6);

            EXPECT_EQ(to_set(state), (UnionFindSet{{1, 2}, {3, 4}, {5, 6}}));
        }

        TEST_F(UnionFindTest, connect__two_unrelated_trees__result_ok)
        {
            UnionFind state;
            union_find::connect(state, 1, 10);
            union_find::connect(state, 2, 10);
            union_find::connect(state, 3, 10);

            union_find::connect(state, 11, 20);
            union_find::connect(state, 12, 20);
            union_find::connect(state, 13, 20);

            EXPECT_EQ(to_set(state), (UnionFindSet{
                {1, 10}, {2, 10}, {3, 10},
                {11, 20}, {12, 20}, {13, 20},
            }));
        }

        TEST_F(UnionFindTest, connect__build_bigger_tree__result_ok)
        {
            UnionFind state;
            union_find::connect(state, 10, 100);
            union_find::connect(state, 20, 100);
            union_find::connect(state, 30, 100);

            union_find::connect(state, 1, 10);
            union_find::connect(state, 2, 10);

            union_find::connect(state, 3, 20);
            union_find::connect(state, 4, 20);

            union_find::connect(state, 5, 30);
            union_find::connect(state, 6, 30);

            EXPECT_EQ(to_set(state), (UnionFindSet{
                {10, 100}, {20, 100}, {30, 100},
                {1, 100}, {2, 100}, {3, 100}, {4, 100}, {5, 100}, {6, 100},
            }));
        }

        TEST_F(UnionFindTest, connect__two_trees__result_ok)
        {
            UnionFind state;
            union_find::connect(state, 10, 100);
            union_find::connect(state, 20, 100);
            union_find::connect(state, 30, 100);

            union_find::connect(state, 40, 200);
            union_find::connect(state, 50, 200);
            union_find::connect(state, 60, 200);

            EXPECT_EQ(to_set(state), (UnionFindSet{
                {10, 100}, {20, 100}, {30, 100},
                {40, 200}, {50, 200}, {60, 200},
            }));

            union_find::connect(state, 100, 200);

            EXPECT_EQ(to_set(state), (UnionFindSet{
                {10, 100}, {20, 100}, {30, 100},
                {40, 200}, {50, 200}, {60, 200},
                {100, 200},
            }));
        }

        TEST_F(UnionFindTest, connect__smaller_with_bigger__smaller_is_child_of_bigger)
        {
            UnionFind state;
            union_find::connect(state, 10, 100);
            union_find::connect(state, 20, 100);
            union_find::connect(state, 30, 100);
            union_find::connect(state, 40, 100);

            union_find::connect(state, 50, 200);
            union_find::connect(state, 60, 200);

            EXPECT_EQ(to_set(state), (UnionFindSet{
                {10, 100}, {20, 100}, {30, 100}, {40, 100},
                {50, 200}, {60, 200},
            }));

            union_find::connect(state, 100, 200);

            EXPECT_EQ(to_set(state), (UnionFindSet{
                {10, 100}, {20, 100}, {30, 100}, {40, 100},
                {50, 200}, {60, 200},
                {200, 100},
            }));
        }
    }
}