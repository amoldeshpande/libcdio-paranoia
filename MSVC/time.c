#include <unistd.h>
#include <time.h>

#define DELTA_EPOCH_IN_TICKS  116444736000000000Ui64

int gettimeofday (struct timeval *tv, struct timezone *tz)
{
    FILETIME ft;
    uint64_t tmpres;
    static int tzflag;

    if (NULL != tv)
    {
        GetSystemTimeAsFileTime(&ft);

        tmpres = ((uint64_t) ft.dwHighDateTime << 32)
               | (ft.dwLowDateTime);

        tmpres -= DELTA_EPOCH_IN_TICKS;
        tv->tv_sec = tmpres / 10000000;
        tv->tv_usec = tmpres % 1000000;
    }

    if (NULL != tz)
    {
        if (!tzflag)
        {
            _tzset();
            tzflag++;
        }
        tz->tz_minuteswest = _timezone / 60;
        tz->tz_dsttime = _daylight;
    }

    return 0;
}
struct tm* localtime_r(const time_t* timep, struct tm* result) {
    if (localtime_s(result, timep) != 0)
    {
        return NULL;
    }
    return result;
}
struct tm* gmtime_r(const time_t* timep, struct tm* result) {
    if (gmtime_s(result, timep) != 0)
    {
        return NULL;
    }
    return result;
}
