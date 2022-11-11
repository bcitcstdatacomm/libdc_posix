#include "tests.h"


int main(int argc, char **argv)
{
    TestSuite *suite;
    TestReporter *reporter;
    int suite_result;

    suite = create_test_suite();
    reporter = create_text_reporter();

    if(argc > 1)
    {
        suite_result = run_single_test(suite, argv[1], reporter);
    }
    else
    {
        suite_result = run_test_suite(suite, reporter);
    }

    destroy_test_suite(suite);
    destroy_reporter(reporter);

    return suite_result;
}
