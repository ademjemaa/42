#include "header.h"

void    pick_up_forks(int cur)
{
    int second = cur - 1;
    if (cur == 0)
        second = stru.philo - 1;
    pthread_mutex_lock(&stru.two_forks);
    pthread_mutex_lock(&stru.philos[second].fork);
    ft_locked_print("has taken a fork\n", cur);
    pthread_mutex_lock(&stru.philos[cur].fork);
    ft_locked_print("has taken a fork\n", cur);
    pthread_mutex_unlock(&stru.two_forks);
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

    pick_up_forks(cur);
    ft_locked_print("is eating\n", cur);
    usleep(stru.time_eat * 1000);
    stru.philos[cur].last_meal = the_time();
    drop_forks(cur);
    stru.philos[cur].total_meals++;
    if (stru.philos[cur].total_meals >= stru.total_must_eat && stru.total_must_eat > 0)
        return (NULL);
    ft_locked_print("is sleeping\n", cur);
    usleep((stru.time_sleep) * 1000);
    ft_locked_print("is thinking\n", cur);
    function(args);
    return(0);
}