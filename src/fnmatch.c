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


#include "dc_posix/dc_fnmatch.h"
#include <fnmatch.h>


int dc_fnmatch(const struct dc_env *env, struct dc_error *err, const char *pattern, const char *string, int flags)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = fnmatch(pattern, string, flags);

    if(ret_val != 0 && ret_val != FNM_NOMATCH)
    {
        // TODO: what message?
        DC_ERROR_RAISE_SYSTEM(err, "", ret_val);
    }

    return ret_val;
}
