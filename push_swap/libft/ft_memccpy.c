/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:46:18 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/08 14:30:02 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*org;
	unsigned char	t;

	i = 0;
	t = (unsigned char)c;
	org = (unsigned char *)src;
	str = (unsigned char *)dst;
	while (i < n)
	{
		str[i] = org[i];
		if (org[i] == t)
			return ((void *)(dst + i + 1));
		i++;
	}
	return (NULL);
}
