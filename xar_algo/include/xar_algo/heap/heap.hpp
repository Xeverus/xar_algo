#pragma once

#include <vector>

namespace xar_algo::heap
{

    template <typename T, typename Comp = std::less<T>, typename Cont = std::vector<T>>
    class Heap
    {
    public:
        void push(T value)
        {
            data_.push_back(value);

            auto element_it = std::prev(data_.end());
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

        T pop()
        {
            auto ret = data_.front();

            std::swap(data_.front(), data_.back());
            data_.pop_back();

            auto element_it = data_.begin();

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
                    return ret;
                }

                if (Comp()(*smaller_child, *element_it))
                {
                    std::iter_swap(element_it, smaller_child);
                    element_it = smaller_child;
                    continue;
                }

                element_it = data_.end();
            }

            return ret;
        }

        std::size_t size()
        {
            return data_.size();
        }

    private:
        Cont data_;

    private:
        [[nodiscard]]
        Cont::iterator getParent(Cont::iterator child)
        {
            const auto child_index = std::distance(data_.begin(), child);
            const auto parent_index = (child_index - 1) / 2;

            auto parent_it = data_.begin();
            std::advance(parent_it, parent_index);
            return parent_it;
        }

        [[nodiscard]]
        Cont::iterator getChild(Cont::iterator parent, const std::size_t childIndex)
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

        Cont::iterator getLeftChild(Cont::iterator parent)
        {
            return getChild(parent, 1);
        }

        Cont::iterator getRightChild(Cont::iterator parent)
        {
            return getChild(parent, 2);
        }
    };

}
