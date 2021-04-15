
project(datetime_tests)

# Google Test
include(scripts/gtest.cmake)

# Tests executable target
add_executable(unit_tests_tm datetime_tests.cpp)

target_compile_features(unit_tests_tm PRIVATE cxx_std_11)

target_include_directories(unit_tests_tm PUBLIC ../src)

# Link gtest library
target_link_libraries(unit_tests_tm gtest_main datetime)

add_test(NAME unit_tests COMMAND unit_tests_tm)