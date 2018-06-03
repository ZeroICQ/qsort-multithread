link_directories(lib)

add_executable(benchmarks benchmarks.cpp)

find_package(Threads)

target_compile_options(benchmarks PUBLIC -Wl,--stack,81943004)

target_link_libraries(benchmarks benchmark ${CMAKE_THREAD_LIBS_INIT} qsort)


