#ifndef LIBDC_POSIX_DC_SIGNAL_H
#define LIBDC_POSIX_DC_SIGNAL_H

/*
 * Copyright 2021-2021 D'Arcy Smith.
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
#include <signal.h>

int dc_kill(const struct dc_posix_env *env, struct dc_error *err, pid_t pid,
            int sig);
int dc_killpg(const struct dc_posix_env *env, struct dc_error *err, pid_t pgrp,
              int sig);
// void dc_psiginfo(const struct dc_posix_env *env, struct dc_error *err, const
// siginfo_t *pinfo, const char *message);
void dc_psignal(const struct dc_posix_env *env, struct dc_error *err,
                int signum, const char *message);
int dc_pthread_kill(const struct dc_posix_env *env, struct dc_error *err,
                    pthread_t thread, int sig);
int dc_pthread_sigmask(const struct dc_posix_env *env, struct dc_error *err,
                       int how, const sigset_t *restrict set,
                       sigset_t *restrict oset);
int dc_raise(const struct dc_posix_env *env, struct dc_error *err, int sig);
int dc_sigaction(const struct dc_posix_env *env, struct dc_error *err, int sig,
                 const struct sigaction *restrict act,
                 struct sigaction *restrict oact);
int dc_sigaddset(const struct dc_posix_env *env, struct dc_error *err,
                 sigset_t *set, int signo);
int dc_sigaltstack(const struct dc_posix_env *env, struct dc_error *err,
                   const stack_t *restrict ss, stack_t *restrict oss);
int dc_sigdelset(const struct dc_posix_env *env, struct dc_error *err,
                 sigset_t *set, int signo);
int dc_sigemptyset(const struct dc_posix_env *env, struct dc_error *err,
                   sigset_t *set);
int dc_sigfillset(const struct dc_posix_env *env, struct dc_error *err,
                  sigset_t *set);
int dc_siginterrupt(const struct dc_posix_env *env, struct dc_error *err,
                    int sig, int flag);
int dc_sigismember(const struct dc_posix_env *env, struct dc_error *err,
                   const sigset_t *set, int signo);
void (*dc_signal(const struct dc_posix_env *env, struct dc_error *err, int sig,
                 void (*func)(int)))(int);
int dc_sigpending(const struct dc_posix_env *env, struct dc_error *err,
                  sigset_t *set);
int dc_sigprocmask(const struct dc_posix_env *env, struct dc_error *err,
                   int how, const sigset_t *restrict set,
                   sigset_t *restrict oset);
int dc_sigsuspend(const struct dc_posix_env *env, struct dc_error *err,
                  const sigset_t *sigmask);
// int dc_sigtimedwait(const struct dc_posix_env *env, struct dc_error *err,
// const sigset_t *restrict set, siginfo_t *restrict info, const struct timespec
// *restrict timeout);
int dc_sigwait(const struct dc_posix_env *env, struct dc_error *err,
               const sigset_t *restrict set, int *restrict sig);
// int dc_sigwaitinfo(const struct dc_posix_env *env, struct dc_error *err,
// const sigset_t *restrict set, siginfo_t *restrict info);

#endif // LIBDC_POSIX_DC_SIGNAL_H
