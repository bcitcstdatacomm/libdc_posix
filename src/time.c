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


#include "dc_posix/dc_time.h"


int dc_clock_getres(const struct dc_env *env, struct dc_error *err, clockid_t clock_id, struct timespec *res)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = clock_getres(clock_id, res);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_clock_gettime(const struct dc_env *env, struct dc_error *err, clockid_t clock_id, struct timespec *tp)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = clock_gettime(clock_id, tp);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_clock_settime(const struct dc_env *env, struct dc_error *err, clockid_t clock_id, const struct timespec *tp)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = clock_settime(clock_id, tp);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

struct tm *dc_gmtime_r(const struct dc_env *env, struct dc_error *err, const time_t *restrict timer, struct tm *restrict result)
{
    struct tm *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = gmtime_r(timer, result);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

struct tm *dc_localtime_r(const struct dc_env *env, struct dc_error *err, const time_t *restrict timer, struct tm *restrict result)
{
    struct tm *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = localtime_r(timer, result);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_nanosleep(const struct dc_env *env, struct dc_error *err, const struct timespec *rqtp, struct timespec *rmtp)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = nanosleep(rqtp, rmtp);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t dc_strftime_l(const struct dc_env *env,char *restrict s, size_t maxsize, const char *restrict format, const struct tm *restrict timeptr, locale_t locale)
{
    size_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = strftime_l(s, maxsize, format, timeptr, locale);

    return ret_val;
}

void dc_tzset(const struct dc_env *env)
{
    DC_TRACE(env);
    errno = 0;
    tzset();
}
