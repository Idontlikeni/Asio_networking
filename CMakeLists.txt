cmake_minimum_required(VERSION 3.20)

project(asio_app)

set(CLIENT_EXE client.cpp)
set(SERVER_EXE server.cpp)
# set(LIB_SOURCE src/Request.cpp)

include_directories(src)

# add_library(Request STATIC ${LIB_SOURCE})

add_executable(client ${CLIENT_EXE})

add_executable(server ${SERVER_EXE})

add_subdirectory(src)

# add_library(server INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/asio-1.30.2/include/asio.hpp")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/asio-1.30.2/include")
# target_include_directories(client PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/asio-1.30.2/include")
# target_include_directories(asio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/asio-1.30.2/include)
target_link_libraries(server Request)

#port = 8080
#127.0.0.1 8080