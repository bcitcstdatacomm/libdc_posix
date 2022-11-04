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


#include "dc_posix/dc_string.h"


char *dc_stpcpy(const struct dc_env *env, char *restrict s1, const char *restrict s2)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = stpcpy(s1, s2);

    return ret_val;
}

char *dc_stpncpy(const struct dc_env *env, char *restrict s1, const char *restrict s2, size_t n)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = stpncpy(s1, s2, n);

    return ret_val;
}

int dc_strcoll_l(const struct dc_env *env, struct dc_error *err, const char *s1, const char *s2, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = strcoll_l(s1, s2, locale);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_strdup(const struct dc_env *env, struct dc_error *err, const char *s)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = strdup(s);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_strerror_l(const struct dc_env *env, struct dc_error *err, int errnum, locale_t locale)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = strerror_l(errnum, locale);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_strerror_r(const struct dc_env *env, struct dc_error *err, int errnum, char *strerrbuf, size_t buflen)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = strerror_r(errnum, strerrbuf, buflen);

    if(ret_val == 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_strndup(const struct dc_env *env, struct dc_error *err, const char *s, size_t size)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = strndup(s, size);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t dc_strnlen(const struct dc_env *env, const char *s, size_t maxlen)
{
    size_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = strnlen(s, maxlen);

    return ret_val;
}

char *dc_strsignal(const struct dc_env *env, int signum)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = strsignal(signum);

    return ret_val;
}

char *dc_strtok_r(const struct dc_env *env, char *restrict s, const char *restrict sep, char **restrict state)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = strtok_r(s, sep, state);

    return ret_val;
}

size_t dc_strxfrm_l(const struct dc_env *env, struct dc_error *err, char *restrict s1, const char *restrict s2, size_t n, locale_t locale)
{
    size_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = strxfrm_l(s1, s2, n, locale);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
