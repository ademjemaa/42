/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:57:04 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/31 15:41:06 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	move_ud(int keycode, t_cam *p, t_cparam *det)
{
	if (keycode == 13)
	{
		if (det->map[(int)(p->posx + p->dirx * 0.2)][(int)(p->posy)] == 0)
			p->posx += (p->dirx * 0.2);
		if (det->map[(int)(p->posx)][(int)(p->posy + p->diry * 0.2)] == 0)
			p->posy += (p->diry * 0.2);
	}
	if (keycode == 1)
	{
		if (det->map[(int)(p->posx - p->dirx * 0.2)][(int)(p->posy)] == 0)
			p->posx -= (p->dirx * 0.2);
		if (det->map[(int)(p->posx)][(int)(p->posy - p->diry * 0.2)] == 0)
			p->posy -= (p->diry * 0.2);
	}
}

void	move_lr(int keycode, t_cam *p, double var)
{
	double	olddirx;
	double	oldplanex;

	if (keycode == 124)
	{
		oldplanex = p->planex;
		olddirx = p->dirx;
		p->dirx = p->dirx * cos(-var) - p->diry * sin(-var);
		p->diry = olddirx * sin(-var) + p->diry * cos(-var);
		p->planex = p->planex * cos(-var) - p->planey * sin(-var);
		p->planey = oldplanex * sin(-var) + p->planey * cos(-var);
	}
	if (keycode == 123)
	{
		oldplanex = p->planex;
		olddirx = p->dirx;
		p->dirx = p->dirx * cos(var) - p->diry * sin(var);
		p->diry = olddirx * sin(var) + p->diry * cos(var);
		p->planex = p->planex * cos(var) - p->planey * sin(var);
		p->planey = oldplanex * sin(var) + p->planey * cos(var);
	}
}

void	move_ad(int keycode, t_cam *p, t_cparam *det)
{
	if (keycode == 0)
	{
		if (det->map[(int)(p->posx)][(int)(p->posy + p->dirx * 0.2)] == 0)
			p->posy += (p->dirx * 0.2);
		if (det->map[(int)(p->posx - p->diry * 0.2)][(int)(p->posy)] == 0)
			p->posx -= (p->diry * 0.2);
	}
	if (keycode == 2)
	{
		if (det->map[(int)(p->posx)][(int)(p->posy - p->dirx * 0.2)] == 0)
			p->posy -= (p->dirx * 0.09);
		if (det->map[(int)(p->posx + p->diry * 0.2)][(int)(p->posy)] == 0)
			p->posx += (p->diry * 0.09);
	}
}

int		saker(void *params)
{
	t_cparam	*det;
	t_text		**txt;
	t_mlx		*par;
	void		**tab;

	tab = (void **)params;
	det = tab[1];
	par = tab[0];
	txt = tab[3];
	mlx_destroy_window(par->mlx_ptr, par->mlx_win);
	free(det->map);
	free(txt);
	exit(0);
	return (0);
}

int		move(int keycode, void *params)
{
	t_cam		*p;
	t_mlx		*par;
	t_cparam	*det;
	void		**tab;
	t_text		**txt;

	tab = (void **)params;
	det = tab[1];
	par = tab[0];
	p = tab[2];
	txt = tab[3];
	if (keycode == 1 || keycode == 13)
		move_ud(keycode, p, det);
	if (keycode == 124 || keycode == 123)
		move_lr(keycode, p, 0.06);
	if (keycode == 53)
		saker(params);
	if (keycode == 0 || keycode == 2)
		move_ad(keycode, p, det);
	teleportation(p, det, keycode);
	draw(par, det, p, txt);
	return (1);
}
