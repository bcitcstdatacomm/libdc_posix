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

#include "dc_termios.h"

speed_t dc_cfgetispeed(const struct dc_posix_env *env, const struct termios *termios_p)
{
    speed_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = cfgetispeed(termios_p);

    return ret_val;
}

speed_t dc_cfgetospeed(const struct dc_posix_env *env, const struct termios *termios_p)
{
    speed_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = cfgetospeed(termios_p);

    return ret_val;
}

int dc_cfsetispeed(const struct dc_posix_env *env, struct dc_error *err, struct termios *termios_p, speed_t speed)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = cfsetispeed(termios_p, speed);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_cfsetospeed(const struct dc_posix_env *env, struct dc_error *err, struct termios *termios_p, speed_t speed)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = cfsetospeed(termios_p, speed);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_tcdrain(const struct dc_posix_env *env, struct dc_error *err, int fildes)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = tcdrain(fildes);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_tcflow(const struct dc_posix_env *env, struct dc_error *err, int fildes, int action)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = tcflow(fildes, action);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_tcflush(const struct dc_posix_env *env, struct dc_error *err, int fildes, int queue_selector)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = tcflush(fildes, queue_selector);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_tcgetattr(const struct dc_posix_env *env, struct dc_error *err, int fildes, struct termios *termios_p)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = tcgetattr(fildes, termios_p);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

pid_t dc_tcgetsid(const struct dc_posix_env *env, struct dc_error *err, int fildes)
{
    pid_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = tcgetsid(fildes);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_tcsendbreak(const struct dc_posix_env *env, struct dc_error *err, int fildes, int duration)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = tcsendbreak(fildes, duration);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}

int dc_tcsetattr(const struct dc_posix_env *env, struct dc_error *err, int fildes, int optional_actions, const struct termios *termios_p)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = tcsetattr(fildes, optional_actions, termios_p);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, ret_val);
    }

    return ret_val;
}
