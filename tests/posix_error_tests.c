#include "tests.h"


Describe(dc_posix_error);
BeforeEach(dc_posix_error) {}
AfterEach(dc_posix_error) {}


Ensure(dc_posix_error, init_tests)
{
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
