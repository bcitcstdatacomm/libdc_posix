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


#include "dc_posix/dc_glob.h"


int dc_glob(const struct dc_posix_env *env, struct dc_error *err, const char *restrict pattern, int flags, int(*errfunc)(const char *epath, int eerrno), glob_t *restrict pglob)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = glob(pattern, flags, errfunc, pglob);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_SYSTEM(err, "glob error", ret_val);
    }

    return ret_val;
}

void dc_globfree(const struct dc_posix_env *env, glob_t *pglob)
{
    DC_TRACE(env);
    errno = 0;
    globfree(pglob);
}
