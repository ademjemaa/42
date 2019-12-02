/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:20:13 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/27 20:06:05 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strtotal(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	i = 1;
	while (s1[i - 1] != '\0')
		i++;
	cpy = malloc(sizeof(*cpy) * i);
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int		ft_check_sign(char *str)
{
	int i;
	int sign;

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

int		ft_atoi(char *str, int *dec)
{
	int i;
	int sign;
	int total;

	total = 0;
	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == 32)
		i++;
	sign = ft_check_sign((str + i));
	if ((str[i] == '-' || str[i] == '+') && ++(*dec))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = (total * 10) + (str[i] - '0');
		*dec = *dec + 1;
		i++;
	}
	return (total * sign);
}

char	*ft_strjoin(char *s1, char *s2, int crit)
{
	int		total;
	char	*str;
	int		i;
	int		j;

	i = -1;
	total = ft_strtotal(s1) + ft_strtotal(s2);
	str = malloc(sizeof(char) * total + 1);
	if (str == NULL)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	if (crit == 1)
		free(s1);
	else if (crit == 2)
		free(s2);
	return (str);
}
