#include "header.h"

unsigned long   the_time(void)
{
    struct timeval eat;

    gettimeofday(&eat, NULL);
    if (time_now == 0)
        time_now = (eat.tv_sec * 1000) + (eat.tv_usec / 1000) + 8;
    return ((eat.tv_sec * 1000) + (eat.tv_usec / 1000));
}

void    pick_up_forks(int cur)
{
    sem_wait(stru.two_forks);
    sem_wait(stru.forks);
    ft_locked_print("has taken a fork\n", cur);
    sem_wait(stru.forks);
    ft_locked_print("has taken a fork\n", cur);
    sem_post(stru.two_forks);
}

void    drop_forks(void)
{
    sem_post(stru.forks);
    sem_post(stru.forks);
}

void    *function(void  *args)
{
    int cur = *(int*)args;
    pick_up_forks(cur);
    stru.philos[cur].last_meal = the_time();
    ft_locked_print("is eating\n", cur);
    usleep(stru.time_eat * 1000);
    drop_forks();
    stru.philos[cur].total_meals++;
    ft_locked_print("is sleeping\n", cur);
    usleep((stru.time_sleep) * 1000);
    ft_locked_print("is thinking\n", cur);
    if (check_stats(cur))
        function(args);
    return(0);
}