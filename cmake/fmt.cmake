# make fmt
# clang-format version >= 18.1.8
# clang-format --style=Google --dump-config > .clang-format
add_custom_target(fmt
    COMMAND clang-format -i ${SRC_FILES} ${INC_FILES} ${TEST_FILES}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "fmt code"
)
