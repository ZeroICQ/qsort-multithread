add_library(qsort STATIC qsort.cpp)
target_include_directories(qsort PUBLIC .)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(qsort PRIVATE -g3 -O0 -coverage)
    set_target_properties(qsort  PROPERTIES LINK_FLAGS " ${LINK_FLAGS} -coverage")
endif()