/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:27:36 by adjemaa           #+#    #+#             */
/*   Updated: 2021/05/13 16:30:43 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putnbr(unsigned	long n)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_locked_print(char *str, int cur, t_condi *stru, int signal)
{
	if (stru->state == 1)
		return ;
	pthread_mutex_lock(&stru->print);
	ft_putnbr(the_time() - stru->time_now);
	ft_putstr(" ");
	ft_putnbr(cur + 1);
	ft_putstr(" ");
	ft_putstr(str);
	if (signal)
		pthread_mutex_unlock(&stru->print);
}

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (0);
}

static int	ft_check_sign(char *str)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	total;

	total = 0;
	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == 32)
		i++;
	sign = ft_check_sign((char *)(str + i));
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10;
		total = (str[i] - '0') + total;
		i++;
	}
	return (total * sign);
}
