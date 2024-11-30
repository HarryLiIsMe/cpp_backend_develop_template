cmake_minimum_required(VERSION 3.20.0)

project(cpp_backend_develop_template LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(INC_DIRS ${CMAKE_SOURCE_DIR}/inc)
set(SRC_DIRS ${CMAKE_SOURCE_DIR}/src)
set(TEST_DIRS ${CMAKE_SOURCE_DIR}/tests)

file(GLOB_RECURSE INC_FILES ${INC_DIRS}/*.h)
file(GLOB_RECURSE SRC_FILES ${SRC_DIRS}/*.cpp)
file(GLOB_RECURSE TEST_FILES ${TEST_DIRS}/*.cpp)

set(3DPARTY ${CMAKE_SOURCE_DIR}/3dparty)

# include 3dparty
include(cmake/3dparty.cmake)

if(WIN32)
    include(cmake/toolchain/msvc.cmake)
elseif(UNIX)
    include(cmake/toolchain/gcc.cmake)
elseif(APPLE)
    include(cmake/toolchain/clang.cmake)
else()
    message(FATAL_ERROR "no support operator system")
endif()

include(cmake/unittest.cmake)
include(cmake/fmt.cmake)
include(cmake/lint.cmake)

include_directories(
    ${INC_DIRS}
)

# exec binary file generate
add_executable(cpp_backend_develop_template_main
    ${SRC_DIRS}/main.cpp
    ${3DPARTY_SRC}
)
target_link_libraries(cpp_backend_develop_template_main)

# static library generate
add_library(cpp_backend_develop_template_st STATIC
    ${SRC_DIRS}/equal_i32.cpp
    ${SRC_DIRS}/max_i32.cpp
)

# shared dynamic library generate
add_library(cpp_backend_develop_template_dy SHARED
    ${SRC_DIRS}/equal_i32.cpp
    ${SRC_DIRS}/max_i32.cpp
)

set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/output/lib")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/output/bin")
