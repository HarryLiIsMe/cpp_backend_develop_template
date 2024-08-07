# make lint
# clang-tidy version >= 18.1.8
# clang-tidy --checks="-llvmlibc-*,-modernize-use-trailing-return-type,-readability-identifier-length,-performance-avoid-endl,-cppcoreguidelines-avoid-magic-numbers,-readability-named-parameter" --format-style=google --dump-config > .clang-tidy
# clang-tidy --checks="-*,clang-diagnostic-*,clang-analyzer-*,cppcoreguidelines-*,google-*,-google-readability-*" --warnings-as-errors=* --format-style=google --dump-config > .clang-tidy
add_custom_target(lint
    COMMAND clang-tidy --config-file=.clang-tidy ${SRC_FILES} ${TEST_FILES} -p ${PROJECT_BINARY_DIR} 
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "lint code"
)

# set(CLANG_TIDY_COMMAND)
# set(CMAKE_CXX_CLANG_TIDY)

# add_custom_target(lint
# COMMAND cppcheck --check-config .cppcheck -I ./inc --enable=all --inconclusive --suppress=missingIncludeSystem --std=c++11 ${SRC_FILES} ${TEST_FILES}
# WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
# COMMENT "lint code"
# )
