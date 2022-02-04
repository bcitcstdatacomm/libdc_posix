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

#include "dc_string.h"

void *dc_memccpy(const struct dc_posix_env *env, void * restrict s1, const void * restrict s2, int c, size_t n)
{
    void *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = memccpy(s1, s2, c, n);

    return ret_val;
}

void *dc_memchr(const struct dc_posix_env *env, const void *s, int c, size_t n)
{
    void *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = memchr(s, c, n);

    return ret_val;
}

int dc_memcmp(const struct dc_posix_env *env, const void *s1, const void *s2, size_t n)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = memcmp(s1, s2, n);

    return ret_val;
}

void *dc_memcpy(const struct dc_posix_env *env, void * restrict s1, const void * restrict s2, size_t n)
{
    void *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = memcpy(s1, s2, n);

    return ret_val;
}

void *dc_memmove(const struct dc_posix_env *env, void *s1, const void *s2, size_t n)
{
    void *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = memmove(s1, s2, n);

    return ret_val;
}

void *dc_memset(const struct dc_posix_env *env, void *s, int c, size_t n)
{
    void *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = memset(s, c, n);

    return ret_val;
}

char *dc_stpcpy(const struct dc_posix_env *env, char * restrict s1, const char * restrict s2)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = stpcpy(s1, s2);

    return ret_val;
}

char *dc_stpncpy(const struct dc_posix_env *env, char * restrict s1, const char * restrict s2, size_t n)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = stpncpy(s1, s2, n);

    return ret_val;
}

char *dc_strcat(const struct dc_posix_env *env, char * restrict s1, const char * restrict s2)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strcat(s1, s2);

    return ret_val;
}

char *dc_strchr(const struct dc_posix_env *env, const char *s, int c)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strchr(s, c);

    return ret_val;
}

int dc_strcmp(const struct dc_posix_env *env, const char *s1, const char *s2)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strcmp(s1, s2);

    return ret_val;
}

int dc_strcoll(const struct dc_posix_env *env, const char *s1, const char *s2)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strcoll(s1, s2);

    return ret_val;
}

int dc_strcoll_l(const struct dc_posix_env *env, const char *s1, const char *s2, locale_t locale)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strcoll_l(s1, s2, locale);

    return ret_val;
}

char *dc_strcpy(const struct dc_posix_env *env, char * restrict s1, const char * restrict s2)
{
    void *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strcpy(s1, s2);

    return ret_val;
}

size_t dc_strcspn(const struct dc_posix_env *env, const char *s1, const char *s2)
{
    size_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strcspn(s1, s2);

    return ret_val;
}

char *dc_strdup(const struct dc_posix_env *env, struct dc_error *err, const char *s)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strdup(s);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_strerror(const struct dc_posix_env *env, struct dc_error *err, int errnum)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strerror(errnum);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_strerror_r(const struct dc_posix_env *env, int errnum, char *strerrbuf, size_t buflen)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strerror_r(errnum, strerrbuf, buflen);

    return ret_val;
}

size_t dc_strlen(const struct dc_posix_env *env, const char *s)
{
    size_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strlen(s);

    return ret_val;
}

char *dc_strncat(const struct dc_posix_env *env, char * restrict s1, const char * restrict s2, size_t n)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strncat(s1, s2, n);

    return ret_val;
}

int dc_strncmp(const struct dc_posix_env *env, const char *s1, const char *s2, size_t n)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strncmp(s1, s2, n);

    return ret_val;
}

char *dc_strncpy(const struct dc_posix_env *env, char * restrict s1, const char * restrict s2, size_t n)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strncpy(s1, s2, n);

    return ret_val;
}

char *dc_strndup(const struct dc_posix_env *env, struct dc_error *err, const char *s, size_t n)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strndup(s, n);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t dc_strnlen(const struct dc_posix_env *env, const char *s, size_t maxlen)
{
    size_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strnlen(s, maxlen);

    return ret_val;
}

char *dc_strpbrk(const struct dc_posix_env *env, const char *s1, const char *s2)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strpbrk(s1, s2);

    return ret_val;
}

char *dc_strrchr(const struct dc_posix_env *env, const char *s, int c)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strrchr(s, c);

    return ret_val;
}

char *dc_strsignal(const struct dc_posix_env *env, int signum)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strsignal(signum);

    return ret_val;
}

size_t dc_strspn(const struct dc_posix_env *env, const char *s1, const char *s2)
{
    size_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strspn(s1, s2);

    return ret_val;
}

char *dc_strstr(const struct dc_posix_env *env, const char *s1, const char *s2)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strstr(s1, s2);

    return ret_val;
}

char *dc_strtok(const struct dc_posix_env *env, char * restrict s, const char * restrict sep)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strtok(s, sep);

    return ret_val;
}

char *dc_strtok_r(const struct dc_posix_env *env, char * restrict s, const char * restrict sep, char ** restrict state)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strtok_r(s, sep, state);

    return ret_val;
}

size_t
dc_strxfrm(const struct dc_posix_env *env, struct dc_error *err, char * restrict s1, const char * restrict s2, size_t n)
{
    size_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strxfrm(s1, s2, n);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t dc_strxfrm_l(const struct dc_posix_env *env,
                    struct dc_error           *err,
                    char * restrict s1,
                    const char * restrict s2,
                    size_t   n,
                    locale_t locale)
{
    size_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = strxfrm_l(s1, s2, n, locale);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
