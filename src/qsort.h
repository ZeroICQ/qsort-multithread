#pragma once

#include <iterator>
#include <thread>
#include <mutex>
#include <memory>
#include <vector>

namespace atl {
    const int SIZE_SUPER_LARGE  = 1000000000;
    const int SIZE_LARGE        = 1000000;
    const int SIZE_MEDIUM       =   50000;
    const int SIZE_SMALL        =    1000;


    const uint  SEED  = 500;
    std::shared_ptr<std::vector<int>> get_default_vector(int size);

    //returns pivot element
    template <class RandIt>
    RandIt qsort_segment(RandIt first, RandIt after_last, std::random_access_iterator_tag)
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

        auto pivot = qsort_segment(first, after_last, std::random_access_iterator_tag());

        qsort_nt(first, pivot, std::random_access_iterator_tag());

        if (pivot < after_last - 1) {
            qsort_nt(pivot + 1, after_last, std::random_access_iterator_tag());
        }
    }


    template <class Iter>
    void qsort_nt(Iter first, Iter last)
    {
        qsort_nt(first, last, typename std::iterator_traits<Iter>::iterator_category());
    }

    template <class RandIt>
    void qsort_t(RandIt first, RandIt after_last, int threads, std::random_access_iterator_tag)
    {
        auto pivot = qsort_segment(first, after_last, std::random_access_iterator_tag());

        std::thread* left_thread = nullptr;
        std::thread* right_thread = nullptr;

        if (pivot - first > 1) {
            if (threads > 0) {
                threads -= 1;
                left_thread = new std::thread(qsort_t<RandIt>, first, pivot, threads, std::random_access_iterator_tag());
            } else {
                qsort_nt(first, pivot, std::random_access_iterator_tag());
            }

        }

        if (after_last - pivot > 2) {
            if (threads > 0) {
                threads -= 1;
                right_thread = new std::thread(qsort_t<RandIt>, pivot + 1, after_last, threads, std::random_access_iterator_tag());
            } else {
                qsort_nt(pivot + 1, after_last, std::random_access_iterator_tag());
            }

        }

        if (left_thread) {
            left_thread->join();
        }

        if (right_thread) {
            right_thread->join();
        }

        delete left_thread;
        delete right_thread;
    }

    //qsort multithreads
    template <class Iter>
    void qsort_t(Iter first, Iter last, int threads = 4)
    {
        qsort_t(first, last, threads, typename std::iterator_traits<Iter>::iterator_category());
    }

} //namespace atl




