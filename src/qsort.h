#pragma once

#include <iterator>
#include <thread>
#include <mutex>

namespace atl {
    const int   SIZE  = 100;
    const uint  SEED  = 500;

    //returns pivot element
    template <class RandIt>
    RandIt qsort_section(RandIt first, RandIt after_last, std::random_access_iterator_tag)
    {
        auto size = after_last - first;

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
        return pivot;
    }

    template <class RandIt>
    void qsort_nt(RandIt first, RandIt after_last, std::random_access_iterator_tag)
    {
        auto size = after_last - first;

        if (size < 2) {
            return;
        }

        auto pivot = qsort_section(first, after_last, std::random_access_iterator_tag());

        qsort_nt(first, pivot, std::random_access_iterator_tag());

        if (pivot < after_last - 1) {
            qsort_nt(pivot + 1, after_last, std::random_access_iterator_tag());
        }
    }

//    template <class InIter>
//    void qsort_nt(InIter first, InIter last, std::forward_iterator_tag)
//    {
//        //todo: write tests
//    }

    //qsort single threads
    template <class Iter>
    void qsort_nt(Iter first, Iter last)
    {
        qsort_nt(first, last, typename std::iterator_traits<Iter>::iterator_category());
    }

    template <class RandIt>
    void qsort_t(RandIt first, RandIt after_last, std::random_access_iterator_tag)
    {

    }

    //qsort multithreads
    template <class Iter>
    void qsort_t(Iter first, Iter last, int threads = 4)
    {
        
        qsort_t(first, last, typename std::iterator_traits<Iter>::iterator_category());
    }

} //namespace atl




