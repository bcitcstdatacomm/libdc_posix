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

#include "dc_string.h"
#include <string.h>

// https://pubs.opengroup.org/onlinepubs/9699919799/functions/memcpy.html
void *dc_memcpy(const struct dc_posix_env *env, void * restrict s1, const void * restrict s2, size_t n)
{
    void *ret_val;

    DC_TRACE(env);
    ret_val = memcpy(s1, s2, n);

    return ret_val;
}

// https://pubs.opengroup.org/onlinepubs/9699919799/functions/memset.html
void *dc_memset(const struct dc_posix_env *env, void *s, int c, size_t n)
{
    void *ret_val;

    DC_TRACE(env);
    ret_val = memset(s, c, n);

    return ret_val;
}

// https://pubs.opengroup.org/onlinepubs/9699919799/functions/strcpy.html
char *dc_strcpy(const struct dc_posix_env *env, char * restrict s1, const char * restrict s2)
{
    char *ret_val;

    DC_TRACE(env);
    ret_val = strcpy(s1, s2);

    return ret_val;
}

// https://pubs.opengroup.org/onlinepubs/9699919799/functions/strcat.html
char *dc_strcat(const struct dc_posix_env *env, char * restrict s1, const char * restrcit s2)
{
  char *ret_val;
  
  DC_TRACE(env);
  ret_val = strcat(s1, s2);

  return ret_val;
}

// https://pubs.opengroup.org/onlinepubs/9699919799/functions/strlen.html
size_t dc_strlen(const struct dc_posix_env *env, const char *s)
{
    size_t ret_val;

    DC_TRACE(env);
    ret_val = strlen(s);

    return ret_val;
}

// https://pubs.opengroup.org/onlinepubs/9699919799/functions/strcmp.html
int dc_strcmp(const struct dc_posix_env *env, const char *s1, const char *s2)
{
    int ret_val;

    DC_TRACE(env);
    ret_val = strcmp(s1, s2);

    return ret_val;
}

// https://pubs.opengroup.org/onlinepubs/9699919799/functions/strncmp.html
int dc_strncmp(const struct dc_posix_env *env, const char *s1, const char *s2, size_t n)
{
    int ret_val;

    DC_TRACE(env);
    ret_val = strncmp(s1, s2, n);

    return ret_val;
}

// https://pubs.opengroup.org/onlinepubs/9699919799/functions/strtok.html
char *dc_strtok_r(const struct dc_posix_env *env, char * restrict s, const char * restrict sep, char ** restrict state)
{
    char *ret_val;

    DC_TRACE(env);
    ret_val = strtok_r(s, sep, state);

    return ret_val;
}
