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

    public:
        ChildToParentMap hierarchy;
    };


    template <typename T>
    typename UnionFind<T>::ValueType find_topmost_node(
        const UnionFind<T>& state,
        const typename UnionFind<T>::ValueType& value)
    {
        auto topmost_value = value;

        for (auto topmost_node = state.hierarchy.find(topmost_value); topmost_node != state.hierarchy.end(); topmost_node = state.hierarchy.find(topmost_value))
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
        return find_topmost_node(state, value_1) == find_topmost_node(state, value_2);
    }


    template <typename T>
    void connect(
        UnionFind<T>& state,
        const typename UnionFind<T>::ValueType& value_1,
        const typename UnionFind<T>::ValueType& value_2)
    {
        auto value_1_topmost = find_topmost_node(state, value_1);
        auto value_2_topmost = find_topmost_node(state, value_2);
        if (find_topmost_node(state, value_1) == find_topmost_node(state, value_2))
        {
            return;
        }

        state.hierarchy.insert(std::make_pair(value_1, std::move(value_2_topmost)));
    }
}