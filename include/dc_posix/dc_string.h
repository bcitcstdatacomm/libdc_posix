#ifndef LIBDC_POSIX_DC_STRING_H
#define LIBDC_POSIX_DC_STRING_H


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

#if (defined __APPLE__) || (defined __FreeBSD__)
    #include <xlocale.h>
#else
    #include <locale.h>
#endif


char *dc_stpcpy(const struct dc_env *env, char *restrict s1, const char *restrict s2);
char *dc_stpncpy(const struct dc_env *env, char *restrict s1, const char *restrict s2, size_t n);
int dc_strcoll_l(const struct dc_env *env, struct dc_error *err, const char *s1, const char *s2, locale_t locale);
char *dc_strdup(const struct dc_env *env, struct dc_error *err, const char *s);
int dc_strerror_r(const struct dc_env *env, struct dc_error *err, int errnum, char *strerrbuf, size_t buflen);
char *dc_strndup(const struct dc_env *env, struct dc_error *err, const char *s, size_t size);
size_t dc_strnlen(const struct dc_env *env, const char *s, size_t maxlen);
char *dc_strsignal(const struct dc_env *env, int signum);
char *dc_strtok_r(const struct dc_env *env, char *restrict s, const char *restrict sep, char **restrict state);
size_t dc_strxfrm_l(const struct dc_env *env, struct dc_error *err, char *restrict s1, const char *restrict s2, size_t n, locale_t locale);


#ifdef __cplusplus
extern "C" {
#endif


// not on macOS
// char *dc_strerror_l(const struct dc_env *env, struct dc_error *err, int errnum, locale_t locale);


#endif // LIBDC_POSIX_DC_STRING_H
