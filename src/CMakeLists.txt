add_compile_definitions(_POSIX_C_SOURCE=200809L _XOPEN_SOURCE=700)

if (APPLE)
    add_definitions(-D_DARWIN_C_SOURCE)
endif ()

find_program(LINT "clang-tidy")
IF (LINT)
    set(CMAKE_C_CLANG_TIDY "clang-tidy;-checks=*,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-clang-analyzer-security.insecureAPI.strcpy,-concurrency-mt-unsafe,-android-cloexec-accept,-android-cloexec-dup,-google-readability-todo,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-cert-dcl03-c,-hicpp-static-assert,-misc-static-assert,-altera-struct-pack-align,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling;--quiet")
ENDIF ()

# Make a shared library
add_library(dc_posix SHARED ${SOURCE_LIST} ${HEADER_LIST} ${HEADER_SYS_LIST} ${HEADER_ARPA_LIST} ${HEADER_NET_LIST})
target_include_directories(dc_posix PRIVATE ../include/dc_posix)
target_include_directories(dc_posix PRIVATE /usr/include)
target_include_directories(dc_posix PRIVATE /usr/local/include)
target_link_directories(dc_posix PRIVATE /usr/local/lib)

set_target_properties(dc_posix PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR})

find_library(LIBDC_ERROR dc_error REQUIRED)
find_library(LIB_RT rt)
find_library(LIB_PTHREAD pthread)
find_library(LIB_CRYPT crypt)
find_library(LIB_GDBM gdbm)
find_library(LIB_GDBM_COMPAT gdbm_compat)

target_link_libraries(dc_posix PUBLIC ${LIBDC_ERROR})

if(LIB_RT)
    target_link_libraries(dc_posix PUBLIC ${LIB_RT})
endif()

if(LIB_PTHREAD)
    target_link_libraries(dc_posix PUBLIC ${LIB_PTHREAD})
endif()

if(LIB_CRYPT)
    target_link_libraries(dc_posix PUBLIC ${LIB_CRYPT})
endif()

if(LIB_GDBM)
    target_link_libraries(dc_posix PUBLIC ${LIB_GDBM})
endif()

if(LIB_GDBM_COMPAT)
    target_link_libraries(dc_posix PUBLIC ${LIB_GDBM_COMPAT})
endif()

# All users of this library will need at least C11
target_compile_features(dc_posix PUBLIC c_std_11)
target_compile_options(dc_posix PRIVATE -g -fPIC)
target_compile_options(dc_posix PRIVATE -fstack-protector-all -ftrapv)
target_compile_options(dc_posix PRIVATE -Wpedantic -Wall -Wextra)
target_compile_options(dc_posix PRIVATE -Wdouble-promotion -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wnull-dereference -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wunused-local-typedefs -Wstrict-overflow=5 -Wmissing-noreturn -Walloca -Wfloat-equal -Wdeclaration-after-statement -Wshadow -Wpointer-arith -Wabsolute-value -Wundef -Wexpansion-to-defined -Wunused-macros -Wno-endif-labels -Wbad-function-cast -Wcast-qual -Wwrite-strings -Wconversion -Wdangling-else -Wdate-time -Wempty-body -Wsign-conversion -Wfloat-conversion -Waggregate-return -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes -Wmissing-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Winvalid-pch -Wvariadic-macros -Wdisabled-optimization -Wstack-protector -Woverlength-strings)

install(TARGETS dc_posix LIBRARY DESTINATION lib)
install(FILES ${HEADER_LIST} DESTINATION include/dc_posix)
install(FILES ${HEADER_SYS_LIST} DESTINATION include/dc_posix/sys)
install(FILES ${HEADER_ARPA_LIST} DESTINATION include/dc_posix/arpa)
install(FILES ${HEADER_NET_LIST} DESTINATION include/dc_posix/net)

# IDEs should put the headers in a nice place
source_group(
        TREE "${PROJECT_SOURCE_DIR}/include"
        PREFIX "Header Files"
        FILES ${HEADER_LIST} ${HEADER_SYS_LIST} ${HEADER_ARPA_LIST} ${HEADER_NET_LIST}
)

add_custom_target(
        format
        COMMAND clang-format
        -i
        ${HEADER_LIST}
        ${HEADER_SYS_LIST}
        ${HEADER_ARPA_LIST}
        ${HEADER_NET_LIST}
        ${SOURCE_LIST}
)
