#include "catch.hpp"
#include "qsort.h"

void test_sort(std::vector<int>& test_vector)
{
    for (int i = 0; i < static_cast<int>(test_vector.size()) - 1; i++) {
        REQUIRE(test_vector[i] <= test_vector[i+1]);
    }
}

TEST_CASE("Hello world")
{
    SECTION("no threads") {
        auto test_vector = atl::get_default_vector();

        atl::qsort_nt(test_vector->begin(), test_vector->end());
        test_sort(*test_vector);
    }

    SECTION("threads") {
        auto test_vector2 = atl::get_default_vector();

        atl::qsort_t(test_vector2->begin(), test_vector2->end());
        test_sort(*test_vector2);
    }
}
