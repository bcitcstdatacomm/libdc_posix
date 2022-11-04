#include "../tests.h"
#include "sys/dc_wait.h"

static struct dc_env env;
static struct dc_error err;

Describe(dc_sys_wait);

BeforeEach(dc_sys_wait)
{
    dc_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_sys_wait)
{
}

TestSuite *dc_sys_wait_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
