cmake_minimum_required(VERSION 3.22)

project(dc_posix
        VERSION 0.2.1
        DESCRIPTION ""
        LANGUAGES C)

set(CMAKE_C_STANDARD 17)

if (DEFINED ENV{DC_BUILD_SANITIZE})
    set(SANITIZE $ENV{DC_BUILD_SANITIZE})
else ()
    set(SANITIZE FALSE)
endif ()

set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

set(SOURCE_LIST ${SOURCE_DIR}/ ${SOURCE_DIR}/aio.c
        ${SOURCE_DIR}/ctype.c
        ${SOURCE_DIR}/dirent.c
        ${SOURCE_DIR}/dlfcn.c
        ${SOURCE_DIR}/fcntl.c
        ${SOURCE_DIR}/fnmatch.c
        ${SOURCE_DIR}/glob.c
        ${SOURCE_DIR}/grp.c
        ${SOURCE_DIR}/iconv.c
        ${SOURCE_DIR}/langinfo.c
        ${SOURCE_DIR}/locale.c
        ${SOURCE_DIR}/netdb.c
        ${SOURCE_DIR}/nl_types.c
        ${SOURCE_DIR}/poll.c
        ${SOURCE_DIR}/pthread.c
        ${SOURCE_DIR}/pwd.c
        ${SOURCE_DIR}/regex.c
        ${SOURCE_DIR}/sched.c
        ${SOURCE_DIR}/semaphore.c
        ${SOURCE_DIR}/setjmp.c
        ${SOURCE_DIR}/signal.c
        ${SOURCE_DIR}/stdio.c
        ${SOURCE_DIR}/stdlib.c
        ${SOURCE_DIR}/string.c
        ${SOURCE_DIR}/strings.c
        ${SOURCE_DIR}/termios.c
        ${SOURCE_DIR}/time.c
        ${SOURCE_DIR}/unistd.c
        ${SOURCE_DIR}/utime.c
        ${SOURCE_DIR}/wchar.c
        ${SOURCE_DIR}/wctype.c
        ${SOURCE_DIR}/wordexp.c
        ${SOURCE_DIR}/arpa/inet.c
        ${SOURCE_DIR}/net/if.c
        ${SOURCE_DIR}/sys/mman.c
        ${SOURCE_DIR}/sys/select.c
        ${SOURCE_DIR}/sys/socket.c
        ${SOURCE_DIR}/sys/stat.c
        ${SOURCE_DIR}/sys/statvfs.c
        ${SOURCE_DIR}/sys/times.c
        ${SOURCE_DIR}/sys/utsname.c
        ${SOURCE_DIR}/sys/wait.c
        )
set(HEADER_LIST ${INCLUDE_DIR}/dc_posix/dc_aio.h
        ${INCLUDE_DIR}/dc_posix/dc_ctype.h
        ${INCLUDE_DIR}/dc_posix/dc_dirent.h
        ${INCLUDE_DIR}/dc_posix/dc_dlfcn.h
        ${INCLUDE_DIR}/dc_posix/dc_fcntl.h
        ${INCLUDE_DIR}/dc_posix/dc_fnmatch.h
        ${INCLUDE_DIR}/dc_posix/dc_glob.h
        ${INCLUDE_DIR}/dc_posix/dc_grp.h
        ${INCLUDE_DIR}/dc_posix/dc_iconv.h
        ${INCLUDE_DIR}/dc_posix/dc_langinfo.h
        ${INCLUDE_DIR}/dc_posix/dc_locale.h
        ${INCLUDE_DIR}/dc_posix/dc_netdb.h
        ${INCLUDE_DIR}/dc_posix/dc_nl_types.h
        ${INCLUDE_DIR}/dc_posix/dc_poll.h
        ${INCLUDE_DIR}/dc_posix/dc_pthread.h
        ${INCLUDE_DIR}/dc_posix/dc_pwd.h
        ${INCLUDE_DIR}/dc_posix/dc_regex.h
        ${INCLUDE_DIR}/dc_posix/dc_sched.h
        ${INCLUDE_DIR}/dc_posix/dc_semaphore.h
        ${INCLUDE_DIR}/dc_posix/dc_setjmp.h
        ${INCLUDE_DIR}/dc_posix/dc_signal.h
        ${INCLUDE_DIR}/dc_posix/dc_stdio.h
        ${INCLUDE_DIR}/dc_posix/dc_stdlib.h
        ${INCLUDE_DIR}/dc_posix/dc_string.h
        ${INCLUDE_DIR}/dc_posix/dc_strings.h
        ${INCLUDE_DIR}/dc_posix/dc_termios.h
        ${INCLUDE_DIR}/dc_posix/dc_time.h
        ${INCLUDE_DIR}/dc_posix/dc_unistd.h
        ${INCLUDE_DIR}/dc_posix/dc_utime.h
        ${INCLUDE_DIR}/dc_posix/dc_wchar.h
        ${INCLUDE_DIR}/dc_posix/dc_wctype.h
        ${INCLUDE_DIR}/dc_posix/dc_ctype.h
        ${INCLUDE_DIR}/dc_posix/dc_wordexp.h
    )
