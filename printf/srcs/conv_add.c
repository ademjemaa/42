/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:55:50 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/27 18:23:58 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*origin;

	i = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	str = (unsigned char *)dst;
	origin = (unsigned char *)src;
	while (i < n)
	{
		str[i] = origin[i];
		i++;
	}
	return (dst);
}

char	*ft_cat_one(char *tab, char c)
{
	char	*tmp;
	int		i;

	i = ft_strlen(tab);
	if ((tmp = malloc(sizeof(*tmp) * i + 2)) == NULL)
		return (NULL);
	tmp[i + 1] = '\0';
	ft_memcpy(tmp + 1, tab, i);
	tmp[0] = c;
	free(tab);
	return (tmp);
}

char	*addr_conv(void *final, t_f **fn)
{
	size_t	addr;
	char	*hexa;
	char	*tab;

	hexa = "0123456789abcdef";
	addr = (size_t)final;
	if ((tab = ft_strdup("")) == NULL)
		return (NULL);
	while (addr > 0)
	{
		if ((tab = ft_cat_one(tab, hexa[addr % 16])) == NULL)
			return (NULL);
		(*fn)->s = (*fn)->s + 1;
		addr = addr / 16;
	}
	(*fn)->s = (*fn)->s + 2;
	return (ft_strjoinfree(ft_strdup("0x"), tab));
}

char	*ft_set_addr(va_list *ap, t_f **fn)
{
	char	*final;

	if ((final = va_arg(*ap, void*)) == NULL)
	{
		(*fn)->s = (*fn)->s + 3;
		return (ft_strdup("0x0"));
	}
	final = addr_conv(final, fn);
	return (final);
}

char	*create_p(t_det *check, va_list *ap, t_f **fn)
{
	int		i;
	char	*final;

	if ((final = ft_set_addr(ap, fn)) == NULL)
		return (NULL);
	i = ft_strlen(final);
	if (check->minus)
		while (i++ < check->justify && ++((*fn)->s))
			final = ft_strjoinfree(final, ft_strdup(" "));
	else
		while (i++ < check->justify && ++((*fn)->s))
			final = ft_strjoinfree(ft_strdup(" "), final);
	return (final);
}
