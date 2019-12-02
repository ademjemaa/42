/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 20:25:43 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/27 14:43:44 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;
	char	*str;

	str = (char *)format;
	va_start(ap, format);
	i = ft_caller(str, &ap);
	va_end(ap);
	return (i);
}
