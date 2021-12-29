#ifndef LIBDC_POSIX_DC_STDIO_H
#define LIBDC_POSIX_DC_STDIO_H

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
#include <stdio.h>

void dc_clearerr(const struct dc_posix_env *env, FILE *stream);
char *dc_ctermid(const struct dc_posix_env *env, char *s);
int dc_fclose(const struct dc_posix_env *env, struct dc_error * err, FILE *stream);
FILE *dc_fdopen(const struct dc_posix_env *env, struct dc_error * err, int fildes, const char *mode);
int dc_feof(const struct dc_posix_env *env, FILE *stream);
int dc_ferror(const struct dc_posix_env *env, FILE *stream);
int dc_fflush(const struct dc_posix_env *env, struct dc_error * err, FILE *stream);
int dc_fgetc(const struct dc_posix_env *env, struct dc_error * err, FILE *stream);
int dc_fgetpos(const struct dc_posix_env *env, struct dc_error * err, FILE *restrict stream, fpos_t *restrict pos);
char *dc_fgets(const struct dc_posix_env *env, struct dc_error * err, char *restrict s, int n, FILE *restrict stream);
int dc_fileno(const struct dc_posix_env *env, struct dc_error * err, FILE *stream);
void dc_flockfile(const struct dc_posix_env *env, FILE *file);
FILE *dc_fmemopen(const struct dc_posix_env *env, struct dc_error * err, void *restrict buf, size_t size, const char *restrict mode);
FILE *dc_fopen(const struct dc_posix_env *env, struct dc_error * err, const char *restrict pathname, const char *restrict mode);
int dc_fputc(const struct dc_posix_env *env, struct dc_error * err, int c, FILE *stream);
int dc_fputs(const struct dc_posix_env *env, struct dc_error * err, const char *restrict s, FILE *restrict stream);
size_t dc_fread(const struct dc_posix_env *env, struct dc_error * err, void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
FILE *dc_freopen(const struct dc_posix_env *env, struct dc_error * err, const char *restrict pathname, const char *restrict mode, FILE *restrict stream);
int dc_fseek(const struct dc_posix_env *env, struct dc_error * err, FILE *stream, long offset, int whence);
int dc_fseeko(const struct dc_posix_env *env, struct dc_error * err, FILE *stream, off_t offset, int whence);
int dc_fsetpos(const struct dc_posix_env *env, struct dc_error * err, FILE *stream, const fpos_t *pos);
long dc_ftell(const struct dc_posix_env *env, struct dc_error * err, FILE *stream);
off_t dc_ftello(const struct dc_posix_env *env, struct dc_error * err, FILE *stream);
int dc_ftrylockfile(const struct dc_posix_env *env, FILE *file);
void dc_funlockfile(const struct dc_posix_env *env, FILE *file);
size_t dc_fwrite(const struct dc_posix_env *env, struct dc_error * err, const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
int dc_getc(const struct dc_posix_env *env, struct dc_error * err, FILE *stream);
int dc_getchar(const struct dc_posix_env *env, struct dc_error * err);
int dc_getc_unlocked(const struct dc_posix_env *env, struct dc_error * err, FILE *stream);
int dc_getchar_unlocked(const struct dc_posix_env *env, struct dc_error * err);
ssize_t dc_getdelim(const struct dc_posix_env *env, struct dc_error * err, char **restrict lineptr, size_t *restrict n, int delimiter, FILE *restrict stream);
ssize_t dc_getline(const struct dc_posix_env *env, struct dc_error * err, char **restrict lineptr, size_t *restrict n, FILE *restrict stream);
char *dc_gets(const struct dc_posix_env *env, struct dc_error * err, char *s);
FILE *dc_open_memstream(const struct dc_posix_env *env, struct dc_error * err, char **bufp, size_t *sizep);
int dc_pclose(const struct dc_posix_env *env, struct dc_error * err, FILE *stream);
void dc_perror(const struct dc_posix_env *env, const char *s);
FILE *dc_popen(const struct dc_posix_env *env, struct dc_error * err, const char *command, const char *mode);
int dc_putc(const struct dc_posix_env *env, struct dc_error * err, int c, FILE *stream);
int dc_putchar(const struct dc_posix_env *env, struct dc_error * err, int c);
int dc_putc_unlocked(const struct dc_posix_env *env, struct dc_error * err, int c, FILE *stream);
int dc_putchar_unlocked(const struct dc_posix_env *env, struct dc_error * err, int c);
int dc_puts(const struct dc_posix_env *env, struct dc_error * err, const char *s);
int dc_remove(const struct dc_posix_env *env, struct dc_error * err, const char *path);
int dc_rename(const struct dc_posix_env *env, struct dc_error * err, const char *old, const char *new);
int dc_renameat(const struct dc_posix_env *env, struct dc_error * err, int oldfd, const char *old, int newfd, const char *new);
void dc_rewind(const struct dc_posix_env *env, struct dc_error * err, FILE *stream);
void dc_setbuf(const struct dc_posix_env *env, struct dc_error * err, FILE *restrict stream, char *restrict buf);
int dc_setvbuf(const struct dc_posix_env *env, struct dc_error * err, FILE *restrict stream, char *restrict buf, int type, size_t size);
char *dc_tempnam(const struct dc_posix_env *env, struct dc_error * err, const char *dir, const char *pfx);
FILE *dc_tmpfile(const struct dc_posix_env *env, struct dc_error * err);
char *dc_tmpnam(const struct dc_posix_env *env, char *s);
int dc_ungetc(const struct dc_posix_env *env, int c, FILE *stream);

#endif // LIBDC_POSIX_DC_STDIO_H
