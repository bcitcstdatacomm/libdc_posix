#include "tests.h"
#include "dc_aio.h"

static struct dc_env env;
static struct dc_error err;

Describe(dc_wordexp);

BeforeEach(dc_wordexp)
{
    dc_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_wordexp)
{
}

TestSuite *dc_wordexp_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
