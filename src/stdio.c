/*
 *Copyright 2021-2021 D'Arcy Smith.
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

#include "dc_stdio.h"

void dc_clearerr(const struct dc_posix_env *env, FILE *stream)
{
    DC_TRACE(env);
    errno = 0;
    clearerr(stream);
}

char *dc_ctermid(const struct dc_posix_env *env, char *s)
{
    char *ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = ctermid(s);

    return ret_val;
}

int dc_fclose(const struct dc_posix_env *env, struct dc_error *err, FILE *stream)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = fclose(stream);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

FILE *dc_fdopen(const struct dc_posix_env *env, struct dc_error *err, int fildes, const char *mode)
{
    FILE *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fdopen(fildes, mode);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_feof(const struct dc_posix_env *env, FILE *stream)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = feof(stream);

    return ret_val;
}

int dc_ferror(const struct dc_posix_env *env, FILE *stream)
{
    int ret_val;

    DC_TRACE(env);
    errno = 0;
    ret_val = ferror(stream);

    return ret_val;
}

int dc_fflush(const struct dc_posix_env *env, struct dc_error *err, FILE *stream)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fflush(stream);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_fgetc(const struct dc_posix_env *env, struct dc_error *err, FILE *stream)
{
    int ret_val;
    errno_t actual_error;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fgetc(stream);
    actual_error = errno;

    if(dc_ferror(env, stream))
    {
        DC_ERROR_RAISE_ERRNO(err, actual_error);
    }

    return ret_val;
}

int dc_fgetpos(const struct dc_posix_env *env, struct dc_error *err, FILE *restrict stream, fpos_t *restrict pos)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fgetpos(stream, pos);

    if(ret_val != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_fgets(const struct dc_posix_env *env, struct dc_error *err, char *restrict s, int n, FILE *restrict stream)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fgets(s, n, stream);

    if(ret_val == NULL)
    {
        errno_t temp_errno;

        temp_errno = errno;

        if(dc_ferror(env, stream))
        {
            DC_ERROR_RAISE_ERRNO(err, temp_errno);
        }
    }

    return ret_val;
}

int dc_fileno(const struct dc_posix_env *env, struct dc_error *err, FILE *stream)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fileno(stream);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

void dc_flockfile(const struct dc_posix_env *env, FILE *file)
{
    DC_TRACE(env);
    errno   = 0;
    flockfile(file);
}

FILE *dc_fmemopen(const struct dc_posix_env *env, struct dc_error *err, void *restrict buf, size_t size, const char *restrict mode)
{
    FILE *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fmemopen(buf, size, mode);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

FILE *dc_fopen(const struct dc_posix_env *env, struct dc_error *err, const char *restrict pathname, const char *restrict mode)
{
    FILE *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fopen(pathname, mode);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_fputc(const struct dc_posix_env *env, struct dc_error *err, int c, FILE *stream)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fputc(c, stream);

    if(ret_val == EOF)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_fputs(const struct dc_posix_env *env, struct dc_error *err, const char *restrict s, FILE *restrict stream)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fputs(s, stream);

    if(ret_val == EOF)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t dc_fread(const struct dc_posix_env *env, struct dc_error *err, void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream)
{
    size_t ret_val;
    errno_t actual_error;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fread(ptr, size, nitems, stream);
    actual_error = errno;

    if(dc_ferror(env, stream))
    {
        DC_ERROR_RAISE_ERRNO(err, actual_error);
    }

    return ret_val;
}

FILE *dc_freopen(const struct dc_posix_env *env, struct dc_error *err, const char *restrict pathname, const char *restrict mode, FILE *restrict stream)
{
    FILE *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = freopen(pathname, mode, stream);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_fseek(const struct dc_posix_env *env, struct dc_error *err, FILE *stream, long offset, int whence)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fseek(stream, offset, whence);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_fseeko(const struct dc_posix_env *env, struct dc_error *err, FILE *stream, off_t offset, int whence)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fseek(stream, offset, whence);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_fsetpos(const struct dc_posix_env *env, struct dc_error *err, FILE *stream, const fpos_t *pos)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fsetpos(stream, pos);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long dc_ftell(const struct dc_posix_env *env, struct dc_error *err, FILE *stream)
{
    long ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = ftell(stream);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

off_t dc_ftello(const struct dc_posix_env *env, struct dc_error *err, FILE *stream)
{
    off_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = ftello(stream);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_ftrylockfile(const struct dc_posix_env *env, FILE *file)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = ftrylockfile(file);

    return ret_val;
}

void dc_funlockfile(const struct dc_posix_env *env, FILE *file)
{
    DC_TRACE(env);
    errno   = 0;
    funlockfile(file);
}

size_t dc_fwrite(const struct dc_posix_env *env, struct dc_error *err, const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream)
{
    size_t ret_val;
    errno_t actual_error;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fwrite(ptr, size, nitems, stream);
    actual_error = errno;

    if(dc_ferror(env, stream))
    {
        DC_ERROR_RAISE_ERRNO(err, actual_error);
    }

    return ret_val;
}

int dc_getc(const struct dc_posix_env *env, struct dc_error *err, FILE *stream)
{
    int ret_val;
    errno_t actual_error;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getc(stream);
    actual_error = errno;

    if(dc_ferror(env, stream))
    {
        DC_ERROR_RAISE_ERRNO(err, actual_error);
    }

    return ret_val;
}

int dc_getchar(const struct dc_posix_env *env, struct dc_error *err)
{
    int ret_val;
    errno_t actual_error;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getchar();
    actual_error = errno;

    if(dc_ferror(env, stdin))
    {
        DC_ERROR_RAISE_ERRNO(err, actual_error);
    }

    return ret_val;
}

int dc_getc_unlocked(const struct dc_posix_env *env, struct dc_error *err, FILE *stream)
{
    int ret_val;
    errno_t actual_error;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getc_unlocked(stream);
    actual_error = errno;

    if(dc_ferror(env, stream))
    {
        DC_ERROR_RAISE_ERRNO(err, actual_error);
    }

    return ret_val;
}

int dc_getchar_unlocked(const struct dc_posix_env *env, struct dc_error *err)
{
    int ret_val;
    errno_t actual_error;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getchar_unlocked();
    actual_error = errno;

    if(dc_ferror(env, stdin))
    {
        DC_ERROR_RAISE_ERRNO(err, actual_error);
    }

    return ret_val;
}

ssize_t dc_getdelim(const struct dc_posix_env *env, struct dc_error *err, char **restrict lineptr, size_t *restrict n, int delimiter, FILE *restrict stream)
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getdelim(lineptr, n, delimiter, stream);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

ssize_t dc_getline(const struct dc_posix_env *env, struct dc_error *err, char **restrict lineptr, size_t *restrict n, FILE *restrict stream)
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getline(lineptr, n, stream);

    if(ret_val == -1 && dc_ferror(env, stream))
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_gets(const struct dc_posix_env *env, struct dc_error *err, char *s)
{
    char * ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = gets(s);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

FILE *dc_open_memstream(const struct dc_posix_env *env, struct dc_error *err, char **bufp, size_t *sizep)
{
    FILE *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = open_memstream(bufp, sizep);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_pclose(const struct dc_posix_env *env, struct dc_error *err, FILE *stream)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pclose(stream);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

void dc_perror(const struct dc_posix_env *env, const char *s)
{
    DC_TRACE(env);
    errno   = 0;
    perror(s);
}

FILE *dc_popen(const struct dc_posix_env *env, struct dc_error *err, const char *command, const char *mode)
{
    FILE *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = popen(command, mode);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_putc(const struct dc_posix_env *env, struct dc_error *err, int c, FILE *stream)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = putc(c, stream);

    if(ret_val == EOF)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_putchar(const struct dc_posix_env *env, struct dc_error *err, int c)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = putchar(c);

    if(ret_val == EOF)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_putc_unlocked(const struct dc_posix_env *env, struct dc_error *err, int c, FILE *stream)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = putc_unlocked(c, stream);

    if(ret_val == EOF)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_putchar_unlocked(const struct dc_posix_env *env, struct dc_error *err, int c)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = putchar_unlocked(c);

    if(ret_val == EOF)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_puts(const struct dc_posix_env *env, struct dc_error *err, const char *s)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = puts(s);

    if(ret_val == EOF)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_remove(const struct dc_posix_env *env, struct dc_error *err, const char *path)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = remove(path);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_rename(const struct dc_posix_env *env, struct dc_error *err, const char *old, const char *new)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = rename(old, new);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_renameat(const struct dc_posix_env *env, struct dc_error *err, int oldfd, const char *old, int newfd, const char *new)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = renameat(oldfd, old, newfd, new);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

void dc_rewind(const struct dc_posix_env *env, struct dc_error *err, FILE *stream)
{
    DC_TRACE(env);
    errno   = 0;

    rewind(stream);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }
}

void dc_setbuf(const struct dc_posix_env *env, struct dc_error *err, FILE *restrict stream, char *restrict buf)
{
    DC_TRACE(env);
    errno   = 0;

    setbuf(stream, buf);

    if(errno != 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }
}

int dc_setvbuf(const struct dc_posix_env *env, struct dc_error *err, FILE *restrict stream, char *restrict buf, int type, size_t size)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = setvbuf(stream, buf, type, size);

    if(ret_val == 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_tempnam(const struct dc_posix_env *env, struct dc_error *err, const char *dir, const char *pfx)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = tempnam(dir, pfx);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

FILE *dc_tmpfile(const struct dc_posix_env *env, struct dc_error *err)
{
    FILE *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = tmpfile();

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_tmpnam(const struct dc_posix_env *env, char *s)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = tmpnam(s);

    return ret_val;
}

int dc_ungetc(const struct dc_posix_env *env, int c, FILE *stream)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = ungetc(c, stream);

    return ret_val;
}
