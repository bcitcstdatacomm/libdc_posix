#include "tests.h"


Ensure(dc_memcpy_tests)
{
}

Ensure(dc_memset_tests)
{
}

Ensure(dc_strcmp_tests)
{
}

Ensure(dc_strncmp_tests)
{
}

Ensure(dc_strcpy_tests)
{
}

Ensure(dc_strlen_tests)
{
}

Ensure(dc_strtok_r_tests)
{
}

TestSuite *dc_string_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();
    add_test(suite, dc_memcpy_tests);
    add_test(suite, dc_memset_tests);
    add_test(suite, dc_strcmp_tests);
    add_test(suite, dc_strncmp_tests);
    add_test(suite, dc_strcpy_tests);
    add_test(suite, dc_strlen_tests);
    add_test(suite, dc_strtok_r_tests);

    return suite;
}
