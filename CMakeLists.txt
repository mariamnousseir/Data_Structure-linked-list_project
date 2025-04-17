cmake_minimum_required(VERSION 3.15)
project(linked_list LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES
    src/LinkedList.cpp
    src/main.cpp
)

add_executable(linked_list ${SOURCES})
