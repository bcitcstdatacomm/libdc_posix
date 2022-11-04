#include "../tests.h"
#include "sys/dc_statvfs.h"

static struct dc_env env;
static struct dc_error err;

Describe(dc_sys_statvfs);

BeforeEach(dc_sys_statvfs)
{
    dc_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_sys_statvfs)
{
}

TestSuite *dc_sys_statvfs_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
