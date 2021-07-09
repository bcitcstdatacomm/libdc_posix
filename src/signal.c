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


#include "signal.h"


// https://pubs.opengroup.org/onlinepubs/9699919799/functions/sigaction.html
int dc_sigaction(const struct dc_posix_env  *env, struct dc_error *err, int sig, const struct sigaction *restrict act, struct sigaction *restrict oact)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = sigaction(sig, act, oact);

    if(ret_val == -1)
    {
        DC_REPORT_ERRNO(env, err, errno);
    }

    return ret_val;
}