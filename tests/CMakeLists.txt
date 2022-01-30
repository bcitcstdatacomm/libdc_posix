add_compile_definitions(_POSIX_C_SOURCE=200809L _XOPEN_SOURCE=700)

if (APPLE)
    add_definitions(-D_DARWIN_C_SOURCE)
endif ()

set(TEST_HEADER_LIST
        tests.h
        )

set(TEST_SOURCE_LIST
        main.c
        posix_env_tests.c
        posix_error_tests.c
        string_tests.c
        )

include_directories(${CGREEN_PUBLIC_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})
add_executable(libdc_posix_test
        ${TEST_SOURCE_LIST} ${TEST_HEADER_LIST} ${SOURCE_LIST} ${HEADER_LIST} ${HEADER_SYS_LIST} ${HEADER_ARPA_LIST} ${HEADER_NET_LIST})

target_compile_features(libdc_posix_test PRIVATE c_std_11)
target_compile_options(libdc_posix_test PRIVATE -g)
target_compile_options(libdc_posix_test PRIVATE -fstack-protector-all -ftrapv)
target_compile_options(libdc_posix_test PRIVATE -Wpedantic -Wall -Wextra)
target_compile_options(libdc_posix_test PRIVATE -Wdouble-promotion -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wnull-dereference -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wunused-local-typedefs -Wstrict-overflow=5 -Wmissing-noreturn -Walloca -Wfloat-equal -Wdeclaration-after-statement -Wshadow -Wpointer-arith -Wabsolute-value -Wundef -Wexpansion-to-defined -Wunused-macros -Wno-endif-labels -Wbad-function-cast -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wdangling-else -Wdate-time -Wempty-body -Wsign-conversion -Wfloat-conversion -Waggregate-return -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes -Wmissing-declarations -Wredundant-decls -Wnested-externs -Winline -Winvalid-pch -Wlong-long -Wvariadic-macros -Wdisabled-optimization -Wstack-protector -Woverlength-strings)

target_include_directories(libdc_posix_test PRIVATE ../include/dc_posix)
target_include_directories(libdc_posix_test PRIVATE /usr/include)
target_include_directories(libdc_posix_test PRIVATE /usr/local/include)

find_library(LIBCGREEN cgreen REQUIRED)
find_library(LIBDC_ERROR dc_error REQUIRED)
find_library(LIB_RT rt)
find_library(LIB_PTHREAD pthread)
find_library(LIB_CRYPT crypt)
find_library(LIB_GDBM gdbm)
find_library(LIB_GDBM_COMPAT gdbm_compat)

target_link_libraries(libdc_posix_test PRIVATE ${LIBCGREEN})
target_link_libraries(libdc_posix_test PRIVATE ${LIBDC_ERROR})

if(LIB_PTHREAD)
    target_link_libraries(libdc_posix_test PUBLIC ${LIB_PTHREAD})
endif()

if(LIB_RT)
    target_link_libraries(libdc_posix_test PUBLIC ${LIB_RT})
endif()

if(LIB_CRYPT)
    target_link_libraries(libdc_posix_test PUBLIC ${LIB_CRYPT})
endif()

if(LIB_GDBM)
    target_link_libraries(libdc_posix_test PUBLIC ${LIB_GDBM})
endif()

if(LIB_GDBM_COMPAT)
    target_link_libraries(libdc_posix_test PUBLIC ${LIB_GDBM_COMPAT})
endif()

add_test(NAME dc_posix_test COMMAND libdc_posix_test)
