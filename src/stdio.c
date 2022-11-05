/*
 *Copyright 2021-2022 D'Arcy Smith.
 *
 *Licensed under the Apache License, Version 2.0 (the "License");
 *you may not use this file except in compliance with the License.
 *You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *Unless required by applicable law or agreed to in writing, software
 *distributed under the License is distributed on an "AS IS" BASIS,
 *WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *See the License for the specific language governing permissions and
 *limitations under the License.
 */


#include "dc_posix/dc_stdio.h"
#include <dc_c/dc_stdio.h>


char *dc_ctermid(const struct dc_env *env, char *s)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = ctermid(s);

    return ret_val;
}

FILE *dc_fdopen(const struct dc_env *env, struct dc_error *err, int fildes, const char *mode)
{
    FILE *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = fdopen(fildes, mode);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_fileno(const struct dc_env *env, struct dc_error *err, FILE *stream)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = fileno(stream);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

void dc_flockfile(const struct dc_env *env, FILE *file)
{
    DC_TRACE(env);
    errno = 0;
    flockfile(file);
}

FILE *dc_fmemopen(const struct dc_env *env, struct dc_error *err, void *restrict buf, size_t size, const char *restrict mode)
{
    FILE *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = fmemopen(buf, size, mode);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_fseeko(const struct dc_env *env, struct dc_error *err, FILE *stream, off_t offset, int whence)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = fseeko(stream, offset, whence);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

off_t dc_ftello(const struct dc_env *env, struct dc_error *err, FILE *stream)
{
    off_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = ftello(stream);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_ftrylockfile(const struct dc_env *env, FILE *file)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = ftrylockfile(file);

    if(ret_val != 0)
    {
        // TODO: what?
    }

    return ret_val;
}

void dc_funlockfile(const struct dc_env *env, FILE *file)
{
    DC_TRACE(env);
    errno = 0;
    funlockfile(file);
}

int dc_getc_unlocked(const struct dc_env *env, struct dc_error *err, FILE *stream)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getc_unlocked(stream);

    if(ret_val == EOF && errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_getchar_unlocked(const struct dc_env *env, struct dc_error *err)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getchar_unlocked();

    if(ret_val == EOF && errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

ssize_t dc_getdelim(const struct dc_env *env, struct dc_error *err, char **restrict lineptr, size_t *restrict n, int delimiter, FILE *restrict stream)
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getdelim(lineptr, n, delimiter, stream);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

ssize_t dc_getline(const struct dc_env *env, struct dc_error *err, char **restrict lineptr, size_t *restrict n, FILE *restrict stream)
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = getline(lineptr, n, stream);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

FILE *dc_open_memstream(const struct dc_env *env, struct dc_error *err, char **bufp, size_t *sizep)
{
    FILE *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = open_memstream(bufp, sizep);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_pclose(const struct dc_env *env, struct dc_error *err, FILE *stream)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = pclose(stream);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

FILE *dc_popen(const struct dc_env *env, struct dc_error *err, const char *command, const char *mode)
{
    FILE *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = popen(command, mode);     // NOLINT(cert-env33-c)

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_putc_unlocked(const struct dc_env *env, struct dc_error *err, int c, FILE *stream)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = putc_unlocked(c, stream);

    if(ret_val == EOF)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_putchar_unlocked(const struct dc_env *env, struct dc_error *err, int c)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = putchar_unlocked(c);

    if(ret_val == EOF)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_renameat(const struct dc_env *env, struct dc_error *err, int oldfd, const char *old, int newfd, const char *new)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = renameat(oldfd, old, newfd, new);

    if(ret_val == EOF)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_vdprintf(const struct dc_env *env, struct dc_error *err, int fildes, const char *restrict format, va_list ap)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
    ret_val = vdprintf(fildes, format, ap);
#pragma GCC diagnostic pop

    if(ret_val < 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
