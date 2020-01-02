/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:57:04 by adjemaa           #+#    #+#             */
/*   Updated: 2019/12/26 00:22:32 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	move_ud(int keycode, t_cam *p, t_cparam *det)
{
	if (keycode == 126)
	{
		if (det->map[(int)p->posy][(int)(p->posx + p->dirx)] == 0)
			p->posx += (p->dirx * 0.15);
		if (det->map[(int)(p->posy + p->diry)][(int)p->posx] == 0)
			p->posy += (p->diry * 0.15);
	}
	if (keycode == 125)
	{
		if (det->map[(int)p->posy][(int)(p->posx - p->dirx)] == 0)
			p->posx -= (p->dirx * 0.09);
		if (det->map[(int)(p->posy - p->diry)][(int)p->posx] == 0)
			p->posy -= (p->diry * 0.09);
	}
}

void	move_lr(int keycode, t_cam *p, double var)
{
	double	olddirx;
	double	oldplanex;
	int		i;


	i = 0;
	if (keycode == 124)
	{
		while (i < 10)
		{
			oldplanex = p->planex;
			olddirx = p->dirx;
			p->dirx = p->dirx * cos(-var) - p->diry * sin(-var);
			p->diry = olddirx * sin(-var) + p->diry * cos(-var);
			p->planex = p->planex * cos(-var) - p->planey * sin(-var);
			p->planey = oldplanex * sin(-var) + p->planey * cos(-var);
			i++;
		}
	}
	if (keycode == 123)
	{
		while (i < 10)
		{
			oldplanex = p->planex;
			olddirx = p->dirx;
			p->dirx = p->dirx * cos(var) - p->diry * sin(var);
			p->diry = olddirx * sin(var) + p->diry * cos(var);
			p->planex = p->planex * cos(var) - p->planey * sin(var);
			p->planey = oldplanex * sin(var) + p->planey * cos(var);
			i++;
		}
	}
}

void	saker(t_mlx *par, t_cam *p, t_cparam *det)
{
	mlx_destroy_window(par->mlx_ptr, par->mlx_win);
	free(p);
	free(det);
	free(par);
	exit(0);
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
	mlx_clear_window(par->mlx_ptr, par->mlx_win);
	if (keycode == 126 || keycode == 125)
		move_ud(keycode, p, det);
	if (keycode == 124 || keycode == 123)
		move_lr(keycode, p, 0.006);
	if (keycode == 53)
		saker(par, p, det);
	draw(par, det, p, txt);
	return (1);
}
