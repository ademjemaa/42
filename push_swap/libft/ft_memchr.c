/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:54:35 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/08 13:07:11 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	h;

	i = 0;
	str = (unsigned char *)s;
	h = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == h)
			return ((unsigned char *)(str + i));
		i++;
	}
	return (NULL);
}
