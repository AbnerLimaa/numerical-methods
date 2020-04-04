#include <time.h>
#include <stdlib.h>
#include "ticker.h"

enum { NS_PER_SECOND = 1000000000 };

struct ticker
{
    struct timespec start;
    struct timespec end;
    struct timespec spent_time;
};

ticker* alloc_ticker()
{
    ticker* t = (ticker*)calloc(1, sizeof(ticker));
    return t;
}

void free_ticker(ticker* t)
{
    if (t != NULL)
        free(t);
}

void sub_timespec(struct timespec t1, struct timespec t2, struct timespec *td)
{
    td->tv_nsec = t2.tv_nsec - t1.tv_nsec;
    td->tv_sec  = t2.tv_sec - t1.tv_sec;
    if (td->tv_sec > 0 && td->tv_nsec < 0)
    {
        td->tv_nsec += NS_PER_SECOND;
        td->tv_sec--;
    }
    else if (td->tv_sec < 0 && td->tv_nsec > 0)
    {
        td->tv_nsec -= NS_PER_SECOND;
        td->tv_sec++;
    }
}

void start(ticker* t)
{
    if (t != NULL)
        clock_gettime(CLOCK_MONOTONIC, &t->start);
}

void end(ticker* t)
{
    if (t != NULL)
        clock_gettime(CLOCK_MONOTONIC, &t->end);
}

double spent_time(ticker* t)
{
    sub_timespec(t->start, t->end, &t->spent_time);
    double seconds = (double)t->spent_time.tv_sec;
    double nanoseconds = ((double)t->spent_time.tv_nsec) / NS_PER_SECOND;
    return seconds + nanoseconds;
}