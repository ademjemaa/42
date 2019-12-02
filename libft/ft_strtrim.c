/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:51:59 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/12 12:22:09 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

static	int		find_end(char const *str, char const *set)
{
	int i;
	int j;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (str[i])
	{
		j = 0;
		while (set[j] != str[i] && set[j] != '\0')
			j++;
		if (set[j] == '\0')
			return (i + 1);
		i--;
	}
	return (i);
}

static	int		find_start(char const *str, char const *set)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != set[j] && set[j] != '\0')
			j++;
		if (set[j] == '\0')
			return (i);
		i++;
	}
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	total;
	char	*str;

	if (find_start(s1, set) == (int)ft_strlen(s1))
		return (ft_strnew(1));
	total = (size_t)(find_end(s1, set) - find_start(s1, set));
	if ((int)total <= 0)
		return (ft_strdup(""));
	str = ft_substr(s1, (unsigned int)(find_start(s1, set)), total);
	return (str);
}
