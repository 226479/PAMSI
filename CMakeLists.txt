cmake_minimum_required(VERSION 3.4)
project(PAMSI CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic")

add_subdirectory(Algorithms)
add_subdirectory(Helpers)
add_subdirectory(Interfaces)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

add_executable(PAMSI main.cpp)

target_link_libraries(PAMSI
    PUBLIC
        Algorithms
        Helpers
        Interfaces
)

add_custom_target(run
    COMMAND PAMSI
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/../"
)
