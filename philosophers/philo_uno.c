#include "header.h"

int    init_vars(char **argv, int argc)
{
    unsigned long current;
    if (!(argc == 5 || argc == 6))
        return (0);
    for (int i = 1; i < argc; i++)
        for (int j = 0; argv[i][j]; j++)
            if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
                return (0);
    stru.philo = ft_atoi(argv[1]);
    stru.time_die = ft_atoi(argv[2]);
    stru.time_eat = ft_atoi(argv[3]);
    stru.time_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        stru.time_must_eat = ft_atoi(argv[5]);
    if ((stru.philos = malloc(sizeof(t_phil) * stru.philo)) == NULL)
		return (0);
    current = the_time();
    pthread_mutex_init(&stru.two_forks, NULL);
    pthread_mutex_init(&stru.print, NULL);
    for (int i = 0; i < stru.philo; i++)
    {
        stru.philos[i].last_meal = current;
        stru.philos[i].total_meals = 0;
        pthread_mutex_init(&stru.philos[i].fork, NULL);
    }
    return (1);
}

int main(int argc, char **argv)
{
    time_now = 0;
    if (init_vars(argv, argc) == 0)
        ft_putstr("config error\n");
    printf("time now : %ld", the_time());
    for (int i = 0; i < stru.philo; i++)
        pthread_create(&stru.philos[i].thread_id, NULL, 
                       function, (void*)&i);
}