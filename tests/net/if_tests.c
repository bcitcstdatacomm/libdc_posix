#include "../tests.h"
#include "net/dc_if.h"

static struct dc_posix_env env;
static struct dc_error err;

Describe(dc_net_if);

BeforeEach(dc_net_if)
{
    dc_posix_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_net_if)
{
}

TestSuite *dc_net_if_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
