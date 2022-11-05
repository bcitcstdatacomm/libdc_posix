#ifndef LIBDC_POSIX_DC_SEMAPHPORE_H
#define LIBDC_POSIX_DC_SEMAPHPORE_H


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
#include <semaphore.h>


#ifdef __cplusplus
extern "C" {
#endif


int dc_sem_close(const struct dc_env *env, struct dc_error *err, sem_t *sem);
sem_t *dc_sem_open(const struct dc_env *env, struct dc_error *err, const char *name, int oflag, ...);
int dc_sem_post(const struct dc_env *env, struct dc_error *err, sem_t *sem);
int dc_sem_trywait(const struct dc_env *env, struct dc_error *err, sem_t *sem);
int dc_sem_unlink(const struct dc_env *env, struct dc_error *err, const char *name);
int dc_sem_wait(const struct dc_env *env, struct dc_error *err, sem_t *sem);


#ifdef __cplusplus
}
#endif


// not on macOS
// int dc_sem_timedwait(const struct dc_env *env, struct dc_error *err, sem_t *restrict sem, const struct timespec *restrict abstime);

// deprecated on macOS
// int dc_sem_destroy(const struct dc_env *env, struct dc_error *err, sem_t *sem);
// int dc_sem_getvalue(const struct dc_env *env, struct dc_error *err, sem_t *restrict sem, int *restrict sval);
// int dc_sem_init(const struct dc_env *env, struct dc_error *err, sem_t *sem, int pshared, unsigned value);


#endif // LIBDC_POSIX_DC_SEMAPHPORE_H
