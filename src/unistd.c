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

#include "dc_unistd.h"
#include <unistd.h>
#if __has_include(<crypt.h>)
    #include <crypt.h>
#endif

int dc_access(const struct dc_posix_env *env, struct dc_error *err, const char *path, int amode)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = access(path, amode);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

unsigned dc_alarm(const struct dc_posix_env *env, unsigned seconds)
{
    unsigned ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = alarm(seconds);

    return ret_val;
}

int dc_chdir(const struct dc_posix_env *env, struct dc_error *err, const char *path)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = chdir(path);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_chown(const struct dc_posix_env *env, struct dc_error *err, const char *path, uid_t owner, gid_t group)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = chown(path, owner, group);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_dc_close(const struct dc_posix_env *env, struct dc_error *err, int fildes)
{
    return dc_close(env, err, fildes);
}

int dc_close(const struct dc_posix_env *env, struct dc_error *err, int fildes)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = close(fildes);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

size_t dc_confstr(const struct dc_posix_env *env, struct dc_error *err, int name, char *buf, size_t len)
{
    size_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = confstr(name, buf, len);

    if(ret_val == 0)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_crypt(const struct dc_posix_env *env, struct dc_error *err, const char *key, const char *salt)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = crypt(key, salt);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_dup(const struct dc_posix_env *env, struct dc_error *err, int fildes)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = dup(fildes);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_dup2(const struct dc_posix_env *env, struct dc_error *err, int fildes, int fildes2)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = dup2(fildes, fildes2);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

/*
void dc_encrypt(const struct dc_posix_env *env, struct dc_error *err, char block[64], int edflag)
{
    DC_TRACE(env);
    errno   = 0;
    encrypt(block, edflag);

    if(errno == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }
}
*/

int dc_execv(const struct dc_posix_env *env, struct dc_error *err, const char *path, char * const argv[])
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = execv(path, argv);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_execve(const struct dc_posix_env *env,
              struct dc_error *          err,
              const char *               path,
              char * const               argv[],
              char * const               envp[])
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = execve(path, argv, envp);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_execvp(const struct dc_posix_env *env, struct dc_error *err, const char *file, char * const argv[])
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = execvp(file, argv);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_faccessat(const struct dc_posix_env *env, struct dc_error *err, int fd, const char *path, int amode, int flag)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = faccessat(fd, path, amode, flag);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_fchdir(const struct dc_posix_env *env, struct dc_error *err, int fildes)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fchdir(fildes);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_fchown(const struct dc_posix_env *env, struct dc_error *err, int fildes, uid_t owner, gid_t group)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fchown(fildes, owner, group);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_fchownat(const struct dc_posix_env *env,
                struct dc_error *          err,
                int                        fd,
                const char *               path,
                uid_t                      owner,
                gid_t                      group,
                int                        flag)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fchownat(fd, path, owner, group, flag);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

/*
int dc_fdatasync(const struct dc_posix_env *env, int fildes)
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fdatasync(fildes);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
*/

/*
int dc_fexecve(const struct dc_posix_env *env, struct dc_error *err, int fd, char *const argv[], char *const envp[])
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fexecve(fd, argv, envp);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
*/

pid_t dc_fork(const struct dc_posix_env *env, struct dc_error *err)
{
    pid_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fork();

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long dc_fpathconf(const struct dc_posix_env *env, struct dc_error *err, int fildes, int name)
{
    long ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fpathconf(fildes, name);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_fsync(const struct dc_posix_env *env, struct dc_error *err, int fildes)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = fsync(fildes);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_ftruncate(const struct dc_posix_env *env, struct dc_error *err, int fildes, off_t length)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = ftruncate(fildes, length);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_getcwd(const struct dc_posix_env *env, struct dc_error *err, char *buf, size_t size)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getcwd(buf, size);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

gid_t dc_getegid(const struct dc_posix_env *env)
{
    gid_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getegid();

    return ret_val;
}

gid_t dc_geteuid(const struct dc_posix_env *env)
{
    gid_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = geteuid();

    return ret_val;
}

gid_t dc_getgid(const struct dc_posix_env *env)
{
    gid_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getgid();

    return ret_val;
}

int dc_getgroups(const struct dc_posix_env *env, struct dc_error *err, int gidsetsize, gid_t grouplist[])
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getgroups(gidsetsize, grouplist);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long dc_gethostid(const struct dc_posix_env *env)
{
    long ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = gethostid();

    return ret_val;
}

int dc_gethostname(const struct dc_posix_env *env, struct dc_error *err, char *name, size_t namelen)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = gethostname(name, namelen);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_getlogin(const struct dc_posix_env *env, struct dc_error *err)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getlogin();

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_getlogin_r(const struct dc_posix_env *env, struct dc_error *err, char *name, size_t namesize)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getlogin_r(name, namesize);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_getopt(const struct dc_posix_env *env,
              struct dc_error *          err,
              int                        argc,
              char * const               argv[],
              const char *               optstring)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getopt(argc, argv, optstring);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

pid_t dc_getpgid(const struct dc_posix_env *env, struct dc_error *err, pid_t pid)
{
    pid_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getpgid(pid);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

pid_t dc_getpgrp(const struct dc_posix_env *env)
{
    pid_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getpgrp();

    return ret_val;
}

pid_t dc_getpid(const struct dc_posix_env *env)
{
    pid_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getpid();

    return ret_val;
}

pid_t dc_getppid(const struct dc_posix_env *env)
{
    pid_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getppid();

    return ret_val;
}

pid_t dc_getsid(const struct dc_posix_env *env, struct dc_error *err, pid_t pid)
{
    pid_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getsid(pid);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

uid_t dc_getuid(const struct dc_posix_env *env)
{
    uid_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = getuid();

    return ret_val;
}

int dc_isatty(const struct dc_posix_env *env, struct dc_error *err, int fildes)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = isatty(fildes);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_lchown(const struct dc_posix_env *env, struct dc_error *err, const char *path, uid_t owner, gid_t group)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = lchown(path, owner, group);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_link(const struct dc_posix_env *env, struct dc_error *err, const char *path1, const char *path2)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = link(path1, path2);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_linkat(const struct dc_posix_env *env,
              struct dc_error *          err,
              int                        fd1,
              const char *               path1,
              int                        fd2,
              const char *               path2,
              int                        flag)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = linkat(fd1, path1, fd2, path2, flag);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_lockf(const struct dc_posix_env *env, struct dc_error *err, int fildes, int function, off_t size)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = lockf(fildes, function, size);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

off_t dc_lseek(const struct dc_posix_env *env, struct dc_error *err, int fildes, off_t offset, int whence)
{
    off_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = lseek(fildes, offset, whence);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_nice(const struct dc_posix_env *env, struct dc_error *err, int incr)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = nice(incr);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

long dc_pathconf(const struct dc_posix_env *env, struct dc_error *err, const char *path, int name)
{
    long ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pathconf(path, name);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_pause(const struct dc_posix_env *env, struct dc_error *err)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pause();

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_pipe(const struct dc_posix_env *env, struct dc_error *err, int fildes[2])
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;

    // NOLINTNEXTLINE(android-cloexec-pipe)
    ret_val = pipe(fildes);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

ssize_t
dc_pread(const struct dc_posix_env *env, struct dc_error *err, int fildes, void *buf, size_t nbyte, off_t offset)
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pread(fildes, buf, nbyte, offset);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

ssize_t
dc_pwrite(const struct dc_posix_env *env, struct dc_error *err, int fildes, const void *buf, size_t nbyte, off_t offset)
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = pwrite(fildes, buf, nbyte, offset);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

ssize_t dc_read(const struct dc_posix_env *env, struct dc_error *err, int fildes, void *buf, size_t nbyte)
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = read(fildes, buf, nbyte);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

ssize_t dc_readlink(const struct dc_posix_env *env,
                    struct dc_error *          err,
                    const char * restrict path,
                    char * restrict buf,
                    size_t bufsize)
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = readlink(path, buf, bufsize);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

ssize_t dc_readlinkat(const struct dc_posix_env *env,
                      struct dc_error *          err,
                      int                        fd,
                      const char * restrict path,
                      char * restrict buf,
                      size_t bufsize)
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = readlinkat(fd, path, buf, bufsize);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_rmdir(const struct dc_posix_env *env, struct dc_error *err, const char *path)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = rmdir(path);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_setegid(const struct dc_posix_env *env, struct dc_error *err, gid_t gid)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = setegid(gid);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_seteuid(const struct dc_posix_env *env, struct dc_error *err, uid_t uid)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = seteuid(uid);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_setgid(const struct dc_posix_env *env, struct dc_error *err, gid_t gid)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = setgid(gid);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_setpgid(const struct dc_posix_env *env, struct dc_error *err, pid_t pid, pid_t pgid)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = setpgid(pid, pgid);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_setregid(const struct dc_posix_env *env, struct dc_error *err, gid_t rgid, gid_t egid)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = setregid(rgid, egid);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_setreuid(const struct dc_posix_env *env, struct dc_error *err, uid_t ruid, uid_t euid)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = setreuid(ruid, euid);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

pid_t dc_setsid(const struct dc_posix_env *env, struct dc_error *err)
{
    pid_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = setsid();

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_setuid(const struct dc_posix_env *env, struct dc_error *err, uid_t uid)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = setuid(uid);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

unsigned dc_sleep(const struct dc_posix_env *env, unsigned seconds)
{
    unsigned ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = sleep(seconds);

    return ret_val;
}

void dc_swab(const struct dc_posix_env *env, const void * restrict src, void * restrict dest, ssize_t nbytes)
{
    DC_TRACE(env);
    errno = 0;
    swab(src, dest, nbytes);
}

int dc_symlink(const struct dc_posix_env *env, struct dc_error *err, const char *path1, const char *path2)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = symlink(path1, path2);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_symlinkat(const struct dc_posix_env *env, struct dc_error *err, const char *path1, int fd, const char *path2)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = symlinkat(path1, fd, path2);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

void dc_sync(const struct dc_posix_env *env)
{
    DC_TRACE(env);
    errno = 0;
    sync();
}

long dc_sysconf(const struct dc_posix_env *env, struct dc_error *err, int name)
{
    long ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = sysconf(name);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

pid_t dc_tcgetpgrp(const struct dc_posix_env *env, struct dc_error *err, int fildes)
{
    pid_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = tcgetpgrp(fildes);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_tcsetpgrp(const struct dc_posix_env *env, struct dc_error *err, int fildes, pid_t pgid_id)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = tcsetpgrp(fildes, pgid_id);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_truncate(const struct dc_posix_env *env, struct dc_error *err, const char *path, off_t length)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = truncate(path, length);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

char *dc_ttyname(const struct dc_posix_env *env, struct dc_error *err, int fildes)
{
    char *ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = ttyname(fildes);

    if(ret_val == NULL)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_ttyname_r(const struct dc_posix_env *env, struct dc_error *err, int fildes, char *name, size_t namesize)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = ttyname_r(fildes, name, namesize);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_unlink(const struct dc_posix_env *env, struct dc_error *err, const char *path)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = unlink(path);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

int dc_unlinkat(const struct dc_posix_env *env, struct dc_error *err, int fd, const char *path, int flag)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = unlinkat(fd, path, flag);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}

ssize_t dc_write(const struct dc_posix_env *env, struct dc_error *err, int fildes, const void *buf, size_t nbyte)
{
    ssize_t ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = write(fildes, buf, nbyte);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
