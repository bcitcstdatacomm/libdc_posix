#ifndef LIBDC_POSIX_DC_STDIO_H
#define LIBDC_POSIX_DC_STDIO_H


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
#include <stdio.h>


#ifdef __cplusplus
extern "C" {
#endif


char *dc_ctermid(const struct dc_env *env, char *s);
FILE *dc_fdopen(const struct dc_env *env, struct dc_error *err, int fildes, const char *mode);
int dc_fileno(const struct dc_env *env, struct dc_error *err, FILE *stream);
void dc_flockfile(const struct dc_env *env, FILE *file);
FILE *dc_fmemopen(const struct dc_env *env, struct dc_error *err, void *restrict buf, size_t size, const char *restrict mode);
int dc_fseeko(const struct dc_env *env, struct dc_error *err, FILE *stream, off_t offset, int whence);
off_t dc_ftello(const struct dc_env *env, struct dc_error *err, FILE *stream);
int dc_ftrylockfile(const struct dc_env *env, struct dc_error *err, FILE *file);
void dc_funlockfile(const struct dc_env *env, FILE *file);
int dc_getc_unlocked(const struct dc_env *env, struct dc_error *err, FILE *stream);
int dc_getchar_unlocked(const struct dc_env *env, struct dc_error *err);
ssize_t dc_getdelim(const struct dc_env *env, struct dc_error *err, char **restrict lineptr, size_t *restrict n, int delimiter, FILE *restrict stream);
ssize_t dc_getline(const struct dc_env *env, struct dc_error *err, char **restrict lineptr, size_t *restrict n, FILE *restrict stream);
FILE *dc_open_memstream(const struct dc_env *env, struct dc_error *err, char **bufp, size_t *sizep);
int dc_pclose(const struct dc_env *env, struct dc_error *err, FILE *stream);
FILE *dc_popen(const struct dc_env *env, struct dc_error *err, const char *command, const char *mode);
int dc_putc_unlocked(const struct dc_env *env, struct dc_error *err, int c, FILE *stream);
int dc_putchar_unlocked(const struct dc_env *env, struct dc_error *err, int c);
int dc_renameat(const struct dc_env *env, struct dc_error *err, int oldfd, const char *old, int newfd, const char *new);
int dc_vdprintf(const struct dc_env *env, struct dc_error *err, int fildes, const char *restrict format, va_list ap);


#ifdef __cplusplus
}
#endif


#endif // LIBDC_POSIX_DC_STDIO_H
