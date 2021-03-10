/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:16:48 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/12 12:22:32 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*cpy;

	cpy = malloc(sizeof(*cpy) * ft_strlen(s) + 1);
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		cpy[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
