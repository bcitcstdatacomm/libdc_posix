include_directories(${CGREEN_PUBLIC_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})
add_executable(dc_posix_test main.c posix_env_tests.c posix_error_tests.c string_tests.c tests.h)

target_compile_features(dc_posix_test PRIVATE c_std_11)

target_include_directories(dc_posix_test PRIVATE /usr/include)
target_include_directories(dc_posix_test PRIVATE /usr/local/include)

find_library(LIBDC_POSIX dc_posix REQUIRED)
if(LIBDC_POSIX)
    target_link_libraries(dc_posix_test PRIVATE ${LIBDC_POSIX})
endif()

find_library(LIBCGREEN cgreen REQUIRED)
if(LIBCGREEN)
    target_link_libraries(dc_posix_test PRIVATE ${LIBCGREEN})
endif()

add_test(NAME dc_posix_test COMMAND dc_posix_test) # Command can be a target
