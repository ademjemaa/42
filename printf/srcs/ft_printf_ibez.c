/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ibez.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:25:41 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/24 15:49:44 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		counter(int n)
{
	int	c;

	c = 1;
	while (!(n >= -9 && n <= 9))
	{
		n = n / 10;
		c++;
	}
	return (c);
}

void	calcul(char *str, unsigned int total, int i)
{
	while (total / 10 > 0)
	{
		str[i] = total % 10 + '0';
		total = total / 10;
		i--;
	}
	str[i] = total + '0';
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	total;

	i = counter(n);
	if (n < 0)
	{
		if (!(str = malloc(sizeof(*str) * i + 2)))
			return (NULL);
		total = -n;
		i++;
		str[0] = '-';
	}
	else
	{
		total = n;
		if (!(str = malloc(sizeof(*str) * i + 1)))
			return (NULL);
	}
	str[i] = '\0';
	calcul(str, total, --i);
	return (str);
}
