cmake_minimum_required(VERSION 3.18.4)

# Setup testing
find_package(GTest REQUIRED)
enable_testing()

file(GLOB TESTS_FILES *.h *.cpp)

add_executable(unit_tests ${TESTS_FILES} main.cpp)
target_include_directories(unit_tests PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../src)
target_link_libraries(unit_tests gtest src)

add_test(unit_tests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} "../../")