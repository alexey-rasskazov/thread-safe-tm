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

if( CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR )

    add_subdirectory(tests)

endif()

