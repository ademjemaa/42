/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_uint_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:50:38 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/29 15:33:57 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ucounter(unsigned int n)
{
	int	c;

	c = 1;
	while (!(n <= 9))
	{
		n = n / 10;
		c++;
	}
	return (c);
}

void	ucalcul(char *str, unsigned int total, int i)
{
	while (total / 10 > 0)
	{
		str[i] = total % 10 + '0';
		total = total / 10;
		i--;
	}
	str[i] = total + '0';
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	int				i;
	unsigned int	total;

	i = ucounter(n);
	total = n;
	if (!(str = malloc(sizeof(*str) * i + 1)))
		return (NULL);
	str[i] = '\0';
	ucalcul(str, total, --i);
	return (str);
}
