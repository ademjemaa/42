/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:13:53 by adjemaa           #+#    #+#             */
/*   Updated: 2021/05/13 16:18:40 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_phil
{
	int				id;
	int				cur;
	unsigned long	last_meal;
	int				total_meals;
	pthread_t		thread_id;
	pthread_mutex_t	fork;
}					t_phil;

typedef struct s_condi
{
	int				philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				total_must_eat;
	int				state;
	unsigned long	time_now;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	forks;
	t_phil			*philos;
}					t_condi;

typedef struct s_params
{
	int		id;
	t_condi	*stru;
}					t_params;

int					ft_atoi(const char *str);
int					ft_putstr(char *str);
int					init_philos(char **argv, int argc, t_condi *stru);
unsigned long		the_time(void);
t_params			*param_config(int i, t_condi *stru);
void				ft_locked_print(char *str, int cur, t_condi *stru,
						int signal);
void				ft_putnbr(unsigned long n);
void				*function(void	*args);
t_params			**create_params_tab(t_condi *stru);
int					check_stats(t_condi *stru);

#endif
