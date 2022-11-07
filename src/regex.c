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


#include "dc_posix/dc_regex.h"
#include <dc_c/dc_stdlib.h>


int dc_regcomp(const struct dc_env *env, struct dc_error *err, regex_t *restrict preg, const char *restrict pattern, int cflags)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = regcomp(preg, pattern, cflags);

    if(ret_val != 0)
    {
        size_t len;
        char *msg;

        len = dc_regerror(env, ret_val, preg, NULL, 0);
        msg = dc_malloc(env, err, len);

        if(dc_error_has_no_error(err))
        {
            len = dc_regerror(env, ret_val, preg, msg, len);
            DC_ERROR_RAISE_SYSTEM(err, msg, ret_val);
            dc_free(env, msg);
        }
    }

    return ret_val;
}

size_t dc_regerror(const struct dc_env *env, int errcode, const regex_t *restrict preg, char *restrict errbuf, size_t errbuf_size)
{
    size_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = regerror(errcode, preg, errbuf, errbuf_size);

    return ret_val;
}

int dc_regexec(const struct dc_env *env, const regex_t *restrict preg, const char *restrict string, size_t nmatch, regmatch_t pmatch[restrict], int eflags)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = regexec(preg, string, nmatch, pmatch, eflags);

    return ret_val;
}

void dc_regfree(const struct dc_env *env, regex_t *preg)
{
    DC_TRACE(env);
    errno = 0;
    regfree(preg);
}
