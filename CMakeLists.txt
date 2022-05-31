cmake_minimum_required(VERSION 3.4...3.18)
project(cmake_example)

add_subdirectory(pybind11)
pybind11_add_module(cmake_example src/main.cpp src/main.h src/linkedlist.h src/tree.h src/map.h)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(cmake_example
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})


add_subdirectory(lib/googletest) # I renamed googletest-master folder to gtest, so that should be fine.
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

#target_link_libraries(tests gtest gtest_main pybind11)