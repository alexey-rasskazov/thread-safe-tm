cmake_minimum_required(VERSION 3.8)

#
# UTF-8 Utilities
#

project(datetime)

add_library(datetime STATIC src/datetime.cpp src/datetime.h)
set_target_properties(
      datetime PROPERTIES
      CXX_STANDARD 11
      CXX_STANDARD_REQUIRED ON
)

# Google Test
include(scripts/gtest.cmake)

# Tests executable target
add_executable(unit_tests tests/datetime_tests.cpp)

target_compile_features(unit_tests PRIVATE cxx_std_11)

target_include_directories(unit_tests PUBLIC src)

# Link gtest library
target_link_libraries(unit_tests gtest_main datetime)

add_test(NAME unit_tests COMMAND unit_tests)

