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


#include "dc_posix_env.h"
#include <signal.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 *
 * @param env
 * @param err
 * @param pid
 * @param sig
 * @return
 */
int dc_kill(const struct dc_posix_env *env, struct dc_error *err, pid_t pid,
            int sig);

/**
 *
 * @param env
 * @param err
 * @param pgrp
 * @param sig
 * @return
 */
int dc_killpg(const struct dc_posix_env *env, struct dc_error *err, pid_t pgrp,
              int sig);

/**
 *
 * @param env
 * @param err
 * @param signum
 * @param message
 */
void dc_psignal(const struct dc_posix_env *env, struct dc_error *err,
                int signum, const char *message);

/**
 *
 * @param env
 * @param err
 * @param thread
 * @param sig
 * @return
 */
int dc_pthread_kill(const struct dc_posix_env *env, struct dc_error *err,
                    pthread_t thread, int sig);

/**
 *
 * @param env
 * @param err
 * @param how
 * @param set
 * @param oset
 * @return
 */
int dc_pthread_sigmask(const struct dc_posix_env *env, struct dc_error *err,
                       int how, const sigset_t *restrict set,
                       sigset_t *restrict oset);

/**
 *
 * @param env
 * @param err
 * @param sig
 * @return
 */
int dc_raise(const struct dc_posix_env *env, struct dc_error *err, int sig);

/**
 *
 * @param env
 * @param err
 * @param sig
 * @param act
 * @param oact
 * @return
 */
int dc_sigaction(const struct dc_posix_env *env, struct dc_error *err, int sig,
                 const struct sigaction *restrict act,
                 struct sigaction *restrict oact);

/**
 *
 * @param env
 * @param err
 * @param set
 * @param signo
 * @return
 */
int dc_sigaddset(const struct dc_posix_env *env, struct dc_error *err,
                 sigset_t *set, int signo);

/**
 *
 * @param env
 * @param err
 * @param ss
 * @param oss
 * @return
 */
int dc_sigaltstack(const struct dc_posix_env *env, struct dc_error *err,
                   const stack_t *restrict ss, stack_t *restrict oss);

/**
 *
 * @param env
 * @param err
 * @param set
 * @param signo
 * @return
 */
int dc_sigdelset(const struct dc_posix_env *env, struct dc_error *err,
                 sigset_t *set, int signo);

/**
 *
 * @param env
 * @param err
 * @param set
 * @return
 */
int dc_sigemptyset(const struct dc_posix_env *env, struct dc_error *err,
                   sigset_t *set);

/**
 *
 * @param env
 * @param err
 * @param set
 * @return
 */
int dc_sigfillset(const struct dc_posix_env *env, struct dc_error *err,
                  sigset_t *set);

/**
 *
 * @param env
 * @param err
 * @param set
 * @param signo
 * @return
 */
int dc_sigismember(const struct dc_posix_env *env, struct dc_error *err,
                   const sigset_t *set, int signo);

/**
 *
 * @param env
 * @param err
 * @param sig
 * @param func
 * @return
 */
void (*dc_signal(const struct dc_posix_env *env, struct dc_error *err, int sig,
                 void (*func)(int)))(int);

/**
 *
 * @param env
 * @param err
 * @param set
 * @return
 */
int dc_sigpending(const struct dc_posix_env *env, struct dc_error *err,
                  sigset_t *set);

/**
 *
 * @param env
 * @param err
 * @param how
 * @param set
 * @param oset
 * @return
 */
int dc_sigprocmask(const struct dc_posix_env *env, struct dc_error *err,
                   int how, const sigset_t *restrict set,
                   sigset_t *restrict oset);

/**
 *
 * @param env
 * @param err
 * @param sigmask
 * @return
 */
int dc_sigsuspend(const struct dc_posix_env *env, struct dc_error *err,
                  const sigset_t *sigmask);

/**
 *
 * @param env
 * @param err
 * @param set
 * @param sig
 * @return
 */
int dc_sigwait(const struct dc_posix_env *env, struct dc_error *err,
               const sigset_t *restrict set, int *restrict sig);

#ifdef __cplusplus
}
#endif


// obselete
// int sighold(int sig);
// int sigignore(int sig);
// int sigpause(int sig);
// int sigrelse(int sig);
// void (*sigset(int sig, void (*disp)(int)))(int);
// int siginterrupt(int sig, int flag);

// These do not exist on macOS
// int dc_sigtimedwait(const struct dc_posix_env *env, struct dc_error *err, const sigset_t *restrict set, siginfo_t *restrict info, const struct timespec *restrict timeout);
// int dc_sigwaitinfo(const struct dc_posix_env *env, struct dc_error *err, const sigset_t *restrict set, siginfo_t *restrict info);
// void psiginfo(const struct dc_posix_env *env, struct dc_error *err, const siginfo_t *pinfo, const char *message);


#endif // LIBDC_POSIX_DC_SIGNAL_H
