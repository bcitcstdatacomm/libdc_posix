#include "tests.h"
#include "dc_posix_env.h"


Describe(dc_posix_error);

BeforeEach(dc_posix_error)
{}

AfterEach(dc_posix_error)
{}


Ensure(dc_posix_error, init_tests)
{
    struct dc_error err;
    char *message;

    dc_error_init(&err);
    assert_that(err.file_name, is_null);
    assert_that(err.function_name, is_null);
    assert_that(err.line_number, is_equal_to(0));
    assert_that(err.message, is_null);
    assert_that(err.type, is_equal_to(DC_ERROR_NONE));
    assert_that(err.errno_code, is_equal_to(0));
    assert_that(err.err_code, is_equal_to(0));

    message = malloc(6);
    strcpy(message, "hello");
    err.file_name = __FILE__;
    err.function_name = __func__;
    err.line_number = __LINE__;
    err.message = message;
    err.type = DC_ERROR_USER;
    err.err_code = 1;
    assert_that(err.file_name, is_equal_to_string(__FILE__));
    assert_that(err.function_name, is_equal_to_string(__func__));
    assert_that(err.line_number, is_not_equal_to(0));
    assert_that(err.message, is_equal_to_string("hello"));
    assert_that(err.type, is_equal_to(DC_ERROR_USER));
    assert_that(err.errno_code, is_equal_to(1));
    assert_that(err.err_code, is_equal_to(1));
    free(message);
    message = NULL;

    dc_error_init(&err);
    assert_that(err.file_name, is_null);
    assert_that(err.function_name, is_null);
    assert_that(err.line_number, is_equal_to(0));
    assert_that(err.message, is_null);
    assert_that(err.type, is_equal_to(DC_ERROR_NONE));
    assert_that(err.errno_code, is_equal_to(0));
    assert_that(err.err_code, is_equal_to(0));
}

Ensure(dc_posix_error, reset_tests)
{
}

Ensure(dc_posix_error, errno_tests)
{
}

Ensure(dc_posix_error, system_tests)
{
}

Ensure(dc_posix_error, user_tests)
{
}

TestSuite *dc_error_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();
    add_test_with_context(suite, dc_posix_error, init_tests);
    add_test_with_context(suite, dc_posix_error, reset_tests);
    add_test_with_context(suite, dc_posix_error, errno_tests);
    add_test_with_context(suite, dc_posix_error, system_tests);
    add_test_with_context(suite, dc_posix_error, user_tests);

    return suite;
}
