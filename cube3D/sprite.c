/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:32:59 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/26 03:23:26 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		find_sprite(t_calc *cal, t_cam *p, t_sprite *sp, t_cparam *det)
{
	int i;
	int	j;

	i = -1;
	j = 0;
	while (sp[++i].dist != -1.)
		if (sp[i].dist > sp[j].dist)
			j = i;
	cal->spx = sp[j].x - p->posx + 0.5;
	cal->spy = sp[j].y - p->posy + 0.5;
	cal->inv = 1.0 / (p->planex * p->diry - p->dirx * p->planey);
	while (j < i)
	{
		sp[j].x = sp[j + 1].x;
		sp[j].y = sp[j + 1].y;
		sp[j].dist = sp[j + 1].dist;
		j++;
	}
	cal->tranx = cal->inv * (p->diry * cal->spx - p->dirx * cal->spy);
	cal->trany = cal->inv * (-(p->planey) * cal->spx + p->planex * cal->spy);
	cal->spscx = (int)((det->render_h / 2) * (1 + cal->tranx / cal->trany));
	cal->sph = abs((int)(det->render_v / (cal->trany)));
	cal->dstarty = (-(cal->sph)) / 2 + det->render_v / 2;
	cal->dendy = cal->sph / 2 + det->render_v / 2;
	cal->spw = abs((int)(det->render_v / (cal->trany)));
}

void		ver_sprite(t_cam *p, t_sprite *sp, t_cparam *det)
{
	t_calc	cal;

	while (sp[0].dist != -1)
	{
		find_sprite(&cal, p, sp, det);
		cal.i = find_dstart(&cal, det) - 1;
		while (++(cal.i) < cal.dendx)
		{
			sprite_calcul(&cal, det, 0, p);
			if (cal.cond)
			{
				cal.y = cal.dstarty - 1;
				while (++(cal.y) < cal.dendy)
				{
					sprite_calcul(&cal, det, 1, p);
					if (ft_memcmp(det->text + det->w * 4 * cal.tey + cal.tex
						* 4, &(cal.color), sizeof(int)))
						ft_memcpy(p->i_p + 4 * det->render_h * cal.y +
						cal.i * 4, det->text + cal.tey * 4 * det->w
						+ cal.tex * 4, sizeof(int));
				}
			}
		}
	}
	free(p->zbuffer);
}

void		init_dda(t_cam *p, t_sprite **sp, t_cparam *det, t_mlx *par)
{
	p->ddistx = 0;
	p->ddisty = 0;
	if ((*sp = (t_sprite*)malloc(sizeof(t_sprite))) == NULL)
		return ;
	sp[0]->dist = -1;
	p->image = mlx_new_image(par->mlx_ptr, det->render_h, det->render_v);
	p->i_p = mlx_get_data_addr(p->image, &(p->bpp), &(p->size_l), &(p->endian));
	if ((p->zbuffer = malloc(sizeof(double) * det->render_h)) == NULL)
		return ;
}

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

void		add_sprite(int x, int y, t_cam *p, t_sprite **sp)
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
