#include "qsort.h"

int main()
{
    auto test_vector = atl::get_default_vector();
    atl::qsort_t(test_vector->begin(), test_vector->end());
    return EXIT_SUCCESS;
}