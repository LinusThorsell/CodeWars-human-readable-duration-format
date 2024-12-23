cmake_minimum_required(VERSION 3.10)
project(CW_SOLUTION)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
add_library(solution src/solution.cpp)

# Add main program
add_executable(main main.cpp)
target_link_libraries(main solution)

# Enable testing
enable_testing()

# Find GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test executable
add_executable(test_solution tests/test_solution.cpp)
target_link_libraries(test_solution solution ${GTEST_BOTH_LIBRARIES} pthread)

# Add a test
add_test(NAME SolutionTest COMMAND test_solution)
