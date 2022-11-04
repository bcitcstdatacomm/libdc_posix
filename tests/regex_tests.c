#include "tests.h"
#include "dc_aio.h"

static struct dc_env env;
static struct dc_error err;

Describe(dc_regex);

BeforeEach(dc_regex)
{
    dc_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_regex)
{
}

TestSuite *dc_regex_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
