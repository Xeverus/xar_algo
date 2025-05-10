#pragma once

#include <utility>

namespace xar_algo::quick_sort
{
    template <typename IterT, typename ComparatorT = std::less<typename IterT::value_type>>
    void sort(IterT begin, IterT end, ComparatorT comparator = {})
    {

    }
}