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

#include "dc_sched.h"

int dc_sched_get_priority_max(const struct dc_posix_env *env, struct dc_error *err, int policy)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = sched_get_priority_max(policy);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sched_get_priority_min(const struct dc_posix_env *env, struct dc_error *err, int policy)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = sched_get_priority_min(policy);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

/*
int dc_sched_getparam(const struct dc_posix_env *env, struct dc_error *err, pid_t pid, struct sched_param *param)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = sched_getparam(pid, param);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
*/

/*
int dc_sched_getscheduler(const struct dc_posix_env *env, struct dc_error *err, pid_t pid)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = sched_getscheduler(pid);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
*/

/*
int dc_sched_rr_get_interval(const struct dc_posix_env *env, struct dc_error *err, pid_t pid, struct timespec *interval)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = sched_rr_get_interval(pid, interval);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
*/

/*
int dc_sched_setparam(const struct dc_posix_env *env, struct dc_error *err, pid_t pid, const struct sched_param *param)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = sched_setparam(pid, param);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
*/

/*
int dc_sched_setscheduler(const struct dc_posix_env *env, struct dc_error *err, pid_t pid, int policy, const struct sched_param *param)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = sched_setscheduler(pid, policy, param);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
*/
int dc_sched_yield(const struct dc_posix_env *env, struct dc_error *err)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = sched_yield();

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
