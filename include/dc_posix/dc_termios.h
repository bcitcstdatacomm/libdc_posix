#ifndef LIBDC_POSIX_DC_TERMIOS_H
#define LIBDC_POSIX_DC_TERMIOS_H


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
#include <termios.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 *
 * @param env
 * @param termios_p
 * @return
 */
speed_t dc_cfgetispeed(const struct dc_posix_env *env, const struct termios *termios_p);

/**
 *
 * @param env
 * @param termios_p
 * @return
 */
speed_t dc_cfgetospeed(const struct dc_posix_env *env, const struct termios *termios_p);

/**
 *
 * @param env
 * @param err
 * @param termios_p
 * @param speed
 * @return
 */
int dc_cfsetispeed(const struct dc_posix_env *env, struct dc_error *err, struct termios *termios_p, speed_t speed);

/**
 *
 * @param env
 * @param err
 * @param termios_p
 * @param speed
 * @return
 */
int dc_cfsetospeed(const struct dc_posix_env *env, struct dc_error *err, struct termios *termios_p, speed_t speed);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @return
 */
int dc_tcdrain(const struct dc_posix_env *env, struct dc_error *err, int fildes);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param action
 * @return
 */
int dc_tcflow(const struct dc_posix_env *env, struct dc_error *err, int fildes, int action);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param queue_selector
 * @return
 */
int dc_tcflush(const struct dc_posix_env *env, struct dc_error *err, int fildes, int queue_selector);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param termios_p
 * @return
 */
int dc_tcgetattr(const struct dc_posix_env *env, struct dc_error *err, int fildes, struct termios *termios_p);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @return
 */
pid_t dc_tcgetsid(const struct dc_posix_env *env, struct dc_error *err, int fildes);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param duration
 * @return
 */
int dc_tcsendbreak(const struct dc_posix_env *env, struct dc_error *err, int fildes, int duration);

/**
 *
 * @param env
 * @param err
 * @param fildes
 * @param optional_actions
 * @param termios_p
 * @return
 */
int dc_tcsetattr(const struct dc_posix_env *env, struct dc_error *err, int fildes, int optional_actions, const struct termios *termios_p);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_TERMIOS_H
