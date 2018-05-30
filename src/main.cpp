#include <iostream>
#include "qsort.h"

int main (int argc, char* argv[])
{
    auto data = atl::standard_input();

    delete[] data;
    return EXIT_SUCCESS;
}