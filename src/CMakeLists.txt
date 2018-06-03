add_library(qsort STATIC qsort.cpp)
target_include_directories(qsort PUBLIC .)

find_package(Threads)

add_executable(main main.cpp)
target_compile_options(main PUBLIC "-Wl,--stack,8194300400")
target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT} qsort)