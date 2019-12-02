/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:40:51 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/07 16:51:36 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_strtotal(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
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
	return (str);
}
