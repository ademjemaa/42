/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:02:55 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/06 17:08:44 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*str;
	const unsigned char	*org;

	i = 0;
	str = (unsigned char *)dst;
	org = (const unsigned char *)src;
	if (str == NULL && org == NULL)
		return (NULL);
	if (org < str)
		while (++i <= len)
			str[len - i] = org[len - i];
	else
	{
		while (len-- > 0)
			*(str++) = *(org++);
	}
	return (dst);
}
