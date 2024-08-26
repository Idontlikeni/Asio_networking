cmake_minimum_required(VERSION 3.16)

project(asio_app)

set(CLIENT_EXE client.cpp)
set(SERVER_EXE server.cpp)

include_directories(src)


add_executable(client ${CLIENT_EXE})

add_executable(server ${SERVER_EXE})

find_package(Threads REQUIRED)

add_subdirectory(src)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/asio-1.30.2/include")
target_link_libraries(server PRIVATE Threads::Threads Request)

#port = 8080
#127.0.0.1 8080