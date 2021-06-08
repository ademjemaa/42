/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:31:24 by adjemaa           #+#    #+#             */
/*   Updated: 2021/05/13 16:32:19 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned long	the_time(void)
{
	struct timeval	eat;

	gettimeofday(&eat, NULL);
	return ((eat.tv_sec * 1000) + (eat.tv_usec / 1000));
}

void	pick_up_forks(int cur, t_condi *stru)
{
	sem_wait(stru->two_forks);
	sem_wait(stru->forks);
	ft_locked_print("has taken a fork\n", cur, stru);
	sem_wait(stru->forks);
	ft_locked_print("has taken a fork\n", cur, stru);
	sem_post(stru->two_forks);
}

void	drop_forks(t_condi *stru)
{
	sem_post(stru->forks);
	sem_post(stru->forks);
}

void	*function(void *args)
{
	t_params	*tab;

	tab = (t_params *)args;
	if (!check_stats(tab->stru))
		return (NULL);
	pick_up_forks(tab->id, tab->stru);
	tab->stru->philos[tab->id].last_meal = the_time();
	ft_locked_print("is eating\n", tab->id, tab->stru);
	usleep(tab->stru->time_eat * 1000);
	drop_forks(tab->stru);
	tab->stru->philos[tab->id].total_meals++;
	if (tab->stru->philos[tab->id].total_meals == tab->stru->total_must_eat)
		return (0);
	ft_locked_print("is sleeping\n", tab->id, tab->stru);
	usleep((tab->stru->time_sleep) * 1000);
	ft_locked_print("is thinking\n", tab->id, tab->stru);
	if (tab->stru->state == 0)
		function(args);
	return (0);
}
