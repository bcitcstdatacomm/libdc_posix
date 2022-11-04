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


#include <dc_env/env.h>
#include <time.h>

#ifdef __APPLE__
    #include <xlocale.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif


int dc_clock_getres(const struct dc_env *env, struct dc_error *err, clockid_t clock_id, struct timespec *res);
int dc_clock_gettime(const struct dc_env *env, struct dc_error *err, clockid_t clock_id, struct timespec *tp);
int dc_clock_settime(const struct dc_env *env, struct dc_error *err, clockid_t clock_id, const struct timespec *tp);
struct tm *dc_gmtime_r(const struct dc_env *env, struct dc_error *err, const time_t *restrict timer, struct tm *restrict result);
struct tm *dc_localtime_r(const struct dc_env *env, struct dc_error *err, const time_t *restrict timer, struct tm *restrict result);
int dc_nanosleep(const struct dc_env *env, struct dc_error *err, const struct timespec *rqtp, struct timespec *rmtp);
size_t dc_strftime_l(const struct dc_env *env, char *restrict s, size_t maxsize, const char *restrict format, const struct tm *restrict timeptr, locale_t locale);
void dc_tzset(const struct dc_env *env);


#ifdef __cplusplus
}
#endif


// not on macOS
// int dc_timer_create(const struct dc_env *env, struct dc_error *err, clockid_t clockid, struct sigevent *restrict evp, timer_t *restrict timerid);
// int dc_timer_delete(const struct dc_env *env, struct dc_error *err, timer_t timerid);
// int dc_timer_getoverrun(const struct dc_env *env, struct dc_error *err, timer_t timerid);
// int dc_timer_gettime(const struct dc_env *env, struct dc_error *err, timer_t timerid, struct itimerspec *value);
// int dc_timer_settime(const struct dc_env *env, struct dc_error *err, timer_t timerid, int flags, const struct itimerspec *restrict value, struct itimerspec *restrict ovalue);
// int dc_clock_nanosleep(const struct dc_env *env, struct dc_error *err, clockid_t clock_id, int flags, const struct timespec *rqtp, struct timespec *rmtp);


#endif // LIBDC_POSIX_DC_TIME_H
