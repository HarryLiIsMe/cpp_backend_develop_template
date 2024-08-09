# make test
set(GTEST_DIRS ${3DPARTY}/googletest)
set(GTEST_SRC_DIRS ${GTEST_DIRS}/googletest/src)
set(GTEST_INCS ${GTEST_DIRS}/googletest/include)
set(GMOCK_SRC_DIRS ${GTEST_DIRS}/googlemock/src)
set(GMOCK_INCS ${GTEST_DIRS}/googlemock/include)

add_subdirectory(${GTEST_DIRS})
include_directories(${GTEST_INCS})

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
