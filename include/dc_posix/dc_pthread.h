#ifndef LIBDC_POSIX_DC_PTHREAD_H
#define LIBDC_POSIX_DC_PTHREAD_H


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


#include <dc_env/env.h>
#include <pthread.h>


#ifdef __cplusplus
extern "C" {
#endif


int dc_pthread_atfork(const struct dc_env *env, struct dc_error *err, void (*prepare)(void), void (*parent)(void), void (*child)(void));
int dc_pthread_attr_destroy(const struct dc_env *env, struct dc_error *err, pthread_attr_t *attr);
int dc_pthread_attr_getdetachstate(const struct dc_env *env, struct dc_error *err, const pthread_attr_t *attr, int *detachstate);
int dc_pthread_attr_getguardsize(const struct dc_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, size_t *restrict guardsize);
int dc_pthread_attr_getschedparam(const struct dc_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, struct sched_param *restrict param);
int dc_pthread_attr_init(const struct dc_env *env, struct dc_error *err, pthread_attr_t *attr);
int dc_pthread_attr_setdetachstate(const struct dc_env *env, struct dc_error *err, pthread_attr_t *attr, int detachstate);
int dc_pthread_attr_setguardsize(const struct dc_env *env, struct dc_error *err, const pthread_attr_t *restrict attr, size_t guardsize);
int dc_pthread_attr_setschedparam(const struct dc_env *env, struct dc_error *err, pthread_attr_t *restrict attr, const struct sched_param *restrict param);
int dc_pthread_cancel(const struct dc_env *env, struct dc_error *err, pthread_t thread);
int dc_pthread_cond_broadcast(const struct dc_env *env, struct dc_error *err, pthread_cond_t *cond);
int dc_pthread_cond_destroy(const struct dc_env *env, struct dc_error *err, pthread_cond_t *cond);
int dc_pthread_cond_init(const struct dc_env *env, struct dc_error *err, pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr);
int dc_pthread_cond_signal(const struct dc_env *env, struct dc_error *err, pthread_cond_t *cond);
int dc_pthread_cond_timedwait(const struct dc_env *env, struct dc_error *err, pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex, const struct timespec *restrict abstime);
int dc_pthread_cond_wait(const struct dc_env *env, struct dc_error *err, pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);
int dc_pthread_condattr_destroy(const struct dc_env *env, struct dc_error *err, pthread_condattr_t *attr);
int dc_pthread_condattr_init(const struct dc_env *env, struct dc_error *err, pthread_condattr_t *attr);
int dc_pthread_create(const struct dc_env *env, struct dc_error *err, pthread_t *restrict thread, const pthread_attr_t *restrict attr, void *(*start_routine)(void*), void *restrict arg);
int dc_pthread_detach(const struct dc_env *env, struct dc_error *err, pthread_t thread);
int dc_pthread_equal(const struct dc_env *env, pthread_t t1, pthread_t t2);
void dc_pthread_exit(const struct dc_env *env, void *value_ptr);
void *dc_pthread_getspecific(const struct dc_env *env, pthread_key_t key);
int dc_pthread_join(const struct dc_env *env, struct dc_error *err, pthread_t thread, void **value_ptr);
int dc_pthread_key_create(const struct dc_env *env, struct dc_error *err, pthread_key_t *key, void (*destructor)(void*));
int dc_pthread_key_delete(const struct dc_env *env, struct dc_error *err, pthread_key_t key);
int dc_pthread_mutex_destroy(const struct dc_env *env, struct dc_error *err, pthread_mutex_t *mutex);
int dc_pthread_mutex_init(const struct dc_env *env, struct dc_error *err, pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
int dc_pthread_mutex_lock(const struct dc_env *env, struct dc_error *err, pthread_mutex_t *mutex);
int dc_pthread_mutex_trylock(const struct dc_env *env, struct dc_error *err, pthread_mutex_t *mutex);
int dc_pthread_mutex_unlock(const struct dc_env *env, struct dc_error *err, pthread_mutex_t *mutex);
int dc_pthread_mutexattr_destroy(const struct dc_env *env, struct dc_error *err, pthread_mutexattr_t *attr);
int dc_pthread_mutexattr_gettype(const struct dc_env *env, struct dc_error *err, const pthread_mutexattr_t *restrict attr, int *restrict type);
int dc_pthread_mutexattr_init(const struct dc_env *env, struct dc_error *err, pthread_mutexattr_t *attr);
int dc_pthread_mutexattr_settype(const struct dc_env *env, struct dc_error *err, pthread_mutexattr_t *attr, int type);
int dc_pthread_once(const struct dc_env *env, struct dc_error *err, pthread_once_t *once_control, void (*init_routine)(void));
int dc_pthread_rwlock_destroy(const struct dc_env *env, struct dc_error *err, pthread_rwlock_t *rwlock);
int dc_pthread_rwlock_init(const struct dc_env *env, struct dc_error *err, pthread_rwlock_t *restrict rwlock, const pthread_rwlockattr_t *restrict attr);
int dc_pthread_rwlock_rdlock(const struct dc_env *env, struct dc_error *err, pthread_rwlock_t *rwlock);
int dc_pthread_rwlock_tryrdlock(const struct dc_env *env, struct dc_error *err, pthread_rwlock_t *rwlock);
int dc_pthread_rwlock_trywrlock(const struct dc_env *env, struct dc_error *err, pthread_rwlock_t *rwlock);
int dc_pthread_rwlock_unlock(const struct dc_env *env, struct dc_error *err, pthread_rwlock_t *rwlock);
int dc_pthread_rwlock_wrlock(const struct dc_env *env, struct dc_error *err, pthread_rwlock_t *rwlock);
int dc_pthread_rwlockattr_destroy(const struct dc_env *env, struct dc_error *err, pthread_rwlockattr_t *attr);
int dc_pthread_rwlockattr_init(const struct dc_env *env, struct dc_error *err, pthread_rwlockattr_t *attr);
pthread_t dc_pthread_self(const struct dc_env *env);
int dc_pthread_setcancelstate(const struct dc_env *env, struct dc_error *err, int state, int *oldstate);
int dc_pthread_setcanceltype(const struct dc_env *env, struct dc_error *err, int type, int *oldtype);
int dc_pthread_setspecific(const struct dc_env *env, struct dc_error *err, pthread_key_t key, const void *value);
void dc_pthread_testcancel(const struct dc_env *env);


#ifdef __cplusplus
}
#endif


// not on macOS
// int dc_pthread_barrier_destroy(const struct dc_env *env, struct dc_error *err, pthread_barrier_t *barrier);
// int dc_pthread_barrier_init(const struct dc_env *env, struct dc_error *err, pthread_barrier_t *restrict barrier, const pthread_barrierattr_t *restrict attr, unsigned count);
// int dc_pthread_barrier_wait(const struct dc_env *env, struct dc_error *err, pthread_barrier_t *barrier);
// int dc_pthread_barrierattr_destroy(const struct dc_env *env, struct dc_error *err, pthread_barrierattr_t *attr);
// int dc_pthread_barrierattr_init(const struct dc_env *env, struct dc_error *err, pthread_barrierattr_t *attr);
// int dc_pthread_spin_destroy(const struct dc_env *env, struct dc_error *err, pthread_spinlock_t *lock);
// int dc_pthread_spin_init(const struct dc_env *env, struct dc_error *err, pthread_spinlock_t *lock, int pshared);
// int dc_pthread_spin_lock(const struct dc_env *env, struct dc_error *err, pthread_spinlock_t *lock);
// int dc_pthread_spin_trylock(const struct dc_env *env, struct dc_error *err, pthread_spinlock_t *lock);
// int dc_pthread_spin_unlock(const struct dc_env *env, struct dc_error *err, pthread_spinlock_t *lock);
// int dc_pthread_mutex_timedlock(const struct dc_env *env, struct dc_error *err, pthread_mutex_t *restrict mutex, const struct timespec *restrict abstime);
// int dc_pthread_mutex_consistent(const struct dc_env *env, struct dc_error *err, pthread_mutex_t *mutex);
// int dc_pthread_mutexattr_getrobust(const struct dc_env *env, struct dc_error *err, const pthread_mutexattr_t *restrict attr, int *restrict robust);
// int dc_pthread_mutexattr_setrobust(const struct dc_env *env, struct dc_error *err, pthread_mutexattr_t *attr, int robust);
// int dc_pthread_condattr_setclock(const struct dc_env *env, struct dc_error *err, pthread_condattr_t *attr, clockid_t clock_id);
// int dc_pthread_condattr_getclock(const struct dc_env *env, struct dc_error *err, const pthread_condattr_t *restrict attr, clockid_t *restrict clock_id);
// int dc_pthread_rwlock_timedrdlock(const struct dc_env *env, struct dc_error *err, pthread_rwlock_t *restrict rwlock, const struct timespec *restrict abstime);
// int dc_pthread_rwlock_timedwrlock(const struct dc_env *env, struct dc_error *err, pthread_rwlock_t *restrict rwlock, const struct timespec *restrict abstime);


#endif // LIBDC_POSIX_DC_PTHREAD_H
