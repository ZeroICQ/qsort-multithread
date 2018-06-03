set(TEST_SRC catch.cpp tests.cpp)
set(TEST_INC inc)

set(TESTS_TARGET "tests")

find_package(Threads)

add_executable(${TESTS_TARGET} ${TEST_SRC})
target_link_libraries(${TESTS_TARGET} qsort ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(${TESTS_TARGET} PRIVATE ${TEST_INC})

target_compile_options(${TESTS_TARGET} PRIVATE -g3 -O0 -coverage)
set_target_properties(${TESTS_TARGET} PROPERTIES LINK_FLAGS "${LINK_FLAGS} -coverage")
