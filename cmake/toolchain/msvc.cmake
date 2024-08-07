if(MSVC)
    set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE)

    foreach(CompilerFlag ${CompilerFlags})
        string(REPLACE "/MT" "/MD" ${CompilerFlag} "${${CompilerFlag}}")
    endforeach()
endif(MSVC)

add_definitions(-DUNICODE -D_UNICODE)

set(CMAKE_DEBUG_POSTFIX "d")
