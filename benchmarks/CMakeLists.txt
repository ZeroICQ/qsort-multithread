link_directories(lib)

add_executable(benchmarks benchmarks.cpp)

find_package(Threads)

target_link_libraries(benchmarks benchmark ${CMAKE_THREAD_LIBS_INIT})
