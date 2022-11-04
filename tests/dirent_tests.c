#include "tests.h"
#include "dc_dirent.h"

static struct dc_env env;
static struct dc_error err;

Describe(dc_dirent);

BeforeEach(dc_dirent)
{
    dc_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_dirent)
{
}

TestSuite *dc_dirent_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
