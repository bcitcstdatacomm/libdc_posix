#ifndef LIBDC_POSIX_PTHREAD_H
#define LIBDC_POSIX_PTHREAD_H


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


#include "dc_posix_env.h"
#include <pthread.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 *
 * @param env
 * @param err
 * @param prepare
 * @param parent
 * @param child
 * @return
 */
int dc_pthread_atfork(const struct dc_posix_env *env, struct dc_error *err, void (*prepare)(void), void (*parent)(void), void (*child)(void));

/**
 *
 * @param env
 * @param err
 * @param attr
 * @return
 */
int dc_pthread_attr_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param detachstate
 * @return
 */
int dc_pthread_attr_getdetachstate(const struct dc_posix_env *env, struct dc_error *err, const pthread_attr_t *attr, int *detachstate);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param guardsize
 * @return
 */
int dc_pthread_attr_getguardsize(const struct dc_posix_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, size_t *restrict guardsize);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param inheritsched
 * @return
 */
int dc_pthread_attr_getinheritsched(const struct dc_posix_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, int *restrict inheritsched);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param param
 * @return
 */
int dc_pthread_attr_getschedparam(const struct dc_posix_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, struct sched_param *restrict param);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param policy
 * @return
 */
int dc_pthread_attr_getschedpolicy(const struct dc_posix_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, int *restrict policy);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param contentionscope
 * @return
 */
int dc_pthread_attr_getscope(const struct dc_posix_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, int *restrict contentionscope);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param stackaddr
 * @param stacksize
 * @return
 */
int dc_pthread_attr_getstack(const struct dc_posix_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, void **restrict stackaddr, size_t *restrict stacksize);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param stacksize
 * @return
 */
int dc_pthread_attr_getstacksize(const struct dc_posix_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, size_t *restrict stacksize);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @return
 */
int dc_pthread_attr_init(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param detachstate
 * @return
 */
int dc_pthread_attr_setdetachstate(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr, int detachstate);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param guardsize
 * @return
 */
int dc_pthread_attr_setguardsize(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr, size_t guardsize);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param inheritsched
 * @return
 */
int dc_pthread_attr_setinheritsched(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr, int inheritsched);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param inheritsched
 * @return
 */
int dc_pthread_attr_setschedparam(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr, int inheritsched);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param policy
 * @return
 */
int dc_pthread_attr_setschedpolicy(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr, int policy);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param contentionscope
 * @return
 */
int dc_pthread_attr_setscope(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr, int contentionscope);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param stackaddr
 * @param stacksize
 * @return
 */
int dc_pthread_attr_setstack(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr, void *stackaddr, size_t stacksize);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param stacksize
 * @return
 */
int dc_pthread_attr_setstacksize(const struct dc_posix_env *env, struct dc_error *err, pthread_attr_t *attr, size_t stacksize);

/*
int dc_pthread_barrier_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_barrier_t *barrier);
int dc_pthread_barrier_init(const struct dc_posix_env *env, struct dc_error *err, pthread_barrier_t *restrict barrier, const pthread_barrierattr_t *restrict attr, unsigned count);
int dc_pthread_barrier_wait(const struct dc_posix_env *env, struct dc_error *err, pthread_barrier_t *barrier);
int dc_pthread_barrierattr_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_barrierattr_t *attr);
int dc_pthread_barrierattr_getpshared(const struct dc_posix_env *env, struct dc_error *err, const pthread_barrierattr_t *restrict attr, int *restrict pshared);
int dc_pthread_barrierattr_init(const struct dc_posix_env *env, struct dc_error *err, pthread_barrierattr_t *attr);
int dc_pthread_barrierattr_setpshared(const struct dc_posix_env *env, struct dc_error *err, pthread_barrierattr_t *attr, int pshared);
*/

/**
 *
 * @param env
 * @param err
 * @param thread
 * @return
 */
int dc_pthread_cancel(const struct dc_posix_env *env, struct dc_error *err, pthread_t thread);

/**
 *
 * @param env
 * @param err
 * @param cond
 * @return
 */
int dc_pthread_cond_broadcast(const struct dc_posix_env *env, struct dc_error *err, pthread_cond_t *cond);

/**
 *
 * @param env
 * @param err
 * @param cond
 * @return
 */
int dc_pthread_cond_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_cond_t *cond);

