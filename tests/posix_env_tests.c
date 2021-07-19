#include "tests.h"
#include "dc_posix_env.h"


Describe(dc_posix_env);
BeforeEach(dc_posix_env) {}
AfterEach(dc_posix_env) {}

Ensure(dc_posix_env, env_init_tests)
{
    struct dc_posix_env env;

    dc_posix_env_init(&env, NULL);
    assert_that(env.null_free, is_false);
    assert_that(env.zero_free, is_false);
    assert_that(env.tracer, is_null);
    assert_that(env.error_reporter, is_null);

    dc_posix_env_init(&env, NULL);
    assert_that(env.null_free, is_false);
    assert_that(env.zero_free, is_false);
    assert_that(env.tracer, is_null);
    assert_that(env.error_reporter, is_null);
}

static const char *actual_file_name;
static const char *actual_function_name;
static size_t      actual_line_number;


static void tracer(__attribute__ ((unused)) const struct dc_posix_env *env, const char *file_name, const char *function_name, size_t line_number)
{
    actual_file_name     = file_name;
    actual_function_name = function_name;
    actual_line_number   = line_number;
}

Ensure(dc_posix_env, env_trace_tests)
{
    struct dc_posix_env env;
    const char *file_name;
    const char *function_name;
    size_t      line_number;

    dc_posix_env_init(&env, NULL);
    env.tracer    = tracer;
    file_name     = __FILE__;
    function_name = __func__;
    line_number   = __LINE__;
    DC_TRACE(&env);

    assert_that(actual_file_name,     is_equal_to_string(file_name));
    assert_that(actual_function_name, is_equal_to_string(function_name));
    assert_that(actual_line_number,   is_equal_to(line_number + 1)); // need + 1 because DC_TRACE is the real line #
}

TestSuite *dc_env_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();
    add_test_with_context(suite, dc_posix_env, env_init_tests);
    add_test_with_context(suite, dc_posix_env, env_trace_tests);

    return suite;
}
