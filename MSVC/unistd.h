#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <WinSock2.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <io.h>
#include <malloc.h>
typedef SSIZE_T ssize_t;
typedef int mode_t;
#pragma warning (disable:4018 4244)

#define __attribute__(a)
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#define usleep(a) Sleep((a)/1000)

struct timezone
{
    time_t tz_minuteswest;         /* minutes W of Greenwich */
    time_t tz_dsttime;             /* type of dst correction */
};

extern int gettimeofday(struct timeval* tv, struct timezone* tz);

