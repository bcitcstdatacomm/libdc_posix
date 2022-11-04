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


#include "dc_posix/dc_semaphore.h"


int dc_sem_close(const struct dc_env *env, struct dc_error *err, sem_t *sem)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sem_close(sem);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sem_destroy(const struct dc_env *env, struct dc_error *err, sem_t *sem)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sem_destroy(sem);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sem_getvalue(const struct dc_env *env, struct dc_error *err, sem_t *restrict sem, int *restrict sval)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sem_getvalue(sem, sval);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sem_init(const struct dc_env *env, struct dc_error *err, sem_t *sem, int pshared, unsigned value)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sem_init(sem, pshared, value);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

sem_t *dc_sem_open(const struct dc_env *env, struct dc_error *err, const char *name, int oflag, ...)
{
    sem_t *ret_val;

    DC_TRACE(env);
    errno = 0;
    // TODO: fix the ... or remove the function
    ret_val = sem_open(name, oflag, 0);

    if(ret_val == SEM_FAILED)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sem_post(const struct dc_env *env, struct dc_error *err, sem_t *sem)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sem_post(sem);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sem_trywait(const struct dc_env *env, struct dc_error *err, sem_t *sem)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sem_trywait(sem);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sem_unlink(const struct dc_env *env, struct dc_error *err, const char *name)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sem_unlink(name);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sem_wait(const struct dc_env *env, struct dc_error *err, sem_t *sem)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sem_wait(sem);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
