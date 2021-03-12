/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:24:43 by adjemaa           #+#    #+#             */
/*   Updated: 2021/03/12 16:34:47 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_choose(char const *s, unsigned int start, size_t len)
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

char		*ft_substr(char const *s, unsigned int start, size_t len)
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
	return (str);
}
