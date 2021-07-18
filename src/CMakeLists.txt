# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

#set(HEADER_LIST
#        "${libdc_posix_SOURCE_DIR}/include/dc_posix/posix_env.h"
#        "${libdc_posix_SOURCE_DIR}/include/dc_posix/fcntl.h"
#        "${libdc_posix_SOURCE_DIR}/include/dc_posix/inttypes.h"
#        "${libdc_posix_SOURCE_DIR}/include/dc_posix/netdb.h"
#        "${libdc_posix_SOURCE_DIR}/include/dc_posix/signal.h"
#        "${libdc_posix_SOURCE_DIR}/include/dc_posix/stdlib.h"
#        "${libdc_posix_SOURCE_DIR}/include/dc_posix/string.h"
#        "${libdc_posix_SOURCE_DIR}/include/dc_posix/unistd.h"
#        "${libdc_posix_SOURCE_DIR}/include/dc_posix/wordexp.h"
#        "${libdc_posix_SOURCE_DIR}/include/dc_posix/regex.h)

#set(HEADER_SYS_LIST
#        "${libdc_posix_SOURCE_DIR}/include/dc_posix/sys/socket.h"
#        "${libdc_posix_SOURCE_DIR}/include/dc_posix/sys/stat.h"
#)

#set(SOURCE_LIST
#        posix_env.c
#        fcntl.c
#        inttypes.c
#        netdb.c
#        signal.c
#        stdlib.c
#        string.c
#        unistd.c
#        wordexp.c
#        sys/socket.c
#        sys/stat.c regex.c)

# Make a shared library
add_library(dc_posix SHARED ${SOURCE_LIST} ${HEADER_LIST} ${HEADER_SYS_LIST})
target_include_directories(dc_posix PRIVATE /usr/include)
target_include_directories(dc_posix PRIVATE /usr/local/include)
target_link_directories(dc_posix PRIVATE /usr/local/lib)

set_target_properties(dc_posix PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR})

# All users of this library will need at least C11
target_compile_features(dc_posix PUBLIC c_std_11)
target_compile_options(dc_posix PRIVATE -iquote "${libdc_posix_SOURCE_DIR}/include/dc_posix")
target_compile_options(dc_posix PRIVATE -g -fPIC)
target_compile_options(dc_posix PRIVATE -fstack-protector-all -ftrapv)
target_compile_options(dc_posix PRIVATE -Wpedantic -Wall -Wextra)
target_compile_options(dc_posix PRIVATE -Wdouble-promotion -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wnull-dereference -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wunused-local-typedefs -Wstrict-overflow=5 -Wmissing-noreturn -Walloca -Wfloat-equal -Wdeclaration-after-statement -Wshadow -Wpointer-arith -Wabsolute-value -Wundef -Wexpansion-to-defined -Wunused-macros -Wno-endif-labels -Wbad-function-cast -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wdangling-else -Wdate-time -Wempty-body -Wsign-conversion -Wfloat-conversion -Waggregate-return -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes -Wmissing-declarations -Wpacked -Wpadded -Wredundant-decls -Wnested-externs -Winline -Winvalid-pch -Wlong-long -Wvariadic-macros -Wdisabled-optimization -Wstack-protector -Woverlength-strings )

install(TARGETS dc_posix LIBRARY DESTINATION lib)
install(FILES ${HEADER_LIST} DESTINATION include/dc_posix)
install(FILES ${HEADER_SYS_LIST} DESTINATION include/dc_posix/sys)

# IDEs should put the headers in a nice place
source_group(
        TREE "${PROJECT_SOURCE_DIR}/include"
        PREFIX "Header Files"
        FILES ${HEADER_LIST} ${HEADER_SYS_LIST}
)
