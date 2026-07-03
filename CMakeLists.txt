cmake_minimum_required(VERSION 4.0)
project(ciq)

file(GLOB_RECURSE SRCS src/*.cpp src/*.hpp)

add_executable(${PROJECT_NAME} ${SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC src)