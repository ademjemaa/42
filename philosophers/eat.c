#include "header.h"

unsigned long   the_time(void)
{
    struct timeval eat;

    gettimeofday(&eat, NULL);
    if (time_now == 0)
        time_now = (eat.tv_sec * 1000) + (eat.tv_usec / 1000);
    return ((eat.tv_sec * 1000) + (eat.tv_usec / 1000));
}