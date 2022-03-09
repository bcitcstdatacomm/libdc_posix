# https://gitlab.com/CLIUtils/modern-cmake/-/blob/master/examples/extended-project/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

# Project name and a few useful settings. Other commands can pick up the results
project(libdc_posix
        VERSION 0.1.0.0
        HOMEPAGE_URL "https://github.com/bcitcstdatacomm/libdc_posix"
        DESCRIPTION ""
        LANGUAGES C)

set(HEADER_LIST
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_posix_env.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_aio.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_dirent.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_dlfcn.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_fcntl.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_fnmatch.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_glob.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_grp.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_iconv.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_inttypes.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_langinfo.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_ndbm.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_netdb.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_nl_types.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_poll.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_pthread.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_pwd.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_regex.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_sched.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_semaphore.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_signal.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_stdio.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_stdlib.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_string.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_strings.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_termios.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_time.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_unistd.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/dc_wordexp.h"
        )

set(HEADER_SYS_LIST
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/sys/dc_ipc.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/sys/dc_mman.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/sys/dc_msg.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/sys/dc_select.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/sys/dc_socket.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/sys/dc_stat.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/sys/dc_statvfs.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/sys/dc_times.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/sys/dc_utsname.h"
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/sys/dc_wait.h"
        )

set(HEADER_ARPA_LIST
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/arpa/dc_inet.h"
        )

set(HEADER_NET_LIST
        "${libdc_posix_SOURCE_DIR}/include/dc_posix/net/dc_if.h"
        )

set(SOURCE_LIST
        "${libdc_posix_SOURCE_DIR}/src/aio.c"
        "${libdc_posix_SOURCE_DIR}/src/dirent.c"
        "${libdc_posix_SOURCE_DIR}/src/dlfcn.c"
        "${libdc_posix_SOURCE_DIR}/src/fcntl.c"
        "${libdc_posix_SOURCE_DIR}/src/fnmatch.c"
        "${libdc_posix_SOURCE_DIR}/src/glob.c"
        "${libdc_posix_SOURCE_DIR}/src/grp.c"
        "${libdc_posix_SOURCE_DIR}/src/iconv.c"
        "${libdc_posix_SOURCE_DIR}/src/inttypes.c"
        "${libdc_posix_SOURCE_DIR}/src/langinfo.c"
        "${libdc_posix_SOURCE_DIR}/src/ndbm.c"
        "${libdc_posix_SOURCE_DIR}/src/netdb.c"
        "${libdc_posix_SOURCE_DIR}/src/nl_types.c"
        "${libdc_posix_SOURCE_DIR}/src/poll.c"
        "${libdc_posix_SOURCE_DIR}/src/posix_env.c"
        "${libdc_posix_SOURCE_DIR}/src/pthread.c"
        "${libdc_posix_SOURCE_DIR}/src/pwd.c"
        "${libdc_posix_SOURCE_DIR}/src/regex.c"
        "${libdc_posix_SOURCE_DIR}/src/sched.c"
        "${libdc_posix_SOURCE_DIR}/src/semaphore.c"
        "${libdc_posix_SOURCE_DIR}/src/signal.c"
        "${libdc_posix_SOURCE_DIR}/src/stdio.c"
        "${libdc_posix_SOURCE_DIR}/src/stdlib.c"
        "${libdc_posix_SOURCE_DIR}/src/string.c"
        "${libdc_posix_SOURCE_DIR}/src/strings.c"
        "${libdc_posix_SOURCE_DIR}/src/termios.c"
        "${libdc_posix_SOURCE_DIR}/src/time.c"
        "${libdc_posix_SOURCE_DIR}/src/unistd.c"
        "${libdc_posix_SOURCE_DIR}/src/wordexp.c"
        "${libdc_posix_SOURCE_DIR}/src/arpa/inet.c"
        "${libdc_posix_SOURCE_DIR}/src/net/if.c"
        "${libdc_posix_SOURCE_DIR}/src/sys/ipc.c"
        "${libdc_posix_SOURCE_DIR}/src/sys/mman.c"
        "${libdc_posix_SOURCE_DIR}/src/sys/msg.c"
        "${libdc_posix_SOURCE_DIR}/src/sys/select.c"
        "${libdc_posix_SOURCE_DIR}/src/sys/socket.c"
        "${libdc_posix_SOURCE_DIR}/src/sys/stat.c"
        "${libdc_posix_SOURCE_DIR}/src/sys/statvfs.c"
        "${libdc_posix_SOURCE_DIR}/src/sys/times.c"
        "${libdc_posix_SOURCE_DIR}/src/sys/utsname.c"
        "${libdc_posix_SOURCE_DIR}/src/sys/wait.c"
        )

### Require out-of-source builds
# this still creates a CMakeFiles directory and CMakeCache.txt- can we delete them?
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if (EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif ()

# Only do these if this is the main project, and not if it is included through add_subdirectory
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here

    # Let's ensure -std=c11 instead of -std=g11
    set(CMAKE_C_EXTENSIONS OFF)

    # Make a shared library
    if (APPLE)
        add_definitions(-D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE=700)
    endif ()

    # Let's nicely support folders in IDEs
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)

    # Docs only available if this is the main app
    find_package(Doxygen)
    if (Doxygen_FOUND)
        add_subdirectory(docs)
    else ()
        message(STATUS "Doxygen not found, not building docs")
    endif ()
endif ()

# The compiled library code is here
add_subdirectory(src)

find_library(LIBCGREEN cgreen)

# Testing only available if this is the main app
if ((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) AND BUILD_TESTING AND LIBCGREEN)
    add_subdirectory(tests)
endif ()
