#pragma once

#include <utility>

namespace xar_algo::partition
{
    template <
        typename IterT,
        typename ValueT = typename IterT::value_type,
        typename ComparatorT = std::less<typename IterT::value_type>>
    IterT partition(IterT begin, IterT end, const ValueT& pivot_value, ComparatorT comparator = {})
    {
        auto insert_iter = begin;
        for (auto current_iter = begin; current_iter != end; ++current_iter)
        {
            if (!comparator(*current_iter, pivot_value)) {
                continue;
            }

            std::iter_swap(current_iter, insert_iter);
            ++insert_iter;
        }

        return insert_iter;
    }
}