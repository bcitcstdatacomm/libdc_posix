#include "../tests.h"
#include "sys/dc_socket.h"

static struct dc_env env;
static struct dc_error err;

Describe(dc_sys_socket);

BeforeEach(dc_sys_socket)
{
    dc_env_init(&env, NULL);
    dc_error_init(&err, NULL);
}

AfterEach(dc_sys_socket)
{
}

TestSuite *dc_sys_socket_tests(void)
{
    TestSuite *suite;

    suite = create_test_suite();

    return suite;
}
