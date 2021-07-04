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


#include "wordexp.h"
#include <errno.h>


// https://pubs.opengroup.org/onlinepubs/9699919799/functions/wordexp.html
int dc_wordexp(const struct dc_posix_env *env,
               struct dc_error *err,
               const char *restrict words,
               wordexp_t *restrict pwordexp,
               int flags)
{
    int err_code;

    DC_TRACE(env);
    errno     = 0;
    err_code  = wordexp(words, pwordexp, flags);

    // this isn't great but the docs suck when it comes to telling how it works
    if(errno != 0)
    {
        DC_REPORT_ERRNO(env, err, err_code);
    }
    else if(err_code != 0)
    {
        const char *msg;

        switch(err_code)
        {
            case WRDE_BADCHAR:
            {
                msg = "Unquoted character in wordexp";
                break;
            }
            case WRDE_BADVAL:
            {
                msg = "Undefined shell variable in wordexp";
                break;
            }
            case WRDE_CMDSUB:
            {
                msg = "Command substitution not allowed in wordexp";
                break;
            }
            case WRDE_NOSPACE:
            {
                msg = "Memory allocation failure in wordexp";
                break;
            }
            case WRDE_SYNTAX:
            {
                msg = "Bad shell syntax in wordexp";
                break;
            }
            default:
            {
                msg = "Unknown Error from wordexp";
            }
        }

        DC_REPORT_SYSTEM(env, err, msg, err_code);
    }
    else
    {
        dc_error_reset(err);
    }

    return err_code;
}
