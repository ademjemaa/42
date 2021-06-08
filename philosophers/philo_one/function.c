/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:11:58 by adjemaa           #+#    #+#             */
/*   Updated: 2021/05/13 16:12:43 by adjemaa          ###   ########.fr       */
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
	int	second;

	second = cur + 1;
	if (cur + 1 == stru->philo)
		second = 0;
	pthread_mutex_lock(&stru->philos[cur].fork);
	pthread_mutex_lock(&stru->philos[second].fork);
	ft_locked_print("has taken a fork\n", cur, stru, 1);
	ft_locked_print("has taken a fork\n", cur, stru, 1);
}

void	drop_forks(int cur, t_condi *stru)
{
	int	second;

	second = cur + 1;
	if (cur + 1 == stru->philo)
		second = 0;
	pthread_mutex_unlock(&stru->philos[cur].fork);
	pthread_mutex_unlock(&stru->philos[second].fork);
}

void	*function(void *args)
{
	t_params	*tab;

	tab = (t_params *)args;
	if (!check_stats(tab->stru) || tab->stru->state)
		return (NULL);
	pick_up_forks(tab->id, tab->stru);
	pthread_mutex_lock(&(tab->stru->death));
	tab->stru->philos[tab->id].last_meal = the_time();
	ft_locked_print("is eating\n", tab->id, tab->stru, 1);
	pthread_mutex_unlock(&tab->stru->death);
	usleep(tab->stru->time_eat * 1000);
	drop_forks(tab->id, tab->stru);
	tab->stru->philos[tab->id].total_meals++;
	if (tab->stru->philos[tab->id].total_meals >= tab->stru->total_must_eat
		&& tab->stru->total_must_eat > 0)
		return (NULL);
	ft_locked_print("is sleeping\n", tab->id, tab->stru, 1);
	usleep((tab->stru->time_sleep) * 1000);
	ft_locked_print("is thinking\n", tab->id, tab->stru, 1);
	if (tab->stru->state == 0)
		function(args);
	return (0);
}