set(HEADER_LIST_ARPA ${INCLUDE_DIR}/dc_posix/arpa/dc_inet.h)

set(HEADER_LIST_NET ${INCLUDE_DIR}/dc_posix/net/dc_if.h)

set(HEADER_LIST_SYS ${INCLUDE_DIR}/dc_posix/sys/dc_mman.h
        ${INCLUDE_DIR}/dc_posix/sys/dc_select.h
        ${INCLUDE_DIR}/dc_posix/sys/dc_socket.h
        ${INCLUDE_DIR}/dc_posix/sys/dc_stat.h
        ${INCLUDE_DIR}/dc_posix/sys/dc_statvfs.h
        ${INCLUDE_DIR}/dc_posix/sys/dc_times.h
        ${INCLUDE_DIR}/dc_posix/sys/dc_utsname.h
        ${INCLUDE_DIR}/dc_posix/sys/dc_wait.h
    )

add_compile_definitions(_POSIX_C_SOURCE=200809L)
add_compile_definitions(_XOPEN_SOURCE=700)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    add_compile_definitions(_DARWIN_C_SOURCE)
endif ()

include_directories(${INCLUDE_DIR})
include(CheckCCompilerFlag)

function(AddCompileOptions)
    foreach(FLAG IN LISTS ARGN)
        string(REPLACE "-" "" FLAG_NO_HYPHEN ${FLAG})
        # set(CMAKE_C_FLAGS "-Werror -Wunknown-warning-option")
        check_c_compiler_flag(${FLAG} COMPILER_SUPPORTS_${FLAG_NO_HYPHEN})
        if (COMPILER_SUPPORTS_${FLAG_NO_HYPHEN})
            add_compile_options(${FLAG})
        endif ()
    endforeach()
endfunction()

list(APPEND COMPILER_FLAGS
        "-Wall"
        "-Wextra"
        "-Wpedantic"
        "-Wshadow"
        "-Wstrict-overflow=4"
        "-Wswitch-default"
        "-Wswitch-enum"
        "-Wunused"
        "-Wunused-macros"
        "-Wdate-time"
        "-Winvalid-pch"
        "-Wmissing-declarations"
        "-Wmissing-include-dirs"
        "-Wmissing-prototypes"
        "-Wstrict-prototypes"
        "-Wundef"
        "-Wnull-dereference"
        "-Wstack-protector"
        "-Wdouble-promotion"
        "-Wvla"
        "-Walloca"
        "-Woverlength-strings"
        "-Wdisabled-optimization"
        "-Winline"
        "-Wcast-qual"
        "-Wfloat-equal"
        "-Wformat=2"
        "-Wfree-nonheap-object"
        "-Wshift-overflow"
        "-Wwrite-strings"
        "-Wunsuffixed-float-constants"
        "-Warith-conversion"
        "-Wunsafe-loop-optimizations"
        "-Wvector-operation-performance"
        "-Walloc-zero"
        "-Wtrampolines"
        "-Wtsan"
        "-Wformat-overflow=2"
        "-Wformat-signedness"
        "-Wjump-misses-init"
        "-Wformat-truncation=2")

if (${SANITIZE})
    list(APPEND COMPILER_FLAGS
            "-fsanitize=pointer-compare"
            "-fsanitize=pointer-subtract"
            "-fsanitize=undefined"
            "-fsanitize-address-use-after-scope"
            "-fcf-protection=full"
            ##            "-fharden-compares"
            ##            "-fharden-conditional-branches"
            "-fharden-control-flow-redundancy"
            "-fstack-protector=all"
            ##            "-fstack-check"
            ##            "-fstack-clash-protection"
            "-finstrument-functions"
            "-fsanitize=leak"
            "-fno-delete-null-pointer-checks"
            "-fno-omit-frame-pointer"
            )

    add_compile_options("-fsanitize=address")
    add_link_options("-fsanitize=address")
    add_link_options("-fsanitize=bounds")
endif ()


AddCompileOptions(${COMPILER_FLAGS})

