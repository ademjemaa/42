#include "header.h"

unsigned int death;

int     check_stats(int cur)
{
    if ((unsigned long)(the_time() - stru.philos[cur].last_meal) >= (unsigned long)stru.time_die)
    {
        ft_locked_print("is dead\n", cur);
        sem_post(stru.death);
        return (0);
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
    stru.death = sem_open("death", O_CREAT, S_IRWXU, 0);
    for (int i = 0; i < stru.philo; i++)
    {
        stru.philos[i].id = i;
        stru.philos[i].last_meal = current;
        stru.philos[i].death = the_time() * 10;
        stru.philos[i].total_meals = 0;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int i;
    sem_unlink("forks");
    sem_unlink("two forks");
    sem_unlink("print");
    sem_unlink("death");
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
                if (!check_stats(i))
                    exit(1);
            }
            pthread_join(stru.philos[i].thread_id, NULL);
        }
    }
    i = -1;
    sem_wait(stru.death);
    i = 0;
    while (i < stru.philo)
		kill(stru.philos[i++].pid, SIGKILL);
    sem_unlink("forks");
    sem_unlink("two forks");
    sem_unlink("print");
    sem_unlink("death");
    free(stru.philos);
}