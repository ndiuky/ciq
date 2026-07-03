cmake_minimum_required(VERSION 4.0)
project(ciq)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRCS src/*.cpp src/*.hpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} ${SRCS})

add_subdirectory(lib/test)

target_include_directories(${PROJECT_NAME} PUBLIC src)