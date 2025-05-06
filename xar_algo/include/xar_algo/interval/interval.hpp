#pragma once

#include <algorithm>


namespace xar_algo::interval
{
    /**
     * Represents an interval of values of type T. Both ends are part of the interval (are included).
     *
     * @tparam T Type of the values stored in the interval.
     */
    template <typename T>
    struct TInterval
    {
    public:
        using ValueType = T;

    public:
        T begin;
        T end;
    };


    template <typename T>
    bool contains(
        const TInterval<T>& interval,
        const T& value)
    {
        return interval.begin <= value && value <= interval.end;
    }

    template <typename T>
    bool overlap(
        const TInterval<T>& left,
        const TInterval<T>& right)
    {
        return contains(left, right.begin) || contains(right, left.begin);
    }

    template <typename T>
    TInterval<T> merge(
        const TInterval<T>& left,
        const TInterval<T>& right)
    {
        return {
            std::min(left.begin, right.begin),
            std::max(left.end, right.end)
        };
    }
}