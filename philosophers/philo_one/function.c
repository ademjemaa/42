#include "header.h"

unsigned long   the_time(void)
{
    struct timeval eat;

    gettimeofday(&eat, NULL);
    if (time_now == 0)
        time_now = (eat.tv_sec * 1000) + (eat.tv_usec / 1000);
    return ((eat.tv_sec * 1000) + (eat.tv_usec / 1000));
}

void    pick_up_forks(int cur)
{
    int second = cur - 1;
    if (cur == 0)
        second = stru.philo - 1;
    pthread_mutex_lock(&stru.philos[cur].fork);
    pthread_mutex_unlock(&stru.philos[cur].fork);
    pthread_mutex_lock(&stru.philos[second].fork);
    ft_locked_print("has taken a fork\n", cur);
    pthread_mutex_lock(&stru.philos[cur].fork);
    ft_locked_print("has taken a fork\n", cur);
}

void    drop_forks(int cur)
{
    int second = cur - 1;
    if (cur == 0)
        second = stru.philo - 1;
    pthread_mutex_unlock(&stru.philos[cur].fork);
    pthread_mutex_unlock(&stru.philos[second].fork);
}

void    *function(void  *args)
{
    int cur = *(int*)args;

    if (!check_stats())
        return NULL;
    pick_up_forks(cur);
    ft_locked_print("is eating\n", cur);
    stru.philos[cur].last_meal = the_time();
    usleep(stru.time_eat * 1000);
    drop_forks(cur);
    stru.philos[cur].total_meals++;
    if (stru.philos[cur].total_meals >= stru.total_must_eat && stru.total_must_eat > 0)
        return (NULL);
    ft_locked_print("is sleeping\n", cur);
    usleep((stru.time_sleep) * 1000);
    ft_locked_print("is thinking\n", cur);
    if (stru.state == 0)
        function(args);
    return(0);
}