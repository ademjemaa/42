/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:02:19 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/31 14:48:33 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "get_next_line.h"

void	check_digits(char *line, int type)
{
	int i;
	int co;

	i = 0;
	co = 0;
	while (line[i] != '\0')
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			co++;
			while (line[i] >= '0' && line[i] <= '9')
				i++;
		}
		else
			i++;
	}
	if ((type == 2 && co != 2) || ((type == 1 || type == 0) && co != 3))
	{
		ft_putstr("Error\ninvalid configuration\n");
		exit(0);
	}
}
