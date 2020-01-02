/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 02:32:54 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/02 22:59:38 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_sky_floor(int x, t_cam *p, t_cparam *det)
{
	int i;
	int color;

	color = det->ceil;
	i = 0;
	while (i < p->dstart)
	{
		ft_memcpy(p->i_p + 4 * det->render_h * i + x * 4, &color, sizeof(int));
		i++;
	}
	i = p->dend;
	color = det->flor;
	while (i < det->render_v)
	{
		ft_memcpy(p->i_p + 4 * det->render_h * i + x * 4, &color, sizeof(int));
		i++;
	}
}

void	place_player(t_cparam *det)
{
	int i;
	int j;
	int	found;

	i = -1;
	found = 0;
	check_map(det, "", 0);
	while (++i < det->mapv - 1)
	{
		j = -1;
		while (++j < det->maph - 1)
		{
			if (det->map[i][j] > 2 && found == 0 && (found = 1))
			{
				det->playerx = i + 0.5;
				det->playery = j + 0.5;
				det->playerr = det->map[i][j];
				det->map[i][j] = 0;
			}
			if (det->map[i][j] > 2 && found == 1)
				map_error();
		}
	}
}

int		calcul_params(int i, t_cparam *det, t_cam *p)
{
	int side;

	p->camx = 2 * i / (double)det->render_h - 1;
	p->rdirx = p->dirx + p->planex * p->camx;
	p->rdiry = p->diry + p->planey * p->camx;
	p->mapx = (int)(p->posx);
	p->mapy = (int)(p->posy);
	p->ddistx = sqrt(1 + ((p->rdiry * p->rdiry) / (p->rdirx * p->rdirx)));
	p->ddisty = sqrt(1 + ((p->rdirx * p->rdirx) / (p->rdiry * p->rdiry)));
	step_cal(p);
	if (!(side = check_hit(p, det)))
		p->walldist = ((p->mapx - p->posx + (1 - p->stepx) / 2) / p->rdirx);
	else
		p->walldist = ((p->mapy - p->posy + (1 - p->stepy) / 2) / p->rdiry);
	p->line = (int)(det->render_v / p->walldist);
	p->dstart = (-(p->line) / 2 + det->render_v / 2) - 1;
	if (p->dstart < 0)
		p->dstart = 0;
	p->dend = p->line / 2 + det->render_v / 2;
	if (p->dend >= det->render_v)
		p->dend = det->render_v - 1;
	return (side);
}

t_text	**get_texture(int type, t_mlx *par)
{
	t_text	**tab;

	tab = (t_text**)malloc(sizeof(t_text**) * 4);
	tab[0] = (t_text*)malloc(sizeof(t_text));
	tab[1] = (t_text*)malloc(sizeof(t_text));
	tab[2] = (t_text*)malloc(sizeof(t_text));
	tab[3] = (t_text*)malloc(sizeof(t_text));
	tab[0]->image = mlx_xpm_file_to_image(par->mlx_ptr, "south.xpm", &(tab[0]->width),
	&((tab[0])->height));
	tab[0]->text = mlx_get_data_addr(tab[0]->image, &tab[0]->bpp, &(tab[0]->size_line), &(tab[0]->end));
	tab[1]->image = mlx_xpm_file_to_image(par->mlx_ptr, "west.xpm", &(tab[1]->width),
	&((tab[1])->height));
	tab[1]->text = mlx_get_data_addr((tab[1]->image), &(tab[1]->bpp), &(tab[1]->size_line), &(tab[1]->end));
	tab[2]->image = mlx_xpm_file_to_image(par->mlx_ptr, "north.xpm", &(tab[2]->width),
	&((tab[2])->height));
	tab[2]->text = mlx_get_data_addr(tab[2]->image, &tab[2]->bpp, &tab[2]->size_line, &tab[2]->end);
	tab[3]->image = mlx_xpm_file_to_image(par->mlx_ptr, "east.xpm", &(tab[3]->width),
	&((tab[3])->height));
	tab[3]->text = mlx_get_data_addr(tab[3]->image, &tab[3]->bpp, &tab[3]->size_line, &tab[3]->end);
	printf("%d %d %d %d %d %d %d %d\n", tab[0]->width, tab[1]->width, tab[2]->width, tab[3]->width, tab[0]->height, tab[1]->height, tab[2]->height, tab[3]->height);



	return (tab);
}
