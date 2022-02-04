#include "../tests.h"
#include "sys/dc_utsname.h"

static struct dc_posix_env env;
static struct dc_error err;

Describe(dc_sys_utsname);

BeforeEach(dc_sys_utsname)
{
    dc_posix_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_sys_utsname)
{
}

TestSuite *dc_sys_utsname_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
