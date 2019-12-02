/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:01:58 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/29 14:00:54 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_choose(char *s, unsigned int start, size_t len)
{
	size_t	total;

	total = 0;
	while (s[start] && total < len)
	{
		total++;
		start++;
	}
	return (total);
}

char	*ft_substr(char *s, unsigned int start, size_t len, int con)
{
	char	*str;
	size_t	i;
	size_t	total;

	i = 0;
	if (start > (unsigned int)(ft_strlen(s)))
		return (ft_strdup(""));
	total = ft_choose(s, start, len);
	if ((str = (char *)malloc(sizeof(*s) * total + 1)) == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		str[i] = s[start++];
		i++;
	}
	str[i] = '\0';
	if (con == 1)
		free(s);
	return (str);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	int		total;
	char	*str;
	int		i;
	int		j;

	i = -1;
	total = ft_strtotal(s1) + ft_strtotal(s2);
	str = malloc(sizeof(char) * total + 1);
	if (str == NULL)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}

char	*turn_null(void)
{
	char	*final;

	if ((final = ft_strdup("(null)")) == NULL)
		return (NULL);
	return (final);
}

char	*create_s(t_det *check, va_list *ap, t_f **fn)
{
	int		i;
	char	*final;
	char	*tmp;

	if ((tmp = va_arg(*ap, char*)) == NULL)
		final = turn_null();
	else
		final = ft_strdup(tmp);
	if (check->point)
		if ((final = ft_substr(final, 0, check->precision, 1)) == NULL)
			return (NULL);
	i = ft_strlen(final);
	(*fn)->s = (*fn)->s + ft_strlen(final);
	if (check->minus)
		while (i++ < check->justify && ++((*fn)->s))
			final = ft_strjoinfree(final, ft_strdup(" "));
	else
		while (i++ < check->justify && ++((*fn)->s))
			final = ft_strjoinfree(ft_strdup(" "), final);
	return (final);
}
