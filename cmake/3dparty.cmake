set(3DPARTY_SRC)

# add Isty001/dotenv-c
set(DOTENV_DIRS ${3DPARTY}/dotenv-c-0.1.0)
set(DOTENV_SRC_DIRS ${DOTENV_DIRS}/src)
set(DOTENV_INCS ${DOTENV_DIRS}/src)
add_subdirectory(${DOTENV_DIRS})
include_directories(${DOTENV_INCS})
file(GLOB DOTENV_SRC "${DOTENV_SRC_DIRS}/*.c")
list(APPEND 3DPARTY_SRC ${DOTENV_SRC})
