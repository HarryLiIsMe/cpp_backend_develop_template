# make lint
# https://github.com/llvm/llvm-project.git
# https://clang.llvm.org/extra/clang-tidy/checks/list.html
# https://clang.llvm.org/extra/clang-tidy/index.html
# clang-tidy version >= 18.1.8
# clang-tidy --checks=*,-* --warnings-as-errors=* --format-style=google --dump-config > .clang-tidy
add_custom_target(lint
    COMMAND clang-tidy --config-file=${CMAKE_SOURCE_DIR}/.clang-tidy ${SRC_FILES} ${TEST_FILES} -- -x c++ -I ${INC_DIRS} -I ${GTEST_INCS}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "lint code"
)
# add_custom_target(lint
#     COMMAND clang-tidy --config-file=${CMAKE_SOURCE_DIR}/.clang-tidy ${SRC_FILES} ${TEST_FILES} -p ${PROJECT_BINARY_DIR} 
#     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
#     COMMENT "lint code"
# )
# add_custom_target(lint
#     COMMAND clang-tidy --config-file=${CMAKE_SOURCE_DIR}/.clang-tidy ${SRC_FILES} ${TEST_FILES} -p ${CMAKE_BINARY_DIR} 
#     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
#     COMMENT "lint code"
# )

# set(CLANG_TIDY_COMMAND)
# set(CMAKE_CXX_CLANG_TIDY)


# https://github.com/danmar/cppcheck
# https://sourceforge.net/p/cppcheck/wiki/ListOfChecks/
# https://cppcheck.sourceforge.io/manual.pdf
# add_custom_target(lint
# COMMAND cppcheck -I ./inc --enable=all --inconclusive --suppress=missingIncludeSystem --std=c++11 ${SRC_FILES} ${TEST_FILES}
# WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
# COMMENT "lint code"
# )
