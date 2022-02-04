#include "tests.h"
#include "dc_dlfcn.h"

static struct dc_posix_env env;
static struct dc_error err;

Describe(dc_dlfcn);

BeforeEach(dc_dlfcn)
{
    dc_posix_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_dlfcn)
{
}

TestSuite *dc_dlfcn_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
