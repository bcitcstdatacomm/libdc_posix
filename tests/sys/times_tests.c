#include "../tests.h"
#include "sys/dc_times.h"

static struct dc_env env;
static struct dc_error err;

Describe(dc_sys_times);

BeforeEach(dc_sys_times)
{
    dc_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_sys_times)
{
}

TestSuite *dc_sys_times_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
