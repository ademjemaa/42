/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:24:17 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/05 20:09:08 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && needle[j] != '\0' && i < len)
	{
		if (haystack[i] == needle[j])
			j++;
		else if (haystack[i] == needle[0])
			j = 1;
		else
			j = 0;
		i++;
	}
	if (needle[j] == '\0')
		return ((char *)(haystack + (i - j)));
	return (0);
}
