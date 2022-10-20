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


#include "dc_posix/sys/dc_msg.h"


int dc_msgctl(const struct dc_posix_env *env, struct dc_error *err, int msqid, int cmd, struct msqid_ds *buf)
{
    int ret_val;

    DC_TRACE(env);
    ret_val = msgctl(msqid, cmd, buf);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_msgget(const struct dc_posix_env *env, struct dc_error *err, key_t key, int msgflg)
{
    int ret_val;

    DC_TRACE(env);
    ret_val = msgget(key, msgflg);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

ssize_t dc_msgrcv(const struct dc_posix_env *env, struct dc_error *err, int msqid, void *msgp, size_t msgsz, long msgtype, int msgflg)
{
    ssize_t ret_val;

    DC_TRACE(env);
    ret_val = msgrcv(msqid, msgp, msgsz, msgtype, msgflg);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_msgsnd(const struct dc_posix_env *env, struct dc_error *err, int msqid, const void *msgp, size_t msgsz, int msgflg)
{
    int ret_val;

    DC_TRACE(env);
    ret_val = msgsnd(msqid, msgp, msgsz, msgflg);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
