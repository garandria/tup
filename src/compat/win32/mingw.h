/* vim: set ts=8 sw=8 sts=8 noet tw=78:
 *
 * tup - A file-based build system
 *
 * Copyright (C) 2010-2023  Mike Shal <marfey@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/* _GNU_SOURCE lets us use the %lli flag correctly */
#define _GNU_SOURCE

/* Minimum version is windows Vista (for GetFinalPathNameByHandle, at least) */
#define _WIN32_WINNT 0x600
#define __USE_MINGW_ANSI_STDIO 1
#include <stddef.h> /* get size_t */
#include <fcntl.h> /* get mode_t (mingw with gcc 4.5) */
#include <sys/types.h> /* get mode_t (mingw with gcc 4.6) */
#include <sys/stat.h> /* struct stat redirection */
#define AT_SYMLINK_NOFOLLOW 0x100

#define O_CLOEXEC 0
#define F_DUPFD_CLOEXEC 1030

#define S_ISLNK(a) 0
#define AT_REMOVEDIR 0x200

/* Use wchar functions for Windows (we use UTF8 internally) */
#define UNICODE
#define _UNICODE

#define mkdir(a,b) mkdir(a)

struct stat;

#define lstat(a, b) win_lstat(a, b)
int win_lstat(const char *pathname, struct stat *buf);

int fchdir(int fd);
int fstatat(int dirfd, const char *pathname, struct stat *buf, int flags);
int mkstemp(char *template);
int openat(int dirfd, const char *pathname, int flags, ...);
int unlinkat(int dirfd, const char *pathname, int flags);
int readlinkat(int dirfd, const char *pathname, char *buf, size_t bufsiz);
int mkdirat(int dirfd, const char *pathname, mode_t mode);
int renameat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath);
int symlink(const char *oldpath, const char *newpath);
int fcntl(int fd, int cmd, int);
