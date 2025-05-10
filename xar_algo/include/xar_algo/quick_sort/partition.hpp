#pragma once

#include <utility>

namespace xar_algo::quick_sort
{
    template <
        typename IterT,
        typename ValueT = typename IterT::value_type,
        typename ComparatorT = std::less<typename IterT::value_type>>
    IterT partition(IterT begin, IterT end, const ValueT& pivot, ComparatorT comparator = {})
    {
        auto insert_iter = begin;
        for (auto current_iter = begin; current_iter != end; ++current_iter)
        {
            if (!comparator(*current_iter, pivot)) {
                continue;
            }

            std::iter_swap(current_iter, insert_iter);
            ++insert_iter;
        }

        return insert_iter;
    }
}