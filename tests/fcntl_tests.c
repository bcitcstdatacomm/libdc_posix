#include "tests.h"
#include "dc_fcntl.h"

static struct dc_posix_env env;
static struct dc_error err;

Describe(dc_fcntl);

BeforeEach(dc_fcntl)
{
    dc_posix_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_fcntl)
{
}

TestSuite *dc_fcntl_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
