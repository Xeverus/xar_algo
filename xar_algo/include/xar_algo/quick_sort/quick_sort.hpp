#pragma once

#include <utility>

#include <xar_algo/quick_sort/partition.hpp>

namespace xar_algo::quick_sort
{
    template <
        typename IterT,
        typename ComparatorT = std::less<typename IterT::value_type>>
    void quick_sort(IterT begin, IterT end, ComparatorT comparator = {})
    {
        if (begin == end)
        {
            return;
        }

        const auto pre_end = std::prev(end);
        const auto pivot_iter = partition(begin, pre_end, *pre_end, comparator);
        std::iter_swap(pivot_iter, pre_end);

        if (pivot_iter != begin)
        {
            quick_sort(
                begin,
                pivot_iter,
                comparator);
        }
        if (pivot_iter != end)
        {
            quick_sort(
                std::next(pivot_iter),
                end,
                comparator);
        }
    }
}