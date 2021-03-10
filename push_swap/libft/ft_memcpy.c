/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:00:30 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/06 18:24:38 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*origin;

	i = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	str = (unsigned char *)dst;
	origin = (unsigned char *)src;
	while (i < n)
	{
		str[i] = origin[i];
		i++;
	}
	return (dst);
}
