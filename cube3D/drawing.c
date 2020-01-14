/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 04:58:10 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/12 22:30:41 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "get_next_line.h"

void	verline(int x, t_cam *p, t_cparam *d, t_text *txt)
{
	int i;
	int aux;

	if (p->dend < p->dstart)
	{
		p->dstart += p->dend;
		p->dend = p->dstart - p->dend;
		p->dstart -= p->dend;
	}
	if (p->dend < 0 || p->dstart >= d->render_v || x < 0 || x >= d->render_h)
		return ;
	i = p->dstart;
	while (++i < p->dend)
	{
		aux = (((i * 256 - d->render_v * 128 + p->line * 128) *
		txt->h) / p->line) / 256;
		if (aux > txt->h - 1)
			aux = txt->h - 1;
		ft_memcpy(p->i_p + 4 * d->render_h * i + x * 4,
		txt->text + aux * 4 * txt->w + p->texx * 4, sizeof(int));
	}
}

int		get_side(t_cam *p, int side, t_text **txt)
{
	if (side == 0)
	{
		p->wallx = p->posy + p->walldist * p->rdiry;
		if (p->rdirx >= 0)
			return (2);
		else
			return (3);
	}
	else
	{
		p->wallx = p->posx + p->walldist * p->rdirx;
		if (p->rdiry >= 0)
			return (0);
		else
			return (1);
	}
	return (0);
}

t_cam	init_player(t_cparam *det)
{
	t_cam	play;
	double	var;

	var = 0;
	play.dirx = -1;
	play.diry = 0;
	play.posy = det->playerx;
	play.posx = det->playery;
	if (det->playerr == 69)
		var = 3;
	else if (det->playerr == 83)
		var = 2;
	else if (det->playerr == 78)
		var = 0;
	else if (det->playerr == 87)
		var = 1;
	play.planex = 0;
	play.planey = 0.66;
	move_lr(123, &play, (double)((M_PI / 2) * var));
	return (play);
}

void	step_cal(t_cam *play)
{
	if (play->rdirx < 0)
	{
		play->stepx = -1;
		play->sdistx = ((play->posx - play->mapx) * play->ddistx);
	}
	else
	{
		play->stepx = 1;
		play->sdistx = ((play->mapx + 1) - play->posx) * play->ddistx;
	}
	if (play->rdiry < 0)
	{
		play->stepy = -1;
		play->sdisty = (play->posy - play->mapy) * play->ddisty;
	}
	else
	{
		play->stepy = 1;
		play->sdisty = ((play->mapy + 1) - play->posy) * play->ddisty;
	}
}

void	draw(t_mlx *par, t_cparam *det, t_cam *p, t_text **txt)
{
	int			i;
	int			side;
	int			bruh;
	t_sprite	*sp;

	i = -1;
	p->ddistx = 0;
	p->ddisty = 0;
	sp = (t_sprite*)malloc(sizeof(t_sprite));
	sp[0].dist = -1;
	p->image = mlx_new_image(par->mlx_ptr, det->render_h, det->render_v);
	p->i_p = mlx_get_data_addr(p->image, &(p->bpp), &(p->size_l), &(p->endian));
	while (++i < det->render_h)
	{
		side = calcul_params(i, det, p, &sp);
		bruh = get_side(p, side, txt);
		texture_cal(txt[bruh], p, bruh);
		verline(i, p, det, txt[bruh]);
		draw_sky_floor(i, p, det);
	}
	mlx_put_image_to_window(par->mlx_ptr, par->mlx_win, p->image, 0, 0);
	mlx_destroy_image(par->mlx_ptr, p->image);
}
