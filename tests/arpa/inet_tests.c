#include "../tests.h"
#include "arpa/dc_inet.h"

static struct dc_posix_env env;
static struct dc_error err;

Describe(dc_arpa_inet);

BeforeEach(dc_arpa_inet)
{
    dc_posix_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_arpa_inet)
{
}

TestSuite *dc_arpa_inet_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
