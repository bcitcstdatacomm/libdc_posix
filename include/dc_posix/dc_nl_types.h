#ifndef LIBDC_POSIX_DC_NL_TYPES_H
#define LIBDC_POSIX_DC_NL_TYPES_H


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
#include <nl_types.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 *
 * @param env
 * @param err
 * @param catd
 * @return
 */
int dc_catclose(const struct dc_posix_env *env, struct dc_error *err,nl_catd catd);

/**
 *
 * @param env
 * @param err
 * @param catd
 * @param set_id
 * @param msg_id
 * @param s
 * @return
 */
char *dc_catgets(const struct dc_posix_env *env, struct dc_error *err,nl_catd catd, int set_id, int msg_id, const char *s);

/**
 *
 * @param env
 * @param err
 * @param name
 * @param oflag
 * @return
 */
nl_catd dc_catopen(const struct dc_posix_env *env, struct dc_error *err,const char *name, int oflag);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_NL_TYPES_H
