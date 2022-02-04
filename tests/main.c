#include "tests.h"


int main(int argc, char **argv)
{
    TestSuite *suite;
    TestReporter *reporter;
    int suite_result;

    suite = create_test_suite();
    reporter = create_text_reporter();

    add_suite(suite, dc_arpa_inet_tests());
    add_suite(suite, dc_net_if_tests());
    add_suite(suite, dc_sys_mman_tests());
    add_suite(suite, dc_sys_select_tests());
    add_suite(suite, dc_sys_socket_tests());
    add_suite(suite, dc_sys_stat_tests());
    add_suite(suite, dc_sys_statvfs_tests());
    add_suite(suite, dc_sys_times_tests());
    add_suite(suite, dc_sys_utsname_tests());
    add_suite(suite, dc_sys_wait_tests());
    add_suite(suite, dc_aio_tests());
    add_suite(suite, dc_dirent_tests());
    add_suite(suite, dc_dlfcn_tests());
    add_suite(suite, dc_fcntl_tests());
    add_suite(suite, dc_fnmatch_tests());
    add_suite(suite, dc_glob_tests());
    add_suite(suite, dc_grp_tests());
    add_suite(suite, dc_iconv_tests());
    add_suite(suite, dc_inttypes_tests());
    add_suite(suite, dc_langinfo_tests());
    add_suite(suite, dc_ndbm_tests());
    add_suite(suite, dc_netdb_tests());
    add_suite(suite, dc_nl_types_tests());
    add_suite(suite, dc_poll_tests());
    add_suite(suite, dc_posix_env_tests());
    add_suite(suite, dc_pthread_tests());
    add_suite(suite, dc_pwd_tests());
    add_suite(suite, dc_regex_tests());
    add_suite(suite, dc_sched_tests());
    add_suite(suite, dc_semaphore_tests());
    add_suite(suite, dc_signal_tests());
    add_suite(suite, dc_stdio_tests());
    add_suite(suite, dc_stdlib_tests());
    add_suite(suite, dc_string_tests());
    add_suite(suite, dc_strings_tests());
    add_suite(suite, dc_termios_tests());
    add_suite(suite, dc_time_tests());
    add_suite(suite, dc_unistd_tests());
    add_suite(suite, dc_wordexp_tests());

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
