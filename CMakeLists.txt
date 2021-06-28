cmake_minimum_required(VERSION 3.10)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=leak -g")

set(CMAKE_VERBOSE_MAKEFILE TRUE)

project(Matrix)

file(GLOB SRC "src/*.cxx")

add_executable(Matrix ${SRC})

target_include_directories(Matrix
    PUBLIC
        ${PROJECT_SOURCE_DIR}/headers
)
