cmake_minimum_required(VERSION 3.18.4)

project(calculator LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#include(FetchContent)
#FetchContent_Declare(
#  googletest
#  # Specify the commit you depend on and update it regularly.
#  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
#)

# Setup testing
find_package(GTest REQUIRED)
find_package(PkgConfig REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_compile_options(
        -std=c++20
        -Wall
        -Wextra
        -Werror
        -Wpedantic
         -lgtest
)

add_subdirectory(src)
add_subdirectory(unit_tests)

add_executable( ${PROJECT_NAME} main.cpp )
target_link_libraries(${CMAKE_PROJECT_NAME} src )

