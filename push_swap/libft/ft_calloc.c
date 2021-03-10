/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:04:15 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/08 12:51:07 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*tab;

	i = 0;
	tab = (void *)(malloc(size * count));
	if (tab == NULL)
		return (NULL);
	while (i < count * size)
	{
		((unsigned char *)tab)[i] = 0;
		i++;
	}
	return ((void *)tab);
}
