#include "tests.h"
#include "string.h"

struct dc_posix_env env;
struct dc_error err;

Describe(dc_posix_string);

BeforeEach(dc_posix_string)
{
    dc_posix_env_init(&env, NULL);
    dc_error_init(&err);
}

AfterEach(dc_posix_string) {}

Ensure(dc_posix_string, dc_memcpy_tests)
{
}

Ensure(dc_posix_string, dc_memset_tests)
{
}

Ensure(dc_posix_string, dc_strcmp_tests)
{
}

Ensure(dc_posix_string, dc_strncmp_tests)
{
}

Ensure(dc_posix_string, dc_strcpy_tests)
{
}

Ensure(dc_posix_string, dc_strlen_tests)
{
    const char *values[] =
            {
                "",
                "A",
                "hello, world",
                "123",
                "!",
                "HI"
            };

    for(size_t i = 0; i < sizeof(values) / sizeof(char *); i++)
    {
        const char *value;

        value = values[i];
        assert_that(dc_strlen(&env, value), is_equal_to(strlen(value)));
    }
}

Ensure(dc_posix_string, dc_strtok_r_tests)
{
}

TestSuite *dc_string_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();
    add_test_with_context(suite, dc_posix_string, dc_memcpy_tests);
    add_test_with_context(suite, dc_posix_string, dc_memset_tests);
    add_test_with_context(suite, dc_posix_string, dc_strcmp_tests);
    add_test_with_context(suite, dc_posix_string, dc_strncmp_tests);
    add_test_with_context(suite, dc_posix_string, dc_strcpy_tests);
    add_test_with_context(suite, dc_posix_string, dc_strlen_tests);
    add_test_with_context(suite, dc_posix_string, dc_strtok_r_tests);

    return suite;
}
