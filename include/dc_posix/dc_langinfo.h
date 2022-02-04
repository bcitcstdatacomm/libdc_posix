#ifndef LIBDC_POSIX_DC_LANGINFO_H
#define LIBDC_POSIX_DC_LANGINFO_H

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
#include <langinfo.h>
#if __has_include(<xlocale.h>)
    #include <xlocale.h>
#endif

char *dc_nl_langinfo(const struct dc_posix_env *env, nl_item item);
char *dc_nl_langinfo_l(const struct dc_posix_env *env, nl_item item, locale_t locale);

#endif // LIBDC_POSIX_DC_LANGINFO_H
