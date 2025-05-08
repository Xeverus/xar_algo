#pragma once

#include <optional>
#include <unordered_map>


namespace xar_algo::union_find
{
    template <typename T>
    struct UnionFind
    {
    public:
        using ValueType = T;
        using ChildToParentMap = std::unordered_map<ValueType, ValueType>;
        using TreeSizeMap = std::unordered_map<ValueType, std::size_t>;

    public:
        ChildToParentMap forest;
        TreeSizeMap tree_size;
    };


    template <typename T>
    typename UnionFind<T>::ValueType find_topmost_value(
        const UnionFind<T>& state,
        const typename UnionFind<T>::ValueType& value)
    {
        auto topmost_value = value;

        for (auto topmost_node = state.forest.find(topmost_value); topmost_node != state.forest.end(); topmost_node = state.forest.find(topmost_value))
        {
            topmost_value = topmost_node->second;
        }

        return topmost_value;
    }


    template <typename T>
    bool are_connected(
        const UnionFind<T>& state,
        const typename UnionFind<T>::ValueType& value_1,
        const typename UnionFind<T>::ValueType& value_2)
    {
        return find_topmost_value(state, value_1) == find_topmost_value(state, value_2);
    }


    template <typename T>
    void connect(
        UnionFind<T>& state,
        const typename UnionFind<T>::ValueType& value_1,
        const typename UnionFind<T>::ValueType& value_2)
    {
        auto value_1_topmost = find_topmost_value(state, value_1);
        auto value_2_topmost = find_topmost_value(state, value_2);
        if (find_topmost_value(state, value_1) == find_topmost_value(state, value_2))
        {
            return;
        }

        const auto value_1_topmost_size_iter = state.tree_size.find(value_1_topmost);
        const auto value_1_topmost_size = value_1_topmost_size_iter == state.tree_size.end() ? 1z : value_1_topmost_size_iter->second;

        const auto value_2_topmost_size_iter = state.tree_size.find(value_2_topmost);
        const auto value_2_topmost_size = value_2_topmost_size_iter == state.tree_size.end() ? 1z : value_2_topmost_size_iter->second;

        const auto merged_trees_size = value_2_topmost_size + value_1_topmost_size;
        if (value_1_topmost_size <= value_2_topmost_size)
        {
            state.tree_size[value_2_topmost] = merged_trees_size;
            state.forest.insert(std::make_pair(value_1, std::move(value_2_topmost)));
        }
        else
        {
            state.tree_size[value_1_topmost_size] = merged_trees_size;
            state.forest.insert(std::make_pair(value_2, std::move(value_1_topmost)));
        }
    }
}