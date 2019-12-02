/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:18:25 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/04 19:16:23 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (to_find)
	{
		while (str[i] != '\0' && to_find[j] != '\0')
		{
			if (str[i] == to_find[j])
				j++;
			else if (str[i] == to_find[0])
				j = 1;
			else
				j = 0;
			i++;
		}
		if (to_find[j] == '\0')
			return (&str[i - j]);
		return (0);
	}
	return (str);
}
