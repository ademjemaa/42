/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:39:17 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/07 16:49:32 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		counter(int n)
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

static	void	calcul(char *str, unsigned int total, int i)
{
	while (total / 10 > 0)
	{
		str[i] = total % 10 + '0';
		total = total / 10;
		i--;
	}
	str[i] = total + '0';
}

char			*ft_itoa(int n)
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
