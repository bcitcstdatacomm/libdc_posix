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


#include "dc_posix/dc_wordexp.h"


int dc_wordexp(const struct dc_env *env, struct dc_error *err, const char *restrict words, wordexp_t *restrict pwordexp, int flags)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = wordexp(words, pwordexp, flags);

    if(ret_val != 0)
    {
        // TODO: message
        DC_ERROR_RAISE_SYSTEM(err, "", ret_val);
    }

    return ret_val;
}

void dc_wordfree(const struct dc_env *env, wordexp_t *pwordexp)
{
    DC_TRACE(env);
    errno = 0;
    wordfree(pwordexp);
}
