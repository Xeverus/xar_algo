#pragma once

#include <unordered_map>


namespace xar_algo::union_find
{
    template <typename T>
    struct UnionFind
    {
    public:
        using ValueType = T;
        using ChildType = ValueType;
        using ParentType = ValueType;
        using ChildParentRelation = std::unordered_map<ChildType, ParentType>;

    public:
        ChildParentRelation data;
    };


    template <typename T>
    bool are_connected(
        const UnionFind<T> data,
        const typename UnionFind<T>::ValueType& value_1,
        const typename UnionFind<T>::ValueType& value_2)
    {
        return false;
    }
}