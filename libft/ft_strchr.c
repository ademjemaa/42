/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:34:08 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/07 20:40:42 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char		*str;
	unsigned char		h;
	int					i;

	i = 0;
	str = (unsigned char *)s;
	h = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == h)
			return ((char *)(str + i));
		i++;
	}
	if (h == '\0')
		return ((char *)(str + i));
	return (0);
}
