/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:47:56 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/29 15:33:48 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uint_point(char *final, t_det *check)
{
	int		i;
	int		k;
	char	*tmp;
	int		j;

	k = 0;
	j = 0;
	if (check->precision < ft_strlen(final) - 1)
		return (final);
	i = ft_strlen(final) + check->precision;
	tmp = malloc(sizeof(*tmp) * i);
	tmp[i] = '\0';
	if (final[k] == '-' && ++k && ++j)
		tmp[0] = '-';
	while (((check->precision)--) > ft_strlen(final))
		tmp[j++] = '0';
	if (final[0] == '-')
		tmp[j++] = '0';
	while (j < i)
		tmp[j++] = final[k++];
	free(final);
	return (tmp);
}

char	*ft_uint_zero(char *final, t_det *check)
{
	int		i;
	int		k;
	char	*tmp;
	int		j;

	k = 0;
	j = 0;
	i = ft_strlen(final) + check->len;
	tmp = malloc(sizeof(*tmp) * i);
	tmp[i] = '\0';
	if (final[k] == '-' && ++k && ++j)
		tmp[0] = '-';
	while (((check->len)--) > (ft_strlen(final)))
		tmp[j++] = '0';
	while (j < i)
		tmp[j++] = final[k++];
	free(final);
	return (tmp);
}

char	*ft_uint_jus(char *final, t_det *check)
{
	int i;

	i = ft_strlen(final);
	if (check->zero && check->minus)
		check->zero = 0;
	if (check->minus)
		while (i++ < check->justify)
			final = ft_strjoinfree(final, ft_strdup(" "));
	else
		while (i++ < check->justify)
			final = ft_strjoinfree(ft_strdup(" "), final);
	return (final);
}

char	*create_u(t_det *check, va_list *ap, t_f **fn)
{
	char	*final;
	int		len;

	final = ft_uitoa(va_arg(*ap, unsigned int));
	if (ft_strlen(final) == 1 && final[0] == '0' && check->point)
		final = ft_strdup("");
	if (final[0] == '-')
		len = ft_strlen(final) - 1;
	else
		len = ft_strlen(final);
	if (check->point)
		final = ft_uint_point(final, check);
	else if (check->zero && ((check->len) > len) && check->minus == 0)
		final = ft_uint_zero(final, check);
	if ((check->justify) > len)
		final = ft_uint_jus(final, check);
	len = ft_strlen(final) - 1;
	while (++len < check->len && check->zero)
		final = ft_strjoinfree(ft_strdup(" "), final);
	(*fn)->s = (*fn)->s + ft_strlen(final);
	return (final);
}
