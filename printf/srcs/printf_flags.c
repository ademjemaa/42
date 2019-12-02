/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:43:48 by adjemaa           #+#    #+#             */
/*   Updated: 2019/12/01 17:02:20 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_purstr(char *str, int j, t_f *fn)
{
	int i;

	i = 0;
	while (i < j)
	{
		if (str[i] == 0)
		{
			write(1, 0, 1);
		}
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	free(fn);
	return (j);
}

char	*take_width(char *format, t_det *check, va_list *ap)
{
	int temp;
	int	dec;

	dec = 0;
	if (*format == '*' && ++dec)
		temp = va_arg(*ap, int);
	else
		temp = ft_atoi(format, &dec);
	if (temp < 0)
	{
		check->minus = 1;
		temp = -temp;
	}
	check->justify = temp;
	check->zero = 1;
	return (format + dec);
}

char	*take_point(char *format, t_det *check, va_list *ap)
{
	int	temp;
	int	dec;

	dec = 0;
	if (*format == '*' && ++dec)
		temp = va_arg(*ap, int);
	else
		temp = ft_atoi(format, &dec);
	check->precision = temp;
	check->point = 1;
	return (format + dec);
}

char	*take_zero(char *format, t_det *check, va_list *ap)
{
	int	temp;
	int	dec;

	dec = 0;
	if (*format == '*' && ++dec)
		temp = va_arg(*ap, int);
	else
		temp = ft_atoi(format, &dec);
	if (temp < 0)
	{
		temp = -temp;
		check->minus = 1;
		check->justify = temp;
	}
	else
	{
		check->len = temp;
		check->zero = 1;
	}
	return (format + dec);
}

char	*take_minus(char *format, t_det *check, va_list *ap)
{
	int	temp;
	int	dec;

	dec = 0;
	if (*format == '*' && ++dec)
		temp = va_arg(*ap, int);
	else
		temp = ft_atoi(format, &dec);
	if (temp < 0)
		temp = -temp;
	check->justify = temp;
	check->minus = 1;
	return (format + dec);
}
