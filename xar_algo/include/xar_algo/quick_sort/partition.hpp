#pragma once

#include <utility>

namespace xar_algo::quick_sort
{
    template <
        typename IterT,
        typename ValueT = typename IterT::value_type,
        typename ComparatorT = std::less<typename IterT::value_type>>
    void partition(IterT begin, IterT end, const ValueT& pivot, ComparatorT comparator = {})
    {

    }
}