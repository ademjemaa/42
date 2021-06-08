/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:59:50 by adjemaa           #+#    #+#             */
/*   Updated: 2021/05/13 16:42:10 by adjemaa          ###   ########.fr       */
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
	ft_locked_print("has taken a fork\n", cur, stru, 1);
	sem_wait(stru->forks);
	ft_locked_print("has taken a fork\n", cur, stru, 1);
	sem_post(stru->two_forks);
}

void	drop_forks(t_condi *stru)
{
	sem_post(stru->forks);
	sem_post(stru->forks);
}

void	*function(void *args)
{
	t_stat	*stat;

	stat = (t_stat *)args;
	pick_up_forks(stat->cur, stat->stru);
	stat->stru->philos[stat->cur].last_meal = the_time();
	stat->total++;
	ft_locked_print("is eating\n", stat->cur, stat->stru, 1);
	if (stat->total == stat->stru->total_must_eat)
		sem_post(stat->stru->meals);
	usleep(stat->stru->time_eat * 1000);
	drop_forks(stat->stru);
	stat->stru->philos[stat->cur].total_meals++;
	ft_locked_print("is sleeping\n", stat->cur, stat->stru, 1);
	usleep((stat->stru->time_sleep) * 1000);
	ft_locked_print("is thinking\n", stat->cur, stat->stru, 1);
	if (check_stats(stat->cur, stat->stru))
		function(stat);
	return (0);
}
