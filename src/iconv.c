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


#include "dc_posix/dc_iconv.h"


size_t dc_iconv(const struct dc_env *env, struct dc_error *err, iconv_t cd, char **restrict inbuf, size_t *restrict inbytesleft, char **restrict outbuf, size_t *restrict outbytesleft)
{
    size_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iconv(cd, inbuf, inbytesleft, outbuf, outbytesleft);

    if(ret_val == (size_t)-1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_iconv_close(const struct dc_env *env, struct dc_error *err, iconv_t cd)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iconv_close(cd);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

iconv_t dc_iconv_open(const struct dc_env *env, struct dc_error *err, const char *tocode, const char *fromcode)
{
    iconv_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = iconv_open(tocode, fromcode);

    if(ret_val == (iconv_t)-1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
