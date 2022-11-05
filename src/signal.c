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


#include "dc_posix/dc_signal.h"


int dc_kill(const struct dc_env *env, struct dc_error *err, pid_t pid, int sig)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = kill(pid, sig);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_pthread_kill(const struct dc_env *env, struct dc_error *err, pthread_t thread, int sig)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = pthread_kill(thread, sig);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_pthread_sigmask(const struct dc_env *env, struct dc_error *err, int how, const sigset_t *restrict set, sigset_t *restrict oset)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = pthread_sigmask(how, set, oset);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_sigaction(const struct dc_env *env, struct dc_error *err, int sig, const struct sigaction *restrict act, struct sigaction *restrict oact)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sigaction(sig, act, oact);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sigaddset(const struct dc_env *env, struct dc_error *err, sigset_t *set, int signo)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sigaddset(set, signo);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sigdelset(const struct dc_env *env, struct dc_error *err, sigset_t *set, int signo)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sigdelset(set, signo);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sigemptyset(const struct dc_env *env, struct dc_error *err, sigset_t *set)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sigemptyset(set);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sigfillset(const struct dc_env *env, struct dc_error *err, sigset_t *set)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sigfillset(set);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sigismember(const struct dc_env *env, struct dc_error *err, const sigset_t *set, int signo)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sigismember(set, signo);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sigpending(const struct dc_env *env, struct dc_error *err, sigset_t *set)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sigpending(set);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sigprocmask(const struct dc_env *env, struct dc_error *err, int how, const sigset_t *restrict set, sigset_t *restrict oset)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sigprocmask(how, set, oset);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sigsuspend(const struct dc_env *env, struct dc_error *err, const sigset_t *sigmask)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sigsuspend(sigmask);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_sigwait(const struct dc_env *env, struct dc_error *err, const sigset_t *restrict set, int *restrict sig)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = sigwait(set, sig);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}
