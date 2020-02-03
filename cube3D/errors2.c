/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:02:19 by adjemaa           #+#    #+#             */
/*   Updated: 2020/02/03 17:41:48 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "get_next_line.h"

int		check_tp(t_cparam *det, t_cam *p, int i, int j)
{
	int c;

	c = rand() % 1000;
	if (det->map[i][j] == 2)
	{
		if (c > 90)
		{
			p->dirx = -1;
			p->diry = 0;
			p->posy = j + 0.5;
			p->posx = i + 0.5;
			det->map[i][j] = 0;
			p->planex = 0;
			p->planey = 0.66;
			return (1);
		}
	}
	return (0);
}

void	teleportation(t_cam *p, t_cparam *det, int keycode)
{
	int	i;
	int	j;

	i = 0;
	printf("%d\n", keycode);
	if (keycode == 12)
		if (det->map[(int)(p->posx)][(int)(p->posy + p->diry * 0.2)] == 2)
		{
			while (i < det->mapv)
			{
				j = 0;
				while (j < det->maph)
				{
					if (check_tp(det, p, i, j))
						return ;
					j++;
				}
				i++;
			}
		}
}

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
