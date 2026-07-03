project(ciq_test)

file(GLOB_RECURSE CIQ_SRCS CONFIGURE_DEPENDS ${SRCS})

list(FILTER CIQ_SRCS EXCLUDE REGEX ".*/main\\.cpp$")

add_library(ciq_library STATIC ${CIQ_SRCS})

target_include_directories(ciq_library PUBLIC "../../src")

file(GLOB_RECURSE TEST_SRCS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(${PROJECT_NAME} ${TEST_SRCS})

target_link_libraries(${PROJECT_NAME} PRIVATE
        gtest
        gtest_main
        ciq_library
)
