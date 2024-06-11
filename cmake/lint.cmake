# make lint
# clang-tidy --checks="*" --format-style=google --dump-config > .clang-tidy
# clang-tidy --checks="-*,clang-analyzer-*,-clang-analyzer-cplusplus,cppcoreguidelines-*,google-*" --format-style=google --dump-config > .clang-tidy
# add_custom_target(lint
# COMMAND clang-tidy --config-file=.clang-tidy ${SRC_FILES} ${TEST_FILES} -- -I ./inc -x c++
# WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
# COMMENT "lint code"
# )

# add_custom_target(lint
# COMMAND cppcheck --check-config .cppcheck -I ./inc --enable=all --inconclusive --suppress=missingIncludeSystem --std=c++11 ${SRC_FILES} ${TEST_FILES}
# WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
# COMMENT "lint code"
# )
