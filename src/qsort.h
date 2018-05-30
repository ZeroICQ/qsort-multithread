#pragma once

#include <iterator>
#include <thread>

namespace atl {
    const int   SIZE  = 10;
    const uint  SEED  = 500;

    template <class RandIt>
    void qsort(RandIt first, RandIt after_last, std::random_access_iterator_tag)
    {
        auto size = after_last - first;

        if (size < 2) {
            return;
        }

        auto left = first;
        auto right = after_last - 1;
        auto pivot = first + size / 2;

        while (!(left == pivot && right == pivot)) {
            while (*left <= *pivot && left < pivot ) {
                ++left;
            }

            while (*right >= *pivot && right > pivot) {
                --right;
            }

            if (left == pivot) {
                pivot = right;
            } else if (right == pivot) {
                pivot = left;
            }

            std::iter_swap(left, right);
        }

        void (*qfunc)(RandIt first, RandIt after_last, std::random_access_iterator_tag) = &qsort;
        std::thread t_left(qfunc, first, pivot, std::random_access_iterator_tag());
//        qsort(first, pivot, std::random_access_iterator_tag());
        if (pivot < after_last - 1) {
            std::thread t_right(qfunc, pivot + 1, after_last, std::random_access_iterator_tag());
//            qsort(pivot + 1, after_last, std::random_access_iterator_tag());
            t_right.join();
        }
        t_left.join();
    }

    template <class InIter>
    void qsort(InIter first, InIter last, std::forward_iterator_tag)
    {
        //todo: write tests
    }

    template <class Iter>
    void qsort(Iter first, Iter last)
    {
        qsort(first, last, typename std::iterator_traits<Iter>::iterator_category());
    }

} //namespace atl




