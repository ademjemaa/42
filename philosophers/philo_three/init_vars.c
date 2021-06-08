/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:44:38 by adjemaa           #+#    #+#             */
/*   Updated: 2021/05/13 16:45:40 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_threads(t_condi *stru)
{
	t_stat	stat;
	int		i;

	i = -1;
	while (++i < stru->philo)
	{
		stat.cur = i;
		stat.total = 0;
		stat.stru = stru;
		stru->philos[i].pid = fork();
		if (stru->philos[i].pid == 0)
		{
			pthread_create(&stru->philos[i].thread_id, NULL, function,
				(void*)&stat);
			while (1)
			{
				if (!check_stats(i, stru))
					exit(1);
			}
			pthread_join(stru->philos[i].thread_id, NULL);
		}
	}
}

int	init_config(char **argv, int argc, t_condi *stru)
{
	int	i;

	i = -1;
	sem_unlink("forks");
	sem_unlink("table");
	sem_unlink("two forks");
	sem_unlink("print");
	sem_unlink("death");
	sem_unlink("meals");
	if (init_vars(argv, argc, stru) == 0)
	{
		ft_putstr("config error\n");
		return (0);
	}
	create_threads(stru);
	if (stru->total_must_eat != -1)
	{
		while (++i < stru->philo)
			sem_wait(stru->meals);
		sem_post(stru->death);
	}
	return (1);
}

void	init_phil_vals(char **argv, t_condi *stru)
{
	struct timeval	eat;

	gettimeofday(&eat, NULL);
	stru->time_now = (eat.tv_sec * 1000) + (eat.tv_usec / 1000) - 1;
	stru->philo = ft_atoi(argv[1]);
	stru->time_die = ft_atoi(argv[2]);
	stru->time_eat = ft_atoi(argv[3]);
	stru->time_sleep = ft_atoi(argv[4]);
	stru->state = 1;
	stru->total_must_eat = -1;
}

int	init_philos(char **argv, int argc, t_condi *stru)
{
	int	i;
	int	j;

	i = 0;
	if (!(argc == 5 || argc == 6))
		return (0);
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
	}
	init_phil_vals(argv, stru);
	if (argc == 6)
	{
		stru->total_must_eat = ft_atoi(argv[5]);
		if (stru->total_must_eat < 1)
			return (0);
	}
	return (1);
}
