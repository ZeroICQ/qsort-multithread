#include <cstdlib>
#include <climits>
#include "qsort.h"

std::shared_ptr<std::vector<int>> atl::get_default_vector(int size)
{
    auto default_vector = std::make_shared<std::vector<int>>();

    std::srand(atl::SEED);

    for (int i = 0; i < size; i++) {
        default_vector->push_back(std::rand() - RAND_MAX / 2);
    }
    return  default_vector;
}
