/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:58:35 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/29 16:24:50 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_cat(char *dest, const char *src, int lens1, int lens2)
{
	int i;

	i = 0;
	while (i < lens2)
	{
		dest[lens1 + i] = src[i];
		i++;
	}
	dest[lens1 + i] = '\0';
	return (dest);
}

char		*ft_strjoinfreeboth(char *s1, char *s2, int lens1, int lens2)
{
	char	*str;

	if ((str = malloc(lens1 + lens2 + 1)) == NULL)
		return (NULL);
	ft_memcpy(str, s1, lens1);
	ft_cat(str, s2, lens1, lens2);
	free(s1);
	free(s2);
	return (str);
}

char		*create_c(t_det *check, va_list *ap, t_f **fn)
{
	char	*final;
	int		i;

	if ((final = malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	final[1] = '\0';
	final[0] = va_arg(*ap, int);
	i = 0;
	if (check->minus)
		while (++i < check->justify)
			final = ft_strjoinfreeboth(final, ft_strdup(" "), i, 1);
	else
		while (++i < check->justify)
			final = ft_strjoinfreeboth(ft_strdup(" "), final, 1, i);
	if (check->justify != 0)
		(*fn)->s = (*fn)->s + check->justify;
	else
		(*fn)->s = (*fn)->s + 1;
	return (final);
}
