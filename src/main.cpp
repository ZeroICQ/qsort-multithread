#include <iostream>
#include "qsort.h"
#include <iterator>
#include <vector>

int main (int argc, char* argv[])
{
    std::vector<int> data = {5, 4, 3, 2, 1, 0, -10};


//    for (int i = 0; i < data_size; i++) {
//        std::cout << data[i] << " ";
//    }

    atl::qsort(data.begin(), data.end());

    for (auto& i : data) {
        std::cout << i << " ";
    }
//    std::cout << std::endl;
//
//    for (int i = 0; i < data_size; i++) {
//        std::cout << data[i] << " ";
//    }

    return EXIT_SUCCESS;
}