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


#include "dc_posix/dc_pthread.h"


int dc_pthread_atfork(const struct dc_posix_env *env, struct dc_error *err, void (*prepare)(void), void (*parent)(void), void (*child)(void))
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_atfork(prepare, parent, child);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_destroy(attr);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_getdetachstate(const struct dc_posix_env *env, struct dc_error *err, const pthread_attr_t *attr, int *detachstate)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_getdetachstate(attr, detachstate);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_getguardsize(const struct dc_posix_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, size_t *restrict guardsize)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_getguardsize(attr, guardsize);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_getinheritsched(const struct dc_posix_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, int *restrict inheritsched)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_getinheritsched(attr, inheritsched);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_getschedparam(const struct dc_posix_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, struct sched_param *restrict param)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_getschedparam(attr, param);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_getschedpolicy(const struct dc_posix_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, int *restrict policy)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_getschedpolicy(attr, policy);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_getscope(const struct dc_posix_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, int *restrict contentionscope)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_getscope(attr, contentionscope);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_getstack(const struct dc_posix_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, void **restrict stackaddr, size_t *restrict stacksize)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_getstack(attr, stackaddr, stacksize);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_getstacksize(const struct dc_posix_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, size_t *restrict stacksize)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_getstacksize(attr, stacksize);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_init(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_init(attr);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_setdetachstate(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr, int detachstate)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_setdetachstate(attr, detachstate);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_setguardsize(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr, size_t guardsize)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_setguardsize(attr, guardsize);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_setinheritsched(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr, int inheritsched)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_setinheritsched(attr, inheritsched);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_setschedparam(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr, int inheritsched)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_setinheritsched(attr, inheritsched);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_setschedpolicy(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr, int policy)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_setschedpolicy(attr, policy);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_setscope(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr, int contentionscope)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_setscope(attr, contentionscope);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_setstack(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr, void *stackaddr, size_t stacksize)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_setstack(attr, stackaddr, stacksize);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_attr_setstacksize(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr, size_t stacksize)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_attr_setstacksize(attr, stacksize);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

/*
int dc_pthread_barrier_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_barrier_t *barrier)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_barrier_destroy(barrier);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_barrier_init(const struct dc_posix_env *env, struct dc_error *err, pthread_barrier_t *restrict barrier, const pthread_barrierattr_t *restrict attr, unsigned count)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_barrier_init(barrier, attr, count);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_barrier_wait(const struct dc_posix_env *env, struct dc_error *err, pthread_barrier_t *barrier)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_barrier_wait(barrier);

    if(ret_val != PTHREAD_BARRIER_SERIAL_THREAD && ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_barrierattr_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_barrierattr_t *attr)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_barrierattr_destroy(attr);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_barrierattr_getpshared(const struct dc_posix_env *env, struct dc_error *err, const pthread_barrierattr_t *restrict attr, int *restrict pshared)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_barrierattr_getpshared(attr, pshared);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_barrierattr_init(const struct dc_posix_env *env, struct dc_error *err, pthread_barrierattr_t *attr)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_barrierattr_init(attr);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_barrierattr_setpshared(const struct dc_posix_env *env, struct dc_error *err, pthread_barrierattr_t *attr, int pshared)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_barrierattr_setpshared(attr, pshared);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}
*/
int dc_pthread_cancel(const struct dc_posix_env *env, struct dc_error *err, pthread_t thread)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_cancel(thread);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_cond_broadcast(const struct dc_posix_env *env, struct dc_error *err, pthread_cond_t *cond)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_cond_broadcast(cond);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_cond_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_cond_t *cond)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_cond_destroy(cond);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_cond_init(const struct dc_posix_env *env, struct dc_error *err, pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_cond_init(cond, attr);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_cond_signal(const struct dc_posix_env *env, struct dc_error *err, pthread_cond_t *cond)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_cond_signal(cond);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_cond_timedwait(const struct dc_posix_env *env, struct dc_error *err, pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex, const struct timespec *restrict abstime)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_cond_timedwait(cond, mutex, abstime);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_cond_wait(const struct dc_posix_env *env, struct dc_error *err, pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_cond_wait(cond, mutex);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_condattr_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_condattr_t *attr)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_condattr_destroy(attr);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

/*
int dc_pthread_condattr_getclock(const struct dc_posix_env *env, struct dc_error *err, const pthread_condattr_t *restrict attr, clockid_t *restrict clock_id)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_condattr_getclock(attr, clock_id);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}
*/

int dc_pthread_condattr_getpshared(const struct dc_posix_env *env, struct dc_error *err, const pthread_condattr_t *restrict attr, int *restrict pshared)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_condattr_getpshared(attr, pshared);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_condattr_init(const struct dc_posix_env *env, struct dc_error *err, pthread_condattr_t *attr)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_condattr_init(attr);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

/*
int dc_pthread_condattr_setclock(const struct dc_posix_env *env, struct dc_error *err, pthread_condattr_t *attr, clockid_t clock_id)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_condattr_setclock(attr, clock_id);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}
*/

int dc_pthread_condattr_setpshared(const struct dc_posix_env *env, struct dc_error *err, pthread_condattr_t *attr, int pshared)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_condattr_setpshared(attr, pshared);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_create(const struct dc_posix_env *env, struct dc_error *err, pthread_t *restrict thread, const pthread_attr_t *restrict attr,  void *(*start_routine)(void*), void *restrict arg)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_create(thread, attr, start_routine, arg);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_detach(const struct dc_posix_env *env, struct dc_error *err, pthread_t thread)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_detach(thread);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_equal(const struct dc_posix_env *env, pthread_t t1, pthread_t t2)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_equal(t1, t2);

    return ret_val;
}

