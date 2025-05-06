#pragma once

#include <xar_algo/interval/interval.hpp>

#include <set>
#include <vector>


namespace xar_algo::interval
{
    template <typename T>
    struct TIntervalCollection
    {
    public:
        using IntervalType = TInterval<T>;
        using ValueType = TInterval<T>::ValueType;

        struct IntervalComparator;
        using IntervalSet = std::set<IntervalType, IntervalComparator>;
        using IntervalRange = std::pair<typename IntervalSet::const_iterator, typename IntervalSet::const_iterator>;

    public:
        IntervalSet data;
    };


    template <typename T>
    void add_interval(
        TIntervalCollection<T>& collection,
        typename TIntervalCollection<T>::IntervalType interval)
    {
    }


    template <typename T>
    bool contains_value(const T& value)
    {
    }


    template <typename T>
    TIntervalCollection<T>::IntervalRange find_overlapping_intervals(
        const TIntervalCollection<T>& collection,
        const typename TIntervalCollection<T>::IntervalType& interval)
    {
    }
}