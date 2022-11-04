#include "tests.h"
#include "dc_aio.h"

static struct dc_env env;
static struct dc_error err;

Describe(dc_aio);

BeforeEach(dc_aio)
{
    dc_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_aio)
{
}

TestSuite *dc_aio_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
