/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:43:02 by adjemaa           #+#    #+#             */
/*   Updated: 2021/05/13 16:46:38 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_phil
{
	int				id;
	unsigned long	last_meal;
	int				total_meals;
	pthread_t		thread_id;
	pid_t			pid;
}					t_phil;

typedef struct s_condi
{
	int				philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				total_must_eat;
	unsigned long	time_now;
	int				state;
	sem_t			*print;
	sem_t			*forks;
	sem_t			*two_forks;
	sem_t			*death;
	sem_t			*meals;
	sem_t			*table;
	t_phil			*philos;
}					t_condi;

typedef struct s_stat
{
	int		cur;
	int		total;
	t_condi	*stru;
}					t_stat;

int					ft_atoi(const char *str);
void				ft_putstr(char *str);
unsigned long		the_time(void);
void				ft_locked_print(char *str, int cur, t_condi *stru, int con);
void				ft_putnbr(unsigned long n);
void				*function(void	*args);
int					check_stats(int cur, t_condi *stru);
int					init_philos(char **argv, int argc, t_condi *stru);
int					init_config(char **argv, int argc, t_condi *stru);
int					init_vars(char **argv, int argc, t_condi *stru);

#endif
