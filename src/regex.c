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

#include "dc_regex.h"
#include "dc_stdlib.h"
#include "dc_string.h"
#include <regex.h>
#include <stdio.h>

int dc_regcomp(const struct dc_posix_env *env,
               struct dc_error *          err,
               regex_t * restrict preg,
               const char * restrict pattern,
               int cflags)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = regcomp(preg, pattern, cflags);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t dc_regerror(const struct dc_posix_env *env,
                   struct dc_error *          err,
                   int                        errcode,
                   const regex_t * restrict preg,
                   char * restrict errbuf,
                   size_t errbuf_size)
{
    size_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = regerror(errcode, preg, errbuf, errbuf_size);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_regexec(const struct dc_posix_env *              env,
               __attribute__((unused)) struct dc_error *err,
               const regex_t * restrict preg,
               const char * restrict string,
               size_t     nmatch,
               regmatch_t pmatch[restrict],
               int        eflags)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = regexec(preg, string, nmatch, pmatch, eflags);

    if(ret_val != 0)
    {
        static const char   *msg_format = "%s does not match the regex";
        static const size_t  msg_format_length = 25;
        size_t               msg_length;
        char                *msg;

        msg_length = msg_format_length + dc_strlen(env, string);
        msg = dc_malloc(env, err, msg_length);

        if(dc_error_has_no_error(err))
        {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
            sprintf(msg, msg_format, string, preg);
#pragma GCC diagnostic pop
            dc_free(env, msg, msg_length * sizeof(char));
            DC_ERROR_RAISE_SYSTEM(err, msg, errno);
        }
    }

    return ret_val;
}

void dc_regfree(const struct dc_posix_env *env, regex_t *preg)
{
    DC_TRACE(env);
    regfree(preg);
}
