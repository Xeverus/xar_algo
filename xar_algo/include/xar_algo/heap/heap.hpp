#pragma once

#include <vector>

namespace xar_algo::heap
{
    template <typename T, typename Comp = std::less<T>, typename Cont = std::vector<T>>
    class Heap
    {
    public:
        using ValueType = T;
        using Comparator = Comp;
        using Iterator = Cont::iterator;
        using ConstIterator = Cont::const_iterator;

    public:
        Heap() = default;

        template <typename Iter>
        Heap(Iter begin, Iter end);

        void push(T value);
        T pop();

        [[nodiscard]] std::size_t size() const;
        [[nodiscard]] bool empty() const;

    private:
        Cont data_;

    private:
        void bubble_up(Iterator element_it);
        void sink_down(Iterator element_it);

        [[nodiscard]]
        Cont::iterator getParent(Iterator child);

        [[nodiscard]]
        Cont::iterator getChild(Iterator parent, std::size_t childIndex);

        Cont::iterator getLeftChild(Iterator parent);
        Cont::iterator getRightChild(Iterator parent);
    };

    template <typename T, typename Comp, typename Cont>
    template <typename Iter>
    Heap<T, Comp, Cont>::Heap(Iter begin, Iter end)
    {
        for (; begin != end; ++begin)
        {
            push(*begin);
        }
    }

    template <typename T, typename Comp, typename Cont>
    void Heap<T, Comp, Cont>::push(T value)
    {
        data_.push_back(value);

        bubble_up(std::prev(data_.end()));
    }

    template <typename T, typename Comp, typename Cont>
    T Heap<T, Comp, Cont>::pop()
    {
        auto ret = data_.front();

        std::swap(data_.front(), data_.back());
        data_.pop_back();

        sink_down(data_.begin());

        return ret;
    }

    template <typename T, typename Comp, typename Cont>
    std::size_t Heap<T, Comp, Cont>::size() const
    {
        return data_.size();
    }

    template <typename T, typename Comp, typename Cont>
    bool Heap<T, Comp, Cont>::empty() const
    {
        return data_.empty();
    }

    template <typename T, typename Comp, typename Cont>
    void Heap<T, Comp, Cont>::bubble_up(Iterator element_it)
    {
        while (element_it != data_.begin())
        {
            const auto parent_it = getParent(element_it);
            if (Comp()(*parent_it, *element_it))
            {
                return;
            }

            std::iter_swap(element_it, parent_it);
            element_it = parent_it;
        }
    }

    template <typename T, typename Comp, typename Cont>
    void Heap<T, Comp, Cont>::sink_down(Iterator element_it)
    {
        while (element_it != data_.end())
        {
            const auto left_child = getLeftChild(element_it);
            const auto right_child = getRightChild(element_it);

            auto smaller_child = left_child;
            if (left_child != data_.end() && right_child != data_.end())
            {
                if (Comp()(*right_child, *left_child))
                {
                    smaller_child = right_child;
                }
            }

            if (smaller_child == data_.end())
            {
                return;
            }

            if (Comp()(*smaller_child, *element_it))
            {
                std::iter_swap(element_it, smaller_child);
                element_it = smaller_child;
                continue;
            }

            element_it = data_.end();
        }
    }

    template <typename T, typename Comp, typename Cont>
    Cont::iterator Heap<T, Comp, Cont>::getParent(Iterator child)
    {
        const auto child_index = std::distance(data_.begin(), child);
        const auto parent_index = (child_index - 1) / 2;

        auto parent_it = data_.begin();
        std::advance(parent_it, parent_index);
        return parent_it;
    }

    template <typename T, typename Comp, typename Cont>
    Cont::iterator Heap<T, Comp, Cont>::getChild(Iterator parent, const std::size_t childIndex)
    {
        const auto parent_index = std::distance(data_.begin(), parent);
        const auto child_index = parent_index * 2 + childIndex;
        if (child_index >= data_.size())
        {
            return data_.end();
        }

        auto child_it = data_.begin();
        std::advance(child_it, child_index);
        return child_it;
    }

    template <typename T, typename Comp, typename Cont>
    Cont::iterator Heap<T, Comp, Cont>::getLeftChild(Iterator parent)
    {
        return getChild(parent, 1);
    }

    template <typename T, typename Comp, typename Cont>
    Cont::iterator Heap<T, Comp, Cont>::getRightChild(Iterator parent)
    {
        return getChild(parent, 2);
    }
}
