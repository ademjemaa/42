/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:00:20 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/29 16:42:55 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_det	*fac_set(t_det *check)
{
	check = (t_det*)malloc(sizeof(t_det));
	if (check == NULL)
		return (NULL);
	check->conv = 0;
	check->len = 0;
	check->minus = 0;
	check->zero = 0;
	check->precision = 0;
	check->point = 0;
	check->justify = 0;
	return (check);
}

char	*use_conv(va_list *ap, t_det *check, t_f **fn)
{
	if (check->conv == 's')
		(*fn)->f = create_s(check, ap, fn);
	else if (check->conv == 'c')
		(*fn)->f = create_c(check, ap, fn);
	else if (check->conv == 'd')
		(*fn)->f = create_d(check, ap, fn);
	else if (check->conv == 'p')
		(*fn)->f = create_p(check, ap, fn);
	else if (check->conv == 'i')
		(*fn)->f = create_d(check, ap, fn);
	else if (check->conv == 'u')
		(*fn)->f = create_u(check, ap, fn);
	else if (check->conv == 'x' || check->conv == 'X')
		(*fn)->f = create_x(check, ap, fn);
	else if (check->conv == '%')
		(*fn)->f = create_pr(check, fn);
	return ((*fn)->f);
}

int		conv_speci(char c, t_det *check)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
	{
		check->conv = c;
		return (1);
	}
	return (0);
}

void	ft_parse(va_list *ap, char **format, t_f **fn, t_det **check)
{
	int i;

	i = (*fn)->s;
	(*format)++;
	while (**format != '\0' && conv_speci(**format, *check) != 1)
	{
		if (**format == '-')
			*format = take_minus(*format + 1, *check, ap);
		else if (**format == '0' && (*check)->zero == 0)
			*format = take_zero((*format) + 1, *check, ap);
		else if (**format == '.' && (*check)->point == 0)
			*format = take_point((*format) + 1, *check, ap);
		else if (((**format) >= '0' && (**format) <= '9')
			|| (**format) == '*')
			*format = take_width((*format), *check, ap);
	}
	(*fn)->f = ft_strjoinfreeboth((*fn)->f,
	use_conv(ap, *check, fn), i, (*fn)->s);
}

int		ft_caller(char *str, va_list *ap)
{
	t_f		*fn;
	t_det	*check;

	fn = (t_f*)malloc(sizeof(t_f));
	fn->f = ft_strdup("");
	fn->s = 0;
	while (*str)
	{
		if ((check = fac_set(check)) == NULL)
			return (0);
		if (*str == '%' && (str + 1) != '\0')
			ft_parse(ap, &str, &fn, &check);
		else
		{
			fn->f = ft_strjoinfreeboth(fn->f,
			ft_substr(str, 0, 1, 0), fn->s, 1);
			(fn->s)++;
		}
		free(check);
		str++;
	}
	return (ft_purstr(fn->f, fn->s, fn));
}
