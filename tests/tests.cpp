#include "catch.hpp"
#include "qsort.h"

TEST_CASE("Hello world")
{
    std::vector<int> test_vector = {9, 8, 7, 6, 5, 4};
    atl::qsort(test_vector.begin(), test_vector.end());
    REQUIRE(true);
//    REQUIRE(false);
}