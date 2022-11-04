#ifndef LIBDC_POSIX_TESTS_H
#define LIBDC_POSIX_TESTS_H


#include <cgreen/cgreen.h>


TestSuite *dc_arpa_inet_tests(void);
TestSuite *dc_net_if_tests(void);
TestSuite *dc_sys_mman_tests(void);
TestSuite *dc_sys_select_tests(void);
TestSuite *dc_sys_socket_tests(void);
TestSuite *dc_sys_stat_tests(void);
TestSuite *dc_sys_statvfs_tests(void);
TestSuite *dc_sys_times_tests(void);
TestSuite *dc_sys_utsname_tests(void);
TestSuite *dc_sys_wait_tests(void);
TestSuite *dc_aio_tests(void);
TestSuite *dc_dirent_tests(void);
TestSuite *dc_dlfcn_tests(void);
TestSuite *dc_fcntl_tests(void);
TestSuite *dc_fnmatch_tests(void);
TestSuite *dc_glob_tests(void);
TestSuite *dc_grp_tests(void);
TestSuite *dc_iconv_tests(void);
TestSuite *dc_inttypes_tests(void);
TestSuite *dc_langinfo_tests(void);
TestSuite *dc_ndbm_tests(void);
TestSuite *dc_netdb_tests(void);
TestSuite *dc_nl_types_tests(void);
TestSuite *dc_poll_tests(void);
TestSuite *dc_env_tests(void);
TestSuite *dc_pthread_tests(void);
TestSuite *dc_pwd_tests(void);
TestSuite *dc_regex_tests(void);
TestSuite *dc_sched_tests(void);
TestSuite *dc_semaphore_tests(void);
TestSuite *dc_signal_tests(void);
TestSuite *dc_stdio_tests(void);
TestSuite *dc_stdlib_tests(void);
TestSuite *dc_string_tests(void);
TestSuite *dc_strings_tests(void);
TestSuite *dc_termios_tests(void);
TestSuite *dc_time_tests(void);
TestSuite *dc_unistd_tests(void);
TestSuite *dc_wordexp_tests(void);


#endif // LIBDC_POSIX_TESTS_H
