include_directories(${CGREEN_PUBLIC_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})
add_executable(dc_posix_test
        ${SOURCE_LIST} ${HEADER_LIST} ${HEADER_SYS_LIST}
        main.c posix_env_tests.c posix_error_tests.c string_tests.c tests.h)

target_compile_features(dc_posix_test PRIVATE c_std_11)
target_compile_options(dc_posix_test PRIVATE -iquote "${libdc_posix_SOURCE_DIR}/include/dc_posix")
target_compile_options(dc_posix_test PRIVATE -g)
target_compile_options(dc_posix_test PRIVATE -fstack-protector-all -ftrapv)
target_compile_options(dc_posix_test PRIVATE -Wpedantic -Wall -Wextra)
target_compile_options(dc_posix_test PRIVATE -Wdouble-promotion -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wnull-dereference -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wunused-local-typedefs -Wstrict-overflow=5 -Wmissing-noreturn -Walloca -Wfloat-equal -Wdeclaration-after-statement -Wshadow -Wpointer-arith -Wabsolute-value -Wundef -Wexpansion-to-defined -Wunused-macros -Wno-endif-labels -Wbad-function-cast -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wdangling-else -Wdate-time -Wempty-body -Wsign-conversion -Wfloat-conversion -Waggregate-return -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes -Wmissing-declarations -Wredundant-decls -Wnested-externs -Winline -Winvalid-pch -Wlong-long -Wvariadic-macros -Wdisabled-optimization -Wstack-protector -Woverlength-strings)

target_include_directories(dc_posix_test PRIVATE /usr/include)
target_include_directories(dc_posix_test PRIVATE /usr/local/include)

find_library(LIBCGREEN cgreen REQUIRED)
if (LIBCGREEN)
    target_link_libraries(dc_posix_test PRIVATE ${LIBCGREEN})
endif ()

add_test(NAME dc_posix_test COMMAND dc_posix_test) # Command can be a target