/**
 *
 * @param env
 * @param err
 * @param cond
 * @param attr
 * @return
 */
int dc_pthread_cond_init(const struct dc_posix_env *env, struct dc_error *err, pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr);

/**
 *
 * @param env
 * @param err
 * @param cond
 * @return
 */
int dc_pthread_cond_signal(const struct dc_posix_env *env, struct dc_error *err, pthread_cond_t *cond);

/**
 *
 * @param env
 * @param err
 * @param cond
 * @param mutex
 * @param abstime
 * @return
 */
int dc_pthread_cond_timedwait(const struct dc_posix_env *env, struct dc_error *err, pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex, const struct timespec *restrict abstime);

/**
 *
 * @param env
 * @param err
 * @param cond
 * @param mutex
 * @return
 */
int dc_pthread_cond_wait(const struct dc_posix_env *env, struct dc_error *err, pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @return
 */
int dc_pthread_condattr_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_condattr_t *attr);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param pshared
 * @return
 */
int dc_pthread_condattr_getpshared(const struct dc_posix_env *env, struct dc_error *err, const pthread_condattr_t *restrict attr, int *restrict pshared);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @return
 */
int dc_pthread_condattr_init(const struct dc_posix_env *env, struct dc_error *err, pthread_condattr_t *attr);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param pshared
 * @return
 */
int dc_pthread_condattr_setpshared(const struct dc_posix_env *env, struct dc_error *err, pthread_condattr_t *attr, int pshared);

/**
 *
 * @param env
 * @param err
 * @param thread
 * @param attr
 * @param start_routine
 * @param arg
 * @return
 */
int dc_pthread_create(const struct dc_posix_env *env, struct dc_error *err, pthread_t *restrict thread, const pthread_attr_t *restrict attr,  void *(*start_routine)(void*), void *restrict arg);

/**
 *
 * @param env
 * @param err
 * @param thread
 * @return
 */
int dc_pthread_detach(const struct dc_posix_env *env, struct dc_error *err, pthread_t thread);

/**
 *
 * @param env
 * @param t1
 * @param t2
 * @return
 */
int dc_pthread_equal(const struct dc_posix_env *env, pthread_t t1, pthread_t t2);

/**
 *
 * @param env
 * @param value_ptr
 */
_Noreturn void dc_pthread_exit(const struct dc_posix_env *env, void *value_ptr);

/**
 *
 * @param env
 * @param err
 * @param thread
 * @param policy
 * @param param
 * @return
 */
int dc_pthread_getschedparam(const struct dc_posix_env *env, struct dc_error *err, pthread_t thread, int *restrict policy, struct sched_param *restrict param);

/**
 *
 * @param env
 * @param key
 * @return
 */
void *dc_pthread_getspecific(const struct dc_posix_env *env, pthread_key_t key);

/**
 *
 * @param env
 * @param err
 * @param thread
 * @param value_ptr
 * @return
 */
int dc_pthread_join(const struct dc_posix_env *env, struct dc_error *err, pthread_t thread, void **value_ptr);

/**
 *
 * @param env
 * @param err
 * @param key
 * @param destructor
 * @return
 */
int dc_pthread_key_create(const struct dc_posix_env *env, struct dc_error *err, pthread_key_t *key, void (*destructor)(void*));

/**
 *
 * @param env
 * @param err
 * @param key
 * @return
 */
int dc_pthread_key_delete(const struct dc_posix_env *env, struct dc_error *err, pthread_key_t key);

/**
 *
 * @param env
 * @param err
 * @param mutex
 * @return
 */
int dc_pthread_mutex_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_mutex_t *mutex);

/**
 *
 * @param env
 * @param err
 * @param mutex
 * @param prioceiling
 * @return
 */
int dc_pthread_mutex_getprioceiling(const struct dc_posix_env *env, struct dc_error *err, const pthread_mutex_t *restrict mutex, int *restrict prioceiling);

/**
 *
 * @param env
 * @param err
 * @param mutex
 * @param attr
 * @return
 */
int dc_pthread_mutex_init(const struct dc_posix_env *env, struct dc_error *err, pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);

/**
 *
 * @param env
 * @param err
 * @param mutex
 * @return
 */
int dc_pthread_mutex_lock(const struct dc_posix_env *env, struct dc_error *err, pthread_mutex_t *mutex);

