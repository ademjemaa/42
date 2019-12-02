/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:05:34 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/07 17:14:01 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*str;
	unsigned char		*ptr;

	i = 0;
	str = (unsigned char *)s1;
	ptr = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str[i] == ptr[i] && i < n - 1)
		i++;
	return ((int)str[i] - (int)ptr[i]);
}
