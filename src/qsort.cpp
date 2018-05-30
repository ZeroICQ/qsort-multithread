#include <cstdlib>
#include <climits>
#include "qsort.h"

int *atl::standard_input()
{
    auto array = new int[SIZE];
    std::srand(SEED);
    for (int i = 0; i < SIZE; i++) {
        array[i] = std::rand() - RAND_MAX / 2;
    }

    return array;
}

void atl::qsort(int *arr, int size)
{
    if (size < 2) {
        return;
    }

    int* left = arr;
    int* right = arr + size - 1;
    int* pivot = left + size / 2;

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

        swap(left, right);
    }

    auto left_size = static_cast<int>(pivot - arr);

    qsort(arr, left_size);
    qsort(arr + left_size, size - left_size);
}

void atl::swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
