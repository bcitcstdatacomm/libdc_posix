#ifndef LIBDC_POSIX_SYS_DC_SELECT_H
#define LIBDC_POSIX_SYS_DC_SELECT_H


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


#include <dc_env/env.h>
#include <sys/select.h>


#ifdef __cplusplus
extern "C" {
#endif


int dc_pselect(const struct dc_env *env, struct dc_error *err, int nfds, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict errorfds, const struct timespec *restrict timeout, const sigset_t *restrict sigmask);
int dc_select(const struct dc_env *env, struct dc_error *err, int nfds, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict errorfds, struct timeval *restrict timeout);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_SYS_DC_SELECT_H
