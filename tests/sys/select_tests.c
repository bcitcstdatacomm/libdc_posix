#include "../tests.h"
#include "sys/dc_select.h"

static struct dc_env env;
static struct dc_error err;

Describe(dc_sys_select);

BeforeEach(dc_sys_select)
{
    dc_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_sys_select)
{
}

TestSuite *dc_sys_select_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
