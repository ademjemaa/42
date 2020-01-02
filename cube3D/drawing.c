/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 04:58:10 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/02 23:07:53 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "get_next_line.h"

void	verline(int x, t_cam *p, t_cparam *det, t_text *txt)
{
	int i;
	int	color;
	int aux;

	color = p->color;
	if (p->dend < p->dstart)
	{
		p->dstart += p->dend;
		p->dend = p->dstart - p->dend;
		p->dstart -= p->dend;
	}
	if (p->dend < 0 || p->dstart >= det->render_v || x < 0 ||
		x >= det->render_h)
		return ;
	if (p->dstart < 0)
		p->dstart = 0;
	if (p->dend >= det->render_v)
		p->dend = det->render_v;
	i = p->dstart - 1;
	while (++i < p->dend)
	{
	//	ft_memcpy(p->i_p + 4 * det->render_h * i + x * 4,
	//	&color, sizeof(int));
		aux = (int)((i - p->dstart) * (txt->height / (p->dend - p->dstart))) * txt->width * 4 + x * txt->width / det->render_h * 4;
		if (aux > (txt->width * txt->height * 4))
			aux = txt->width * txt->height * 4;
		ft_memcpy(p->i_p + 4 * det->render_h * i + x * 4, txt->text + aux, sizeof(int));
	}
}

int	get_side(t_cam *p, int side)
{
	if (side == 0)
	{
		if (p->rdirx >= 0)
			return (0);
		else
			return (1);
	}
	else
	{
		if (p->rdiry >= 0)
			return (2);
		else
			return (3);
	}
	return (0);
}

t_cam	*init_player(t_cparam *det)
{
	t_cam	*play;
	double	 var;

	var = 0;
	if ((play = (t_cam*)malloc(sizeof(t_cam))) == NULL)
		return (NULL);
	play->dirx = -1;
	play->diry = 0;
	play->posy = det->playerx;
	play->posx = det->playery;
	if (det->playerr == 69)
		var = 2;
	else if (det->playerr == 83)
		var = 3;
	else if (det->playerr == 78)
		var = 3;
	else if (det->playerr == 87)
		var = 0;
	play->planex = 0;
	play->planey = 0.66;
	move_lr(123, play, (double)((M_PI / 4) * var));
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
		play->sdistx = ((play->mapx + 1.0) - play->posx) * play->ddistx;
	}
	if (play->rdiry < 0)
	{
		play->stepy = -1;
		play->sdisty = (play->posy - play->mapy) * play->ddisty;
	}
	else
	{
		play->stepy = 1;
		play->sdisty = ((play->mapy + 1.0) - play->posy) * play->ddisty;
	}
}

int		check_hit(t_cam *p, t_cparam *det)
{
	int	hit;
	int side;

	hit = 0;
	while (hit == 0)
	{
		if (p->sdistx < p->sdisty)
		{
			p->sdistx += p->ddistx;
			p->mapx += p->stepx;
			side = 0;
		}
		else
		{
			p->sdisty += p->ddisty;
			p->mapy += p->stepy;
			side = 1;
		}
		if (det->map[p->mapy][p->mapx] > 0)
			hit = 1;
	}
	return (side);
}

void	draw(t_mlx *par, t_cparam *det, t_cam *p, t_text **txt)
{
	int		i;
	int		side;
	int		bruh;

	i = -1;
	p->ddistx = 0;
	p->ddisty = 0;
	p->image = mlx_new_image(par->mlx_ptr, det->render_h, det->render_v);
	p->i_p = mlx_get_data_addr(p->image, &(p->bpp), &(p->size_l), &(p->endian));
	while (++i < det->render_h)
	{
		side = calcul_params(i, det, p);
		p->color = get_side(p, side);
		bruh = get_side(p, side);
		verline(i, p, det, txt[bruh]);
		draw_sky_floor(i, p, det);
	}
	mlx_put_image_to_window(par->mlx_ptr, par->mlx_win, p->image, 0, 0);
	mlx_destroy_image(par->mlx_ptr, p->image);
}
