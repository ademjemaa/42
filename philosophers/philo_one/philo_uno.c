/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_uno.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:24:41 by adjemaa           #+#    #+#             */
/*   Updated: 2021/05/13 16:27:14 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_all(t_condi *stru, t_params **tab)
{
	int	i;

	i = -1;
	while (++i < stru->philo)
	{
		pthread_mutex_destroy(&stru->philos[i].fork);
		free(tab[i]);
	}
	pthread_mutex_destroy(&stru->print);
	free(stru->philos);
	free(tab);
}

int	check_stats(t_condi *stru)
{
	int	index;
	int	i;

	index = 0;
	i = -1;
	while (++i < stru->philo)
	{
		if (stru->philos[i].total_meals == stru->total_must_eat)
			index++;
		pthread_mutex_lock(&stru->death);
		if ((unsigned long)(the_time()
			- stru->philos[i].last_meal) > (unsigned long)stru->time_die)
		{
			ft_locked_print("has died\n", i, stru, 0);
			stru->state = 1;
			return (0);
		}
		pthread_mutex_unlock(&stru->death);
	}
	if (index == stru->philo && stru->total_must_eat > 0)
	{
		stru->state = 1;
		return (0);
	}
	return (1);
}

int	init_vars(char **argv, int argc, t_condi *stru)
{
	unsigned long	current;
	int				i;

	i = -1;
	if (init_philos(argv, argc, stru) == 0)
		return (0);
	stru->philos = malloc(sizeof(t_phil) * stru->philo);
	current = the_time();
	pthread_mutex_init(&stru->print, NULL);
	pthread_mutex_init(&stru->death, NULL);
	pthread_mutex_init(&stru->forks, NULL);
	while (++i < stru->philo)
	{
		stru->philos[i].id = i;
		stru->philos[i].last_meal = current;
		stru->philos[i].total_meals = 0;
		pthread_mutex_init(&stru->philos[i].fork, NULL);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			i;
	void		*ret;
	t_condi		stru;
	t_params	**tab;

	i = -1;
	if (init_vars(argv, argc, &stru) == 0)
		return (ft_putstr("config error\n"));
	tab = create_params_tab(&stru);
	while (++i < stru.philo)
	{
		pthread_create(&stru.philos[i].thread_id, NULL,
			function, (void*)tab[i]);
		pthread_detach(stru.philos[i].thread_id);
		usleep(100);
	}
	while (check_stats(&stru))
		i = -1;
	while (++i < stru.philo)
		pthread_join(stru.philos[i].thread_id, &ret);
	usleep(200000);
	free_all(&stru, tab);
}
