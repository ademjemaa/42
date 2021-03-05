#include "header.h"

int     check_stats(void)
{
    int index = 0;
    for (int i = 0; i < stru.philo; i++)
    {
        if (stru.philos[i].total_meals == stru.total_must_eat)
            index++;
        else if ((unsigned long)(the_time() - stru.philos[i].last_meal) >= (unsigned long)stru.time_die)
        {
            ft_locked_print("has died\n", i);
            printf("last meal == %ld\n", the_time() - stru.philos[i].last_meal);
            stru.state = 1;
            return(0);
        }
    }
    if (index == stru.philo && stru.total_must_eat > 0)
    {
        stru.state = 1;
        return(0);
    }
    return (1);
}

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
    stru.state = 0;
    stru.total_must_eat = -1;
    if (argc == 6)
    {
        stru.total_must_eat = ft_atoi(argv[5]);
        if (stru.total_must_eat < 1)
            return (0);
    }
    if ((stru.philos = malloc(sizeof(t_phil) * stru.philo)) == NULL)
		return (0);
    current = the_time();
    stru.forks = sem_open("forks", O_CREAT, S_IRWXU, stru.philo);
    stru.print = sem_open("print", O_CREAT, S_IRWXU, 1);
    stru.two_forks = sem_open("two forks", O_CREAT, S_IRWXU, 1);
    for (int i = 0; i < stru.philo; i++)
    {
        stru.philos[i].id = i;
        stru.philos[i].last_meal = current;
        stru.philos[i].total_meals = 0;
    }
    return (1);
}

int main(int argc, char **argv)
{
    sem_unlink("forks");
    sem_unlink("two forks");
    sem_unlink("print");
    time_now = 0;
    if (init_vars(argv, argc) == 0)
    {
        ft_putstr("config error\n");
        if (stru.philos != NULL)
            free(stru.philos);
        return (0);
    }
    for (int i = 0; i < stru.philo; i++)
    {
        stru.philos[i].pid = fork();
        if (stru.philos[i].pid == 0)
        {
			pthread_create(&stru.philos[i].thread_id, NULL, function, (void*)&i);
            while (1)
            {
                if (!check_stats())
                    exit(1);
            }
            
        }
    }
    while (check_stats());
    sem_unlink("forks");
    sem_unlink("two forks");
    sem_unlink("print");
    free(stru.philos);
}