/**
 *
 * @param env
 * @param err
 * @param mutex
 * @param prioceiling
 * @param old_ceiling
 * @return
 */
int dc_pthread_mutex_setprioceiling(const struct dc_posix_env *env, struct dc_error *err, pthread_mutex_t *restrict mutex, int prioceiling, int *restrict old_ceiling);

/**
 *
 * @param env
 * @param err
 * @param mutex
 * @return
 */
int dc_pthread_mutex_trylock(const struct dc_posix_env *env, struct dc_error *err, pthread_mutex_t *mutex);

/**
 *
 * @param env
 * @param err
 * @param mutex
 * @return
 */
int dc_pthread_mutex_unlock(const struct dc_posix_env *env, struct dc_error *err, pthread_mutex_t *mutex);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @return
 */
int dc_pthread_mutexattr_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_mutexattr_t *attr);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param prioceiling
 * @return
 */
int dc_pthread_mutexattr_getprioceiling(const struct dc_posix_env *env, struct dc_error *err, const pthread_mutexattr_t *restrict attr, int *restrict prioceiling);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param protocol
 * @return
 */
int dc_pthread_mutexattr_getprotocol(const struct dc_posix_env *env, struct dc_error *err, const pthread_mutexattr_t *restrict attr, int *restrict protocol);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param pshared
 * @return
 */
int dc_pthread_mutexattr_getpshared(const struct dc_posix_env *env, struct dc_error *err, const pthread_mutexattr_t *restrict attr, int *restrict pshared);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param type
 * @return
 */
int dc_pthread_mutexattr_gettype(const struct dc_posix_env *env, struct dc_error *err, const pthread_mutexattr_t *restrict attr, int *restrict type);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @return
 */
int dc_pthread_mutexattr_init(const struct dc_posix_env *env, struct dc_error *err, pthread_mutexattr_t *attr);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param prioceiling
 * @return
 */
int dc_pthread_mutexattr_setprioceiling(const struct dc_posix_env *env, struct dc_error *err, pthread_mutexattr_t *attr, int prioceiling);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param protocol
 * @return
 */
int dc_pthread_mutexattr_setprotocol(const struct dc_posix_env *env, struct dc_error *err, pthread_mutexattr_t *attr, int protocol);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param pshared
 * @return
 */
int dc_pthread_mutexattr_setpshared(const struct dc_posix_env *env, struct dc_error *err, pthread_mutexattr_t *attr, int pshared);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param type
 * @return
 */
int dc_pthread_mutexattr_settype(const struct dc_posix_env *env, struct dc_error *err, pthread_mutexattr_t *attr, int type);

/**
 *
 * @param env
 * @param err
 * @param once_control
 * @param init_routine
 * @return
 */
int dc_pthread_once(const struct dc_posix_env *env, struct dc_error *err, pthread_once_t *once_control, void (*init_routine)(void));

/**
 *
 * @param env
 * @param err
 * @param rwlock
 * @return
 */
int dc_pthread_rwlock_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *rwlock);

/**
 *
 * @param env
 * @param err
 * @param rwlock
 * @param attr
 * @return
 */
int dc_pthread_rwlock_init(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *restrict rwlock, const pthread_rwlockattr_t *restrict attr);

/**
 *
 * @param env
 * @param err
 * @param rwlock
 * @return
 */
int dc_pthread_rwlock_rdlock(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *rwlock);

/**
 *
 * @param env
 * @param err
 * @param rwlock
 * @return
 */
int dc_pthread_rwlock_tryrdlock(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *rwlock);

/**
 *
 * @param env
 * @param err
 * @param rwlock
 * @return
 */
int dc_pthread_rwlock_trywrlock(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *rwlock);

/**
 *
 * @param env
 * @param err
 * @param rwlock
 * @return
 */
int dc_pthread_rwlock_unlock(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *rwlock);

/**
 *
 * @param env
 * @param err
 * @param rwlock
 * @return
 */
int dc_pthread_rwlock_wrlock(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *rwlock);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @return
 */
int dc_pthread_rwlockattr_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlockattr_t *attr);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param pshared
 * @return
 */
int dc_pthread_rwlockattr_getpshared(const struct dc_posix_env *env, struct dc_error *err, const pthread_rwlockattr_t *restrict attr, int *restrict pshared);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @return
 */
