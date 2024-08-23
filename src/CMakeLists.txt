cmake_minimum_required(VERSION 3.20)

project(Request)

set(SOURCES Request.cpp)

set(HEADERS Request.h)

add_library(Request STATIC ${SOURCES} ${HEADERS})

# target_include_directories(Request PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})