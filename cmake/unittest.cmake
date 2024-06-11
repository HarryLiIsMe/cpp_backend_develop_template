# make test
add_subdirectory(${3DPARTY}/googletest-1.14.0)
include_directories(${3DPARTY}/googletest-1.14.0/googletest/include)

# set(GTEST_LIB gtest gtest_main gmock gmock_main)
add_executable(tests
    ${TEST_DIRS}/test1.cpp
    ${TEST_DIRS}/test2.cpp
)
target_link_libraries(tests
    gtest
    gtest_main
    gmock
    gmock_main
)
enable_testing()
add_test(NAME tests
    COMMAND tests
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# set_tests_properties()
list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")

# gtest_discover_tests()
# gtest_add_tests()
