/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 22:01:55 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/07 16:50:53 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		size(char const *str, char c)
{
	int i;

	i = 1;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str && *str != c)
		{
			i++;
			while (*str && *str != c)
				str++;
		}
	}
	return (i);
}

static	char	*ft_strddup(const char *str, char c)
{
	char	*tab;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	tab = (char *)malloc(sizeof(char *) * (i + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static	void	ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (size(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tab[i] = ft_strddup(s, c);
			if (tab[i] == NULL)
				ft_free(tab, size(s, c));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = 0;
	return (tab);
}
