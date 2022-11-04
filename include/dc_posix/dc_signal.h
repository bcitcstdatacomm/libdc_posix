#ifndef LIBDC_POSIX_DC_SIGNAL_H
#define LIBDC_POSIX_DC_SIGNAL_H


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
#include <signal.h>


#ifdef __cplusplus
extern "C" {
#endif


int dc_kill(const struct dc_env *env, struct dc_error *err, pid_t pid, int sig);
int dc_pthread_kill(const struct dc_env *env, struct dc_error *err, pthread_t thread, int sig);
int dc_pthread_sigmask(const struct dc_env *env, struct dc_error *err, int how, const sigset_t *restrict set, sigset_t *restrict oset);
int dc_sigaction(const struct dc_env *env, struct dc_error *err, int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);
int dc_sigaddset(const struct dc_env *env, struct dc_error *err, sigset_t *set, int signo);
int dc_sigdelset(const struct dc_env *env, struct dc_error *err, sigset_t *set, int signo);
int dc_sigemptyset(const struct dc_env *env, struct dc_error *err, sigset_t *set);
int dc_sigfillset(const struct dc_env *env, struct dc_error *err, sigset_t *set);
int dc_sigismember(const struct dc_env *env, struct dc_error *err, const sigset_t *set, int signo);
int dc_sigpending(const struct dc_env *env, struct dc_error *err, sigset_t *set);
int dc_sigprocmask(const struct dc_env *env, struct dc_error *err, int how, const sigset_t *restrict set, sigset_t *restrict oset);
int dc_sigsuspend(const struct dc_env *env, struct dc_error *err, const sigset_t *sigmask);
int dc_sigwait(const struct dc_env *env, struct dc_error *err, const sigset_t *restrict set, int *restrict sig);


#ifdef __cplusplus
}
#endif


// not on macOS
// int dc_sigtimedwait(const struct dc_env *env, struct dc_error *err, const sigset_t *restrict set, siginfo_t *restrict info, const struct timespec *restrict timeout);
// void dc_psiginfo(const struct dc_env *env, struct dc_error *err, const siginfo_t *pinfo, const char *message);
// void dc_psignal(const struct dc_env *env, struct dc_error *err, int signum, const char *message);
// int dc_sigqueue(const struct dc_env *env, struct dc_error *err, pid_t pid, int signo, union sigval value);
// int dc_sigwaitinfo(const struct dc_env *env, struct dc_error *err, const sigset_t *restrict set, siginfo_t *restrict info);


#endif // LIBDC_POSIX_DC__H
