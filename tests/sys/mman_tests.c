#include "../tests.h"
#include "sys/dc_mman.h"

static struct dc_posix_env env;
static struct dc_error err;

Describe(dc_sys_mman);

BeforeEach(dc_sys_mman)
{
    dc_posix_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_sys_mman)
{
}

TestSuite *dc_sys_mman_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
