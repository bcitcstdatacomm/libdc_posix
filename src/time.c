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


#include "dc_posix/dc_posix_env.h"
#include "dc_posix/dc_time.h"


clock_t dc_clock(const struct dc_posix_env *env, struct dc_error *err)
{
    clock_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = clock();

    if(ret_val == (clock_t)-1)
    {
        // TODO: what is a sensible message/code?
        DC_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}

int dc_clock_getres(const struct dc_posix_env *env, struct dc_error *err, clockid_t clock_id, struct timespec *tp)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = clock_getres(clock_id, tp);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_clock_gettime(const struct dc_posix_env *env, struct dc_error *err, clockid_t clock_id, struct timespec *tp)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = clock_gettime(clock_id, tp);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_clock_settime(const struct dc_posix_env *env, struct dc_error *err, clockid_t clock_id, const struct timespec *tp)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = clock_settime(clock_id, tp);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

double dc_difftime(const struct dc_posix_env *env, time_t time1, time_t time0)
{
    double ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = difftime(time1, time0);

    return ret_val;
}

struct tm *dc_gmtime(const struct dc_posix_env *env, struct dc_error *err, const time_t *clock)
{
    struct tm *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = gmtime(clock);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

struct tm *dc_gmtime_r(const struct dc_posix_env *env, struct dc_error *err, const time_t *clock, struct tm *result)
{
    struct tm *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = gmtime_r(clock, result);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

struct tm *dc_localtime(const struct dc_posix_env *env, struct dc_error *err, const time_t *clock)
{
    struct tm *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = localtime(clock);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

struct tm *dc_localtime_r(const struct dc_posix_env *env, struct dc_error *err, const time_t *clock, struct tm	*result)
{
    struct tm *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = localtime_r(clock, result);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

time_t dc_mktime(const struct dc_posix_env *env, struct dc_error *err, struct tm *tm)
{
    time_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = mktime(tm);

    if(ret_val == (time_t)-1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_nanosleep(const struct dc_posix_env *env,
                 struct dc_error           *err,
                 const struct timespec     *rqtp,
                 struct timespec           *rmtp)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = nanosleep(rqtp, rmtp);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t dc_strftime(const struct dc_posix_env *env, struct dc_error *err, char * restrict buf, size_t maxsize, const char * restrict format, const struct tm * restrict timeptr)
{
    size_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strftime(buf, maxsize, format, timeptr);

    if(ret_val == 0)
    {
        // TODO: what is a sensible message/code?
        DC_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}

size_t dc_strftime_l(const struct dc_posix_env *env, struct dc_error *err, char *restrict buf, size_t maxsize, const char * restrict format, const struct tm *restrict timeptr, locale_t loc)
{
    size_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strftime_l(buf, maxsize, format, timeptr, loc);

    if(ret_val == 0)
    {
        // TODO: what is a sensible message/code?
        DC_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}

char *dc_strptime(const struct dc_posix_env *env, struct dc_error *err, const char * restrict buf, const char * restrict format, struct	tm * restrict timeptr)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strptime(buf, format, timeptr);

    if(ret_val == NULL)
    {
        // TODO: what is a sensible message/code?
        DC_ERROR_RAISE_SYSTEM(err, "", 0);
    }

    return ret_val;
}

time_t dc_time(const struct dc_posix_env *env, struct dc_error *err, time_t *tloc)
{
    time_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = time(tloc);

    if(ret_val == (time_t)-1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

void dc_tzset(const struct dc_posix_env *env)
{
    DC_TRACE(env);
    errno   = 0;
    tzset();
}
