/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:46:43 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/13 15:28:44 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	size_t			i;

	i = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	pdst = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	while (i < n)
	{
		*pdst = *psrc;
		i++;
		pdst++;
		psrc++;
	}
	return (dest);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = ft_strlen(src);
	if ((ptr = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len, int crit)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	int		len1;
	int		len2;
	char	*str;

	i = -1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len1 = (int)ft_strlen(s1);
	len2 = (int)ft_strlen(s2);
	if ((str = malloc(len1 + len2 + 1)) == NULL)
		return (NULL);
	str = (char*)ft_memcpy(str, s1, ft_strlen(s1));
	str[len1 + len2] = '\0';
	len = len1;
	while (++i < len2)
		str[len + i] = s2[i];
	free((char*)s1);
	return (str);
}
