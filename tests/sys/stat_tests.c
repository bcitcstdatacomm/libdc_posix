#include "../tests.h"
#include "sys/dc_stat.h"

static struct dc_env env;
static struct dc_error err;

Describe(dc_sys_stat);

BeforeEach(dc_sys_stat)
{
    dc_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_sys_stat)
{
}

TestSuite *dc_sys_stat_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
