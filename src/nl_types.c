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


#include "dc_posix/dc_nl_types.h"


int dc_catclose(const struct dc_env *env, struct dc_error *err, nl_catd catd)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = catclose(catd);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_catgets(const struct dc_env *env, struct dc_error *err, nl_catd catd, int set_id, int msg_id, const char *s)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = catgets(catd, set_id, msg_id, s);

    if(ret_val == s)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

nl_catd dc_catopen(const struct dc_env *env, struct dc_error *err, const char *name, int oflag)
{
    nl_catd ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = catopen(name, oflag);

    if(ret_val == (nl_catd)-1)      // NOLINT(performance-no-int-to-ptr)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
