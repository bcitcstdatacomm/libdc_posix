#include "tests.h"
#include "dc_aio.h"

static struct dc_env env;
static struct dc_error err;

Describe(dc_ndbm);

BeforeEach(dc_ndbm)
{
    dc_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_ndbm)
{
}

TestSuite *dc_ndbm_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
