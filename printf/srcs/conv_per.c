/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_per.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:48:48 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/27 20:56:06 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_pr(t_det *check, t_f **fn)
{
	int		i;
	char	*final;

	if ((final = ft_strdup("%")) == NULL)
		return (NULL);
	i = 1;
	if (check->len > 1 && check->zero && check->minus == 0)
		final = ft_int_zero(final, check);
	if (check->justify > 1)
		final = ft_int_jus(final, check);
	(*fn)->s = (*fn)->s + ft_strlen(final);
	return (final);
}
