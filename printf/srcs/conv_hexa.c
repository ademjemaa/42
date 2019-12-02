/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:10:37 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/27 22:03:28 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv_num(unsigned int num, t_det *check)
{
	char			*hexa;
	char			*tab;

	if (check->conv == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if ((tab = ft_strdup("")) == NULL)
		return (NULL);
	if (num == 0)
		return (ft_strdup("0"));
	while (num > 0)
	{
		if ((tab = ft_cat_one(tab, hexa[num % 16])) == NULL)
			return (NULL);
		num = num / 16;
	}
	return (tab);
}

char	*create_x(t_det *check, va_list *ap, t_f **fn)
{
	int				i;
	char			*final;
	unsigned int	num;

	num = va_arg(*ap, unsigned int);
	final = conv_num(num, check);
	i = ft_strlen(final) - 1;
	if (ft_strlen(final) == 1 && final[0] == '0' && check->point)
		final = ft_strdup("");
	if (check->point)
		final = ft_int_point(final, check);
	else if (check->zero && ((check->len) > i) && check->minus == 0)
		final = ft_int_zero(final, check);
	if ((check->justify) > i)
		final = ft_int_jus(final, check);
	i = ft_strlen(final) - 1;
	while (++i < check->len && check->zero)
		final = ft_strjoinfree(ft_strdup(" "), final);
	(*fn)->s = (*fn)->s + ft_strlen(final);
	return (final);
}