_Noreturn void dc_pthread_exit(const struct dc_posix_env *env, void *value_ptr)
{
    DC_TRACE(env);
    pthread_exit(value_ptr);
}

/*
int dc_pthread_getcpuclockid(const struct dc_posix_env *env, struct dc_error *err, pthread_t thread_id, clockid_t *clock_id)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_getcpuclockid(thread_id, clock_id);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}
*/

int dc_pthread_getschedparam(const struct dc_posix_env *env, struct dc_error *err, pthread_t thread, int *restrict policy, struct sched_param *restrict param)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_getschedparam(thread, policy, param);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

void *dc_pthread_getspecific(const struct dc_posix_env *env, pthread_key_t key)
{
    void *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_getspecific(key);

    return ret_val;
}

int dc_pthread_join(const struct dc_posix_env *env, struct dc_error *err, pthread_t thread, void **value_ptr)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_join(thread, value_ptr);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_key_create(const struct dc_posix_env *env, struct dc_error *err, pthread_key_t *key, void (*destructor)(void*))
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_key_create(key, destructor);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_key_delete(const struct dc_posix_env *env, struct dc_error *err, pthread_key_t key)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_key_delete(key);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

/*
int dc_pthread_mutex_consistent(const struct dc_posix_env *env, struct dc_error *err, pthread_mutex_t *mutex)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutex_consistent(mutex);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}
*/

int dc_pthread_mutex_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_mutex_t *mutex)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutex_destroy(mutex);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_mutex_getprioceiling(const struct dc_posix_env *env, struct dc_error *err, const pthread_mutex_t *restrict mutex, int *restrict prioceiling)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutex_getprioceiling(mutex, prioceiling);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_mutex_init(const struct dc_posix_env *env, struct dc_error *err, pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutex_init(mutex, attr);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_mutex_lock(const struct dc_posix_env *env, struct dc_error *err, pthread_mutex_t *mutex)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutex_lock(mutex);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_mutex_setprioceiling(const struct dc_posix_env *env, struct dc_error *err, pthread_mutex_t *restrict mutex, int prioceiling, int *restrict old_ceiling)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutex_setprioceiling(mutex, prioceiling, old_ceiling);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

/*
int dc_pthread_mutex_timedlock(const struct dc_posix_env *env, struct dc_error *err, pthread_mutex_t *restrict mutex, const struct timespec *restrict abstime)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutex_timedlock(mutex, abstime);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}
*/

int dc_pthread_mutex_trylock(const struct dc_posix_env *env, struct dc_error *err, pthread_mutex_t *mutex)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutex_trylock(mutex);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_mutex_unlock(const struct dc_posix_env *env, struct dc_error *err, pthread_mutex_t *mutex)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutex_unlock(mutex);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_mutexattr_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_mutexattr_t *attr)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutexattr_destroy(attr);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_mutexattr_getprioceiling(const struct dc_posix_env *env, struct dc_error *err, const pthread_mutexattr_t *restrict attr, int *restrict prioceiling)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutexattr_getprioceiling(attr, prioceiling);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_mutexattr_getprotocol(const struct dc_posix_env *env, struct dc_error *err, const pthread_mutexattr_t *restrict attr, int *restrict protocol)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutexattr_getprotocol(attr, protocol);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_mutexattr_getpshared(const struct dc_posix_env *env, struct dc_error *err, const pthread_mutexattr_t *restrict attr, int *restrict pshared)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutexattr_getpshared(attr, pshared);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

