cmake_minimum_required(VERSION 3.2.1)
project (scratch)

add_compile_options(-std=c++11)

# Add project cmake modules to path.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

# We probably don't want this to run on every build.
option(COVERAGE "Generate Coverage Data" ON)

if (COVERAGE)
    include(CodeCoverage)
    set(LCOV_REMOVE_EXTRA "'vendor/*'")
    setup_target_for_coverage(code_coverage test/detectHuman-test coverage)
    set(COVERAGE_SRCS app/main.cpp include/Detect.hpp include/Data.hpp include/Train.hpp)

    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -g")
endif()

find_package(OpenCV REQUIRED)

# INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )
# add_executable( detect app/main.cpp )
# target_link_libraries( detect ${OpenCV_LIBS} )

include(CMakeToolsHelpers OPTIONAL)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(app)
add_subdirectory(test)
add_subdirectory(vendor/googletest/googletest)

