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


#include "dc_posix/sys/dc_statvfs.h"


int dc_fstatvfs(const struct dc_env *env, struct dc_error *err, int fildes, struct statvfs *buf)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = fstatvfs(fildes, buf);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_statvfs(const struct dc_env *env, struct dc_error *err, const char *restrict path, struct statvfs *restrict buf)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = statvfs(path, buf);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
