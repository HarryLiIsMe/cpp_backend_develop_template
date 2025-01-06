set(CMAKE_VERBOSE_MAKEFILE TRUE)

add_definitions(
    -ggdb3 -O0 -m64

    # -std=c++20 -fPIC
    # -fstack-protector
    # -fstack-protector-all
    # -fstack-protector-strong
    # -fstack-protector-explicit
    # -ftrampolines -ftrapv -fwrapv
)

add_link_options(
    -fsanitize=address
)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
