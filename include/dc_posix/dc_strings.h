#ifndef LIBDC_POSIX_DC_STRINGS_H
#define LIBDC_POSIX_DC_STRINGS_H


/*
 * Copyright 2022-2022 D'Arcy Smith.
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
#include <strings.h>
#if __has_include(<xlocale.h>)
    #include <xlocale.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif


/**
 *
 * @param env
 * @param i
 * @return
 */
int dc_ffs(const struct dc_posix_env *env, int i);

/**
 *
 * @param env
 * @param s1
 * @param s2
 * @return
 */
int dc_strcasecmp(const struct dc_posix_env *env, const char *s1, const char *s2);

/**
 *
 * @param env
 * @param s1
 * @param s2
 * @param locale
 * @return
 */
int dc_strcasecmp_l(const struct dc_posix_env *env, const char *s1, const char *s2, locale_t locale);

/**
 *
 * @param env
 * @param s1
 * @param s2
 * @param n
 * @return
 */
int dc_strncasecmp(const struct dc_posix_env *env, const char *s1, const char *s2, size_t n);

/**
 *
 * @param env
 * @param s1
 * @param s2
 * @param n
 * @param locale
 * @return
 */
int dc_strncasecmp_l(const struct dc_posix_env *env, const char *s1, const char *s2, size_t n, locale_t locale);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_STRINGS_H
