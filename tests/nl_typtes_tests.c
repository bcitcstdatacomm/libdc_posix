#include "tests.h"
#include "dc_aio.h"

static struct dc_env env;
static struct dc_error err;

Describe(dc_nl_types);

BeforeEach(dc_nl_types)
{
    dc_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_nl_types)
{
}

TestSuite *dc_nl_types_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
