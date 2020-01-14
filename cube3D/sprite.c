/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:32:59 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/12 23:06:42 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_sprite	*re_sprites(t_sprite **sp, int x, int y, t_cam *p)
{
	t_sprite	*tmp;
	int			i;

	i = 0;
	while ((*sp + i)->dist != -1.)
		i++;
	tmp = (t_sprite*)malloc(sizeof(t_sprite) * (i + 2));
	i = 0;
	while ((*sp + i)->dist != -1.)
	{
		tmp[i].x = (*sp + i)->x;
		tmp[i].y = (*sp + i)->y;
		tmp[i].dist = (*sp + i)->dist;
		i++;
	}
	tmp[i].x = x;
	tmp[i].y = y;
	tmp[i].dist = pow((p->posx - x), 2) + pow((p->posy - y), 2);
	tmp[i + 1].dist = -1;
	free(*sp);
	return (tmp);
}

void	add_sprite(int x, int y, t_cam *p, t_sprite **sp)
{
	int	i;
	i = 0;

	while ((*sp + i)->dist != -1)
	{
		if ((*sp + i)->x == x && (*sp + i)->y == y)
			return ;
		i++;
	}
	*sp = re_sprites(sp, x, y, p);
}
