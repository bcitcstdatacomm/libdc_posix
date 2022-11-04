#include "tests.h"
#include "dc_aio.h"

static struct dc_env env;
static struct dc_error err;

Describe(dc_pthread);

BeforeEach(dc_pthread)
{
    dc_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_pthread)
{
}

TestSuite *dc_pthread_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
