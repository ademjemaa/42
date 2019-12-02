/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:09:48 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/05 18:35:10 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int pos;

	i = 0;
	pos = -1;
	while (s[i])
	{
		if (s[i] == c)
			pos = i;
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	if (pos != -1)
		return ((char *)(s + pos));
	return (NULL);
}
