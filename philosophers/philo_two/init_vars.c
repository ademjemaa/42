/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:34:14 by adjemaa           #+#    #+#             */
/*   Updated: 2021/05/13 16:35:12 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_params	**create_params_tab(t_condi *stru)
{
	t_params	**tab;
	int			i;

	i = -1;
	tab = malloc(sizeof(t_params) * stru->philo);
	while (++i < stru->philo)
		tab[i] = param_config(i, stru);
	return (tab);
}

t_params	*param_config(int i, t_condi *stru)
{
	t_params	*config;

	config = malloc(sizeof(t_params));
	config->id = i;
	config->stru = stru;
	return (config);
}

void	init_phil_vals(char **argv, t_condi *stru)
{
	struct timeval	eat;

	gettimeofday(&eat, NULL);
	stru->time_now = (eat.tv_sec * 1000) + (eat.tv_usec / 1000);
	stru->philo = ft_atoi(argv[1]);
	stru->time_die = ft_atoi(argv[2]);
	stru->time_eat = ft_atoi(argv[3]);
	stru->time_sleep = ft_atoi(argv[4]);
	stru->state = 0;
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
