#include "tests.h"
#include "dc_aio.h"

static struct dc_posix_env env;
static struct dc_error err;

Describe(dc_time);

BeforeEach(dc_time)
{
    dc_posix_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_time)
{
}

TestSuite *dc_time_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
