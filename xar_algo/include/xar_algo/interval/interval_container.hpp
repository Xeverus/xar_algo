#pragma once

#include <xar_algo/interval/interval.hpp>

#include <set>
#include <vector>


namespace xar_algo::interval
{
    /**
     * Contains a set of non-overlapping intervals.
     *
     * @tparam T Type of value stored in interval.
     */
    template <typename T>
    struct TIntervalCollection
    {
    public:
        using IntervalType = TInterval<T>;
        using ValueType = TInterval<T>::ValueType;

        struct TIntervalComparator;
        using IntervalSet = std::set<IntervalType, TIntervalComparator>;
        using IntervalRange = std::pair<typename IntervalSet::const_iterator, typename IntervalSet::const_iterator>;

    public:
        IntervalSet data;
    };


    template <typename T>
    struct TIntervalCollection<T>::TIntervalComparator
    {
    public:
        bool operator()(const IntervalType& left, const IntervalType& right) const;
    };


    template <typename T>
    bool TIntervalCollection<T>::TIntervalComparator::operator()(
        const IntervalType& left,
        const IntervalType& right) const
    {
        return left.begin < right.begin;
    }


    template <typename T>
    void add(
        TIntervalCollection<T>& collection,
        typename TIntervalCollection<T>::IntervalType interval)
    {
    }


    template <typename T>
    bool contains(
        const TIntervalCollection<T>& collection,
        const T& value)
    {
        const auto iter = collection.data.upper_bound({value, {}});
        return iter != collection.data.begin() && contains(*std::prev(iter), value);
    }


    template <typename T>
    TIntervalCollection<T>::IntervalRange find_overlapping_intervals(
        const TIntervalCollection<T>& collection,
        const typename TIntervalCollection<T>::IntervalType& interval)
    {
        return {};
    }
}