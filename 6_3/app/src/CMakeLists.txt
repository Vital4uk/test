cmake_minimum_required(VERSION 3.18.4)

FILE(GLOB_RECURSE HEADERS  ${CMAKE_SOURCE_DIR}/app/src/*.h)
FILE(GLOB_RECURSE SOURCES  ${CMAKE_SOURCE_DIR}/app/src/*.cpp)

add_library(src ${SOURCES} ${HEADERS} )
target_link_libraries( src )
