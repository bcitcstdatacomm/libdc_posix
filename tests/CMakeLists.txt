add_compile_definitions(_POSIX_C_SOURCE=200809L _XOPEN_SOURCE=700)

if (APPLE)
    add_definitions(-D_DARWIN_C_SOURCE)
endif ()

set(TEST_HEADER_LIST
        tests.h
        )

set(TEST_SOURCE_LIST
        main.c
        arpa/inet_tests.c
        net/if_tests.c
        sys/mman_tests.c
        sys/select_tests.c
        sys/socket_tests.c
        sys/stat_tests.c
        sys/statvfs_tests.c
        sys/times_tests.c
        sys/utsname_tests.c
        sys/wait_tests.c
        aio_tests.c
        dirent_tests.c
        dlfcn_tests.c
        fcntl_tests.c
        fnmatch_tests.c
        glob_tests.c
        grp_tests.c
        iconv_tests.c
        inttypes_tests.c
        langinfo_tests.c
        ndbm_tests.c
        netdb_tests.c
        nl_typtes_tests.c
        poll_tests.c
        posix_env_tests.c
        pthread_tests.c
        pwd_tests.c
        regex_tests.c
        sched_tests.c
        semaphore_tests.c
        signal_tests.c
        stdio_tests.c
        stdlib_tests.c
        string_tests.c
        strings_tests.c
        termios_tests.c
        time_tests.c
        unistd_tests.c
        wordexp_tests.c
        )

include_directories(${CGREEN_PUBLIC_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})
add_executable(libdc_posix_test
        ${TEST_SOURCE_LIST} ${TEST_HEADER_LIST} ${SOURCE_LIST} ${HEADER_LIST} ${HEADER_SYS_LIST} ${HEADER_ARPA_LIST} ${HEADER_NET_LIST})

target_compile_features(libdc_posix_test PRIVATE c_std_17)
target_compile_options(libdc_posix_test PRIVATE -g)

target_include_directories(libdc_posix_test PRIVATE ../include/dc_posix)
target_include_directories(libdc_posix_test PRIVATE /usr/include)
target_include_directories(libdc_posix_test PRIVATE /usr/local/include)

find_library(LIBCGREEN cgreen REQUIRED)
find_library(LIBDC_ERROR dc_error REQUIRED)
find_library(LIB_CRYPT crypt)
find_library(LIB_DL dl)
find_library(LIB_GDBM gdbm)
find_library(LIB_GDBM_COMPAT gdbm_compat)
find_library(LIB_ICONV iconv)
find_library(LIB_PTHREAD pthread)
find_library(LIB_RT rt)

target_link_libraries(libdc_posix_test PRIVATE ${LIBCGREEN})
target_link_libraries(libdc_posix_test PRIVATE ${LIBDC_ERROR})

if(LIB_CRYPT)
    target_link_libraries(libdc_posix_test PUBLIC ${LIB_CRYPT})
endif()

if(LIB_DL)
    target_link_libraries(libdc_posix_test PUBLIC ${LIB_DL})
endif()

if(LIB_GDBM)
    target_link_libraries(libdc_posix_test PUBLIC ${LIB_GDBM})
endif()

if(LIB_GDBM_COMPAT)
    target_link_libraries(libdc_posix_test PUBLIC ${LIB_GDBM_COMPAT})
endif()

if(LIB_ICONV)
    target_link_libraries(libdc_posix_test PUBLIC ${LIB_ICONV})
endif()

if(LIB_PTHREAD)
    target_link_libraries(libdc_posix_test PUBLIC ${LIB_PTHREAD})
endif()

if(LIB_RT)
    target_link_libraries(libdc_posix_test PUBLIC ${LIB_RT})
endif()

add_test(NAME dc_posix_test COMMAND libdc_posix_test)