/*
int dc_pthread_mutexattr_getrobust(const struct dc_posix_env *env, struct dc_error *err, const pthread_mutexattr_t *restrict attr, int *restrict robust)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutexattr_getrobust(attr, robust);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}
*/

int dc_pthread_mutexattr_gettype(const struct dc_posix_env *env, struct dc_error *err, const pthread_mutexattr_t *restrict attr, int *restrict type)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutexattr_gettype(attr, type);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_mutexattr_init(const struct dc_posix_env *env, struct dc_error *err, pthread_mutexattr_t *attr)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutexattr_init(attr);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_mutexattr_setprioceiling(const struct dc_posix_env *env, struct dc_error *err, pthread_mutexattr_t *attr, int prioceiling)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutexattr_setprioceiling(attr, prioceiling);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_mutexattr_setprotocol(const struct dc_posix_env *env, struct dc_error *err, pthread_mutexattr_t *attr, int protocol)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutexattr_setprotocol(attr, protocol);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_mutexattr_setpshared(const struct dc_posix_env *env, struct dc_error *err, pthread_mutexattr_t *attr, int pshared)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutexattr_setpshared(attr, pshared);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

/*
int dc_pthread_mutexattr_setrobust(const struct dc_posix_env *env, struct dc_error *err, pthread_mutexattr_t *attr, int robust)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutexattr_setrobust(attr, robust);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}
*/

int dc_pthread_mutexattr_settype(const struct dc_posix_env *env, struct dc_error *err, pthread_mutexattr_t *attr, int type)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_mutexattr_settype(attr, type);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_once(const struct dc_posix_env *env, struct dc_error *err, pthread_once_t *once_control, void (*init_routine)(void))
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_once(once_control, init_routine);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_rwlock_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *rwlock)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_rwlock_destroy(rwlock);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_rwlock_init(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *restrict rwlock, const pthread_rwlockattr_t *restrict attr)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_rwlock_init(rwlock, attr);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_rwlock_rdlock(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *rwlock)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_rwlock_rdlock(rwlock);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

/*
int dc_pthread_rwlock_timedrdlock(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *restrict rwlock, const struct timespec *restrict abstime)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_rwlock_timedrdlock(rwlock, abstime);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}
*/

/*
int dc_pthread_rwlock_timedwrlock(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *restrict rwlock, const struct timespec *restrict abstime)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_rwlock_timedwrlock(rwlock, abstime);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}
*/

int dc_pthread_rwlock_tryrdlock(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *rwlock)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_rwlock_tryrdlock(rwlock);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_rwlock_trywrlock(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *rwlock)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_rwlock_trywrlock(rwlock);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_rwlock_unlock(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *rwlock)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_rwlock_unlock(rwlock);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_rwlock_wrlock(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *rwlock)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_rwlock_wrlock(rwlock);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_rwlockattr_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlockattr_t *attr)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_rwlockattr_destroy(attr);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_rwlockattr_getpshared(const struct dc_posix_env *env, struct dc_error *err, const pthread_rwlockattr_t *restrict attr, int *restrict pshared)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_rwlockattr_getpshared(attr, pshared);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_rwlockattr_init(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlockattr_t *attr)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_rwlockattr_init(attr);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_rwlockattr_setpshared(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlockattr_t *attr, int pshared)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_rwlockattr_setpshared(attr, pshared);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

pthread_t dc_pthread_self(const struct dc_posix_env *env)
{
    pthread_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_self();

    return ret_val;
}

int dc_pthread_setcancelstate(const struct dc_posix_env *env, struct dc_error *err, int state, int *oldstate)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_setcancelstate(state, oldstate);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_setcanceltype(const struct dc_posix_env *env, struct dc_error *err, int type, int *oldtype)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_setcanceltype(type, oldtype);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_setschedparam(const struct dc_posix_env *env, struct dc_error *err, pthread_t thread, int policy, const struct sched_param *param)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_setschedparam(thread, policy, param);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

/*
int dc_pthread_setschedprio(const struct dc_posix_env *env, struct dc_error *err, pthread_t thread, int prio)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_setschedprio(thread, prio);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}
*/

int dc_pthread_setspecific(const struct dc_posix_env *env, struct dc_error *err, pthread_key_t key, const void *value)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pthread_setspecific(key, value);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

void dc_pthread_testcancel(const struct dc_posix_env *env)
{
    DC_TRACE(env);
    errno   = 0;
    pthread_testcancel();
}
