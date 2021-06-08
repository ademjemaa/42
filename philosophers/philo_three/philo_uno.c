/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_uno.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:46:44 by adjemaa           #+#    #+#             */
/*   Updated: 2021/05/13 16:47:59 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_stats(int cur, t_condi *stru)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stru->philo)
	{
		j = -1;
		if ((long)(the_time() - stru->philos[cur].last_meal) >
			(long)stru->time_die)
		{
			stru->state = 0;
			ft_locked_print("is dead\n", cur, stru, 0);
			sem_post(stru->death);
			if (stru->total_must_eat != -1)
			{
				while (++j < stru->philo)
					sem_post(stru->meals);
			}
			return (0);
		}
	}
	return (1);
}

int	init_vars(char **argv, int argc, t_condi *stru)
{
	int	i;

	if (init_philos(argv, argc, stru) == 0)
		return (0);
	stru->philos = malloc(sizeof(t_phil) * stru->philo);
	stru->forks = sem_open("forks", O_CREAT, S_IRWXU, stru->philo);
	stru->print = sem_open("print", O_CREAT, S_IRWXU, 1);
	stru->two_forks = sem_open("two forks", O_CREAT, S_IRWXU, 1);
	stru->death = sem_open("death", O_CREAT, S_IRWXU, 0);
	stru->meals = sem_open("meals", O_CREAT, S_IRWXU, 0);
	stru->table = sem_open("print", O_CREAT, S_IRWXU, 1);
	i = -1;
	while (++i < stru->philo)
	{
		stru->philos[i].id = i;
		stru->philos[i].last_meal = the_time();
		stru->philos[i].total_meals = 0;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_condi	stru;

	if (init_config(argv, argc, &stru) == 0)
		return (0);
	sem_wait(stru.death);
	i = 0;
	while (i < stru.philo)
		kill(stru.philos[i++].pid, SIGKILL);
	sem_unlink("forks");
	sem_close(stru.death);
	sem_close(stru.two_forks);
	sem_close(stru.forks);
	sem_close(stru.print);
	sem_close(stru.table);
	free(stru.philos);
}
