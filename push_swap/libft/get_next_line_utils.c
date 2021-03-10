/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:33:53 by abarbour          #+#    #+#             */
/*   Updated: 2021/01/28 11:36:07 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*dest;

	if (!s1)
		s1 = "";
	if (!(dest = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
	{
		dest[j + i] = s2[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}

char	*ft_substrr(char *s, unsigned int start, size_t len, int crit)
{
	char	*temp;
	int		i;

	i = 0;
	if ((temp = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	temp[len] = '\0';
	while (len--)
	{
		temp[i] = s[start];
		i++;
		start++;
	}
	if (crit == 1)
		free(s);
	return (temp);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	while (*(s1 + i) != '\0')
		i++;
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(dest + i) = *(s1 + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
