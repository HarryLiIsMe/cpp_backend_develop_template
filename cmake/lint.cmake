# make lint
# https://github.com/llvm/llvm-project.git
# https://clang.llvm.org/extra/clang-tidy/checks/list.html
# https://clang.llvm.org/extra/clang-tidy/index.html
# clang-tidy version >= 18.1.8
# clang-tidy --checks=*,-* --warnings-as-errors=* --format-style=google --dump-config > .clang-tidy
# add_custom_target(lint
#     COMMAND clang-tidy --config-file=.clang-tidy ${SRC_FILES} ${TEST_FILES} -- -x c++ -I ${INC_DIRS} -I ${GTEST_INCS}
#     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
#     COMMENT "lint code"
# )
# add_custom_target(lint
#     COMMAND clang-tidy --config-file=.clang-tidy ${SRC_FILES} ${TEST_FILES} -p ${PROJECT_BINARY_DIR}|{CMAKE_BINARY_DIR} 
#     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
#     COMMENT "lint code"
# )

# set(CLANG_TIDY_COMMAND)
# set(CMAKE_CXX_CLANG_TIDY)


# https://github.com/danmar/cppcheck
# https://sourceforge.net/p/cppcheck/wiki/ListOfChecks/
# https://cppcheck.sourceforge.io/manual.pdf
# cppcheck version >= 2.14.1
add_custom_target(lint
COMMAND cppcheck --enable=all --suppressions-list=.suppressions.txt --language=c++ --std=c++20  ${SRC_FILES} ${TEST_FILES} -I ./inc
WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
COMMENT "lint code"
)

# set(CMAKE_CXX_CPPCHECK) 
# set(CMAKE_C_CPPCHECK) 