find_package(Doxygen
        REQUIRED
        REQUIRED dot
        OPTIONAL_COMPONENTS mscgen dia)

set(DOXYGEN_ALWAYS_DETAILED_SEC YES)
set(DOXYGEN_REPEAT_BRIEF YES)
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_WARNINGS YES)
set(DOXYGEN_QUIET YES)

doxygen_add_docs(doxygen
        ${HEADER_LIST}
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        COMMENT "Generating Doxygen documentation for libdc_posix")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CLANG_TIDY_CHECKS "*")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-altera-id-dependent-backward-branch")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-altera-struct-pack-align")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-altera-unroll-loops")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-android-cloexec-accept")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-android-cloexec-creat")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-android-cloexec-dup")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-android-cloexec-open")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-android-cloexec-pipe")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-android-cloexec-socket")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-bugprone-easily-swappable-parameters")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-cert-dcl03-c")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-analyzer-deadcode.DeadStores")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-analyzer-security.insecureAPI.strcpy")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-cast-align")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-format-nonliteral")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-incompatible-pointer-types-discards-qualifiers")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-unknown-warning-option")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-unused-but-set-variable")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-unused-function")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-unused-parameter")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-unused-variable")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-clang-diagnostic-vla")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-cppcoreguidelines-init-variables")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-google-readability-todo")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-hicpp-static-assert")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-llvmlibc-restrict-system-libc-headers")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-misc-static-assert")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-misc-unused-parameters")
set(CLANG_TIDY_CHECKS "${CLANG_TIDY_CHECKS},-readability-identifier-length")

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    if (NOT DEFINED ENV{CMDLINE_TOOLS_VER})
        message( FATAL_ERROR "The CMDLINE_TOOLS_VER environment variable must be set" )
    endif ()

    if(NOT EXISTS /Library/Developer/CommandLineTools/usr/lib/clang/$ENV{CMDLINE_TOOLS_VER})
        message( FATAL_ERROR "/Library/Developer/CommandLineTools/usr/lib/clang/$ENV{CMDLINE_TOOLS_VER} does not exist" )
    endif ()

    set(CMAKE_C_CLANG_TIDY clang-tidy -extra-arg=-I/Library/Developer/CommandLineTools/usr/lib/clang/$ENV{CMDLINE_TOOLS_VER}/include -checks=${CLANG_TIDY_CHECKS};--quiet)
else ()
    set(CMAKE_C_CLANG_TIDY clang-tidy -checks=${CLANG_TIDY_CHECKS};--quiet)
endif ()

add_library(dc_posix SHARED ${SOURCE_LIST} ${HEADER_LIST})
target_include_directories(dc_posix PRIVATE include/dc_posix)
target_include_directories(dc_posix PRIVATE /usr/local/include)
target_link_directories(dc_posix PRIVATE /usr/local/lib)

if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_include_directories(dc_posix PRIVATE /usr/include)
endif ()

set_target_properties(dc_posix PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR})

find_library(LIBDC_ERROR dc_error REQUIRED)
find_library(LIBDC_ENV dc_env REQUIRED)
find_library(LIBDC_C dc_c REQUIRED)
find_library(LIBICONV iconv)
find_library(LIBDL dl)
find_library(LIBRT rt)
find_library(LIBPTHREAD pthread)

target_link_libraries(dc_posix PUBLIC ${LIBDC_ERROR})
target_link_libraries(dc_posix PUBLIC ${LIBDC_ENV})
target_link_libraries(dc_posix PUBLIC ${LIBDC_C})

if(LIBICONV)
    target_link_libraries(dc_posix PUBLIC ${LIBICONV})
endif()

if(LIBDL)
    target_link_libraries(dc_posix PUBLIC ${LIBDL})
endif()

if(LIBRT)
    target_link_libraries(dc_posix PUBLIC ${LIBRT})
endif()

if(LIBPTHREAD)
    target_link_libraries(dc_posix PUBLIC ${LIBPTHREAD})
endif()

install(TARGETS dc_posix LIBRARY DESTINATION lib)
install(FILES ${HEADER_LIST} DESTINATION include/dc_posix)
install(FILES ${HEADER_LIST_ARPA} DESTINATION include/dc_posix/arpa)
install(FILES ${HEADER_LIST_NET} DESTINATION include/dc_posix/net)
install(FILES ${HEADER_LIST_SYS} DESTINATION include/dc_posix/sys)

add_dependencies(dc_posix doxygen)

find_library(LIBCGREEN cgreen REQUIRED)
add_subdirectory(tests)
