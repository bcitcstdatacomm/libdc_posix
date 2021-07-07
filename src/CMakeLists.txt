# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

set(HEADER_LIST
        posix_env.h
        inttypes.h
        netdb.h
        signal.h
        stdlib.h
        string.h
        unistd.h
        wordexp.h
)

set(HEADER_SYS_LIST
        sys/socket.h
)


set(SOURCE_LIST
        posix_env.c
        inttypes.c
        netdb.c
        signal.c
        stdlib.c
        string.c
        unistd.c
        wordexp.c
        sys/socket.c
)

# Make an static library
add_library(dc_posix SHARED ${SOURCE_LIST} ${HEADER_LIST})
target_include_directories(dc_posix PRIVATE /usr/include)
target_include_directories(dc_posix PRIVATE /usr/local/include)
target_link_directories(dc_posix PRIVATE /usr/local/lib)

set_target_properties(dc_posix  PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR})

# All users of this library will need at least C11
target_compile_features(dc_posix PUBLIC c_std_11)
target_compile_options(dc_posix PRIVATE -g -fPIC)
target_compile_options(dc_posix PRIVATE -fstack-protector-all -ftrapv)
target_compile_options(dc_posix PRIVATE -Wpedantic -Wall -Wextra)
target_compile_options(dc_posix PRIVATE -Wdouble-promotion -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wnull-dereference -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wunused-local-typedefs -Wstrict-overflow=5 -Wmissing-noreturn -Walloca -Wfloat-equal -Wdeclaration-after-statement -Wshadow -Wpointer-arith -Wabsolute-value -Wundef -Wexpansion-to-defined -Wunused-macros -Wno-endif-labels -Wbad-function-cast -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wdangling-else -Wdate-time -Wempty-body -Wsign-conversion -Wfloat-conversion -Waggregate-return -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes -Wmissing-declarations -Wpacked -Wpadded -Wredundant-decls -Wnested-externs -Winline -Winvalid-pch -Wlong-long -Wvariadic-macros -Wdisabled-optimization -Wstack-protector -Woverlength-strings )

install(TARGETS dc_posix LIBRARY DESTINATION lib)
install(FILES ${HEADER_LIST} DESTINATION include/dc_posix)
install(FILES ${HEADER_SYS_LIST} DESTINATION include/dc_posix/sys)

# IDEs should put the headers in a nice place
source_group(
        TREE "${PROJECT_SOURCE_DIR}/src"
        PREFIX "Header Files"
        FILES ${HEADER_LIST} ${HEADER_SYS_LIST}
)
