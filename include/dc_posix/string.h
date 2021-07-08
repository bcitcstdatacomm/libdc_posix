#ifndef LIBDC_POSIX_STRING_H
#define LIBDC_POSIX_STRING_H


/*
 * Copyright 2021-2021 D'Arcy Smith.
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


#include "posix_env.h"
#include <stddef.h>


/**
 *
 * @param env
 * @param s1
 * @param s2
 * @param n
 * @return
 */
void *dc_memcpy(const struct dc_posix_env *env, void *restrict s1, const void *restrict s2, size_t n);

/**
 *
 * @param env
 * @param s
 * @param c
 * @param n
 * @return
 */
void *dc_memset(const struct dc_posix_env *env, void *s, int c, size_t n);


/**
 *
 * @param env
 * @param s1
 * @param s2
 * @return
 */
char *dc_strcpy(const struct dc_posix_env *env, char *restrict s1, const char *restrict s2);


/**
 *
 * @param env
 * @param s
 * @return
 */
size_t dc_strlen(const struct dc_posix_env *env, const char *s);


/**
 *
 * @param env
 * @param s1
 * @param s2
 * @return
 */
int dc_strcmp(const struct dc_posix_env *env, const char *s1, const char *s2);


/**
 *
 * @param env
 * @param s1
 * @param s2
 * @param n
 * @return
 */
int dc_strncmp(const struct dc_posix_env *env, const char *s1, const char *s2, size_t n);


/**
 *
 * @param env
 * @param s
 * @param sep
 * @param state
 * @return
 */
char *dc_strtok_r(const struct dc_posix_env *env, char *restrict s, const char *restrict sep, char **restrict state);

#endif // LIBDC_POSIX_STRING_H
