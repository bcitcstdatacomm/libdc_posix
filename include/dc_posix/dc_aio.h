#ifndef LIBDC_POSIX_DC_AIO_H
#define LIBDC_POSIX_DC_AIO_H


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
#include <aio.h>


#ifdef __cplusplus
extern "C" {
#endif


int dc_aio_cancel(const struct dc_env *env, struct dc_error *err, int fildes, struct aiocb *aiocbp);
int dc_aio_error(const struct dc_env *env, struct dc_error *err, const struct aiocb *aiocbp);
int dc_aio_read(const struct dc_env *env, struct dc_error *err, struct aiocb *aiocbp);
ssize_t dc_aio_return(const struct dc_env *env, struct dc_error *err, struct aiocb *aiocbp);
int dc_aio_suspend(const struct dc_env *env, struct dc_error *err, const struct aiocb *const list[], int nent, const struct timespec *timeout);
int dc_aio_write(const struct dc_env *env, struct dc_error *err, struct aiocb *aiocbp);
int dc_lio_listio(const struct dc_env *env, struct dc_error *err, int mode, struct aiocb *restrict const list[restrict], int nent, struct sigevent *restrict sig);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_AIO_H
