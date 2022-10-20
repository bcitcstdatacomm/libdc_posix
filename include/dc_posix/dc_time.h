#ifndef LIBDC_POSIX_DC_TIME_H
#define LIBDC_POSIX_DC_TIME_H


/*
 * Copyright 2021-2022 D'Arcy Smith.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "dc_posix_env.h"
#include <time.h>
#include <sys/types.h>
#if __has_include(<xlocale.h>)
#include <xlocale.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif

clock_t dc_clock(const struct dc_posix_env *env, struct dc_error *err);
int dc_clock_getres(const struct dc_posix_env *env, struct dc_error *err, clockid_t clock_id, struct timespec *tp);
int dc_clock_gettime(const struct dc_posix_env *env, struct dc_error *err, clockid_t clock_id, struct timespec *tp);
int dc_clock_settime(const struct dc_posix_env *env, struct dc_error *err, clockid_t clock_id, const struct timespec *tp);
double dc_difftime(const struct dc_posix_env *env, time_t time1, time_t time0);
struct tm *dc_gmtime(const struct dc_posix_env *env, struct dc_error *err, const time_t *clock);
struct tm *dc_gmtime_r(const struct dc_posix_env *env, struct dc_error *err, const time_t *clock, struct tm *result);
struct tm *dc_localtime(const struct dc_posix_env *env, struct dc_error *err, const time_t *clock);
struct tm *dc_localtime_r(const struct dc_posix_env *env, struct dc_error *err, const time_t *clock, struct tm	*result);
time_t dc_mktime(const struct dc_posix_env *env, struct dc_error *err, struct tm *tm);


/**
 *
 * @param env
 * @param err
 * @param rqtp
 * @param rmtp
 * @return
 */
int dc_nanosleep(const struct dc_posix_env *env, struct dc_error *err,
                 const struct timespec *rqtp, struct timespec *rmtp);

size_t dc_strftime(const struct dc_posix_env *env, struct dc_error *err, char * restrict buf, size_t maxsize, const char * restrict format, const struct tm * restrict timeptr);
size_t dc_strftime_l(const struct dc_posix_env *env, struct dc_error *err, char *restrict buf, size_t maxsize, const char * restrict format, const struct tm *restrict timeptr, locale_t loc);
char *dc_strptime(const struct dc_posix_env *env, struct dc_error *err, const char * restrict buf, const char * restrict format, struct	tm * restrict timeptr);
time_t dc_time(const struct dc_posix_env *env, struct dc_error *err, time_t *tloc);
void dc_tzset(const struct dc_posix_env *env);


#ifdef __cplusplus
}
#endif


// obselete
// char *asctime(const struct tm *tm);
// char *asctime_r(const struct tm *tm, char *buf);
// char *ctime(const time_t *);
// char *ctime_r(const time_t *, char *);

// Not supported by FreeBSD
// struct tm *getdate(const char *);

// Not supported by macOS
// int dc_timer_create(clockid_t clockid, struct sigevent *restrict evp, timer_t *restrict timerid);
// int dc_timer_delete(timer_t timerid);
// int dc_timer_getoverrun(timer_t timerid);
// int dc_timer_gettime(timer_t timerid, struct itimerspec *value);
// int dc_timer_settime(timer_t timerid, int	flags, const struct itimerspec *restrict value, struct	itimerspec *restrict ovalue);
// int dc_clock_getcpuclockid(const struct dc_posix_env *env, struct dc_error *err, pid_t pid, clockid_t *clock_id);
// int dc_clock_nanosleep(const struct dc_posix_env *env, struct dc_error *err, clockid_t clock_id, int flags, const struct timespec *rqtp, struct timespec *rmtp);

#endif // LIBDC_POSIX_DC_FCNTL_H
