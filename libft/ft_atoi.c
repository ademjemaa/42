/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:29:48 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/07 16:48:49 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_check_sign(char *str)
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

int			ft_atoi(const char *str)
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