int dc_pthread_rwlockattr_init(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlockattr_t *attr);

/**
 *
 * @param env
 * @param err
 * @param attr
 * @param pshared
 * @return
 */
int dc_pthread_rwlockattr_setpshared(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlockattr_t *attr, int pshared);

/**
 *
 * @param env
 * @return
 */
pthread_t dc_pthread_self(const struct dc_posix_env *env);

/**
 *
 * @param env
 * @param err
 * @param state
 * @param oldstate
 * @return
 */
int dc_pthread_setcancelstate(const struct dc_posix_env *env, struct dc_error *err, int state, int *oldstate);

/**
 *
 * @param env
 * @param err
 * @param type
 * @param oldtype
 * @return
 */
int dc_pthread_setcanceltype(const struct dc_posix_env *env, struct dc_error *err, int type, int *oldtype);

/**
 *
 * @param env
 * @param err
 * @param thread
 * @param policy
 * @param param
 * @return
 */
int dc_pthread_setschedparam(const struct dc_posix_env *env, struct dc_error *err, pthread_t thread, int policy, const struct sched_param *param);

/**
 *
 * @param env
 * @param err
 * @param key
 * @param value
 * @return
 */
int dc_pthread_setspecific(const struct dc_posix_env *env, struct dc_error *err, pthread_key_t key, const void *value);

/**
 *
 * @param env
 */
void dc_pthread_testcancel(const struct dc_posix_env *env);


struct dc_thread_arg
{
    struct dc_posix_env *env;
    struct dc_error *err;
};


#ifdef __cplusplus
}
#endif


// These are implemented as macros, and don't work as functions
// void dc_pthread_cleanup_pop(const struct dc_posix_env *env, int execute);
// void dc_pthread_cleanup_push(const struct dc_posix_env *env, void (*routine)(void*), void *arg);

// obsolete
// int pthread_getconcurrency(void);
// int pthread_setconcurrency(int new_level);

// These do not exist on macOS
// int dc_pthread_setschedprio(const struct dc_posix_env *env, struct dc_error *err, pthread_t thread, int prio);
//int dc_pthread_spin_destroy(const struct dc_posix_env *env, struct dc_error *err, pthread_spinlock_t *lock);
//int dc_pthread_spin_init(const struct dc_posix_env *env, struct dc_error *err, pthread_spinlock_t *lock, int pshared);
//int dc_pthread_spin_lock(const struct dc_posix_env *env, struct dc_error *err, pthread_spinlock_t *lock);
//int dc_pthread_spin_trylock(const struct dc_posix_env *env, struct dc_error *err, pthread_spinlock_t *lock);
//int dc_pthread_spin_unlock(const struct dc_posix_env *env, struct dc_error *err, pthread_spinlock_t *lock);
// int dc_pthread_mutexattr_getrobust(const struct dc_posix_env *env, struct dc_error *err, const pthread_mutexattr_t *restrict attr, int *restrict robust);
// int dc_pthread_condattr_getclock(const struct dc_posix_env *env, struct dc_error *err, const pthread_condattr_t *restrict attr, clockid_t *restrict clock_id);
// int dc_pthread_condattr_setclock(const struct dc_posix_env *env, struct dc_error *err, pthread_condattr_t *attr, clockid_t clock_id);
// int dc_pthread_getcpuclockid(const struct dc_posix_env *env, struct dc_error *err, pthread_t thread_id, clockid_t *clock_id);
// int dc_pthread_mutex_consistent(const struct dc_posix_env *env, struct dc_error *err, pthread_mutex_t *mutex);
// int dc_pthread_mutex_timedlock(const struct dc_posix_env *env, struct dc_error *err, pthread_mutex_t *restrict mutex, const struct timespec *restrict abstime);
// int dc_pthread_mutexattr_setrobust(const struct dc_posix_env *env, struct dc_error *err, pthread_mutexattr_t *attr, int robust);
// int dc_pthread_rwlock_timedrdlock(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *restrict rwlock, const struct timespec *restrict abstime);
// int dc_pthread_rwlock_timedwrlock(const struct dc_posix_env *env, struct dc_error *err, pthread_rwlock_t *restrict rwlock, const struct timespec *restrict abstime);


#endif //LIBDC_POSIX_PTHREAD_H
