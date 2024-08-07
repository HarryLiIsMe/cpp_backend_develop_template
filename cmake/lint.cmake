# make lint
# https://clang.llvm.org/extra/clang-tidy/checks/list.html
# https://clang.llvm.org/extra/clang-tidy/index.html
# clang-tidy version >= 18.1.8
# clang-tidy --checks=*,-* --warnings-as-errors=* --format-style=google --dump-config > .clang-tidy
add_custom_target(lint
    COMMAND clang-tidy --config-file=.clang-tidy ${SRC_FILES} ${TEST_FILES} -p ${PROJECT_BINARY_DIR} 
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "lint code"
)
# add_custom_target(lint
#     COMMAND clang-tidy --config-file=.clang-tidy ${SRC_FILES} ${TEST_FILES} -p ${CMAKE_BINARY_DIR} 
#     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
#     COMMENT "lint code"
# )

# set(CLANG_TIDY_COMMAND)
# set(CMAKE_CXX_CLANG_TIDY)


# add_custom_target(lint
# COMMAND cppcheck --check-config .cppcheck -I ./inc --enable=all --inconclusive --suppress=missingIncludeSystem --std=c++11 ${SRC_FILES} ${TEST_FILES}
# WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
# COMMENT "lint code"
# )
