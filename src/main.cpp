#include <iostream>
#include "qsort.h"

int main (int argc, char* argv[])
{
    auto data = atl::standard_input();

    int data_size = atl::SIZE;

//    for (int i = 0; i < data_size; i++) {
//        std::cout << data[i] << " ";
//    }

    atl::qsort(data, data_size);

//    std::cout << std::endl;
//
//    for (int i = 0; i < data_size; i++) {
//        std::cout << data[i] << " ";
//    }

    delete[] data;
    return EXIT_SUCCESS;
}