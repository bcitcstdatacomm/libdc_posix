#ifndef LIBDC_POSIX_DC_REGEX_H
#define LIBDC_POSIX_DC_REGEX_H

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
#include <regex.h>

/**
 *
 * @param env
 * @param err
 * @param preg
 * @param pattern
 * @param cflags
 * @return
 */
int dc_regcomp(const struct dc_posix_env *env, struct dc_error *err,
               regex_t *restrict preg, const char *restrict pattern,
               int cflags);

/**
 *
 * @param env
 * @param errcode
 * @param preg
 * @param errbuf
 * @param errbuf_size
 * @return
 */
size_t dc_regerror(const struct dc_posix_env *env, int errcode,
                   const regex_t *restrict preg, char *restrict errbuf,
                   size_t errbuf_size);

/**
 *
 * @param env
 * @param preg
 * @param string
 * @param nmatch
 * @param pmatch
 * @param eflags
 * @return
 */
int dc_regexec(const struct dc_posix_env *env, const regex_t *restrict preg,
               const char *restrict string, size_t nmatch,
               regmatch_t pmatch[restrict], int eflags);

/**
 *
 * @param env
 * @param preg
 */
void dc_regfree(const struct dc_posix_env *env, regex_t *preg);

#endif // LIBDC_POSIX_DC_REGEX_H
