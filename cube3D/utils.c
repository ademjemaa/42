/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 02:32:54 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/12 20:46:21 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "get_next_line.h"

void	grab_textures(t_cparam *d, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		d->no = ft_strdup(&line[3]);
	else if (line[0] == 'S' && line[1] == 'O')
		d->so = ft_strdup(&line[3]);
	else if (line[0] == 'W' && line[1] == 'E')
		d->we = ft_strdup(&line[3]);
	else if (line[0] == 'E' && line[1] == 'A')
		d->ea = ft_strdup(&line[3]);
	else if (line[0] == 'S' && line[1] == ' ')
		d->s = ft_strdup(&line[2]);
}

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
				det->playery = i + 0.5;
				det->playerx = j + 0.5;
				det->playerr = det->map[i][j];
				det->map[i][j] = 0;
			}
			if (det->map[i][j] > 2 && found == 1)
				map_error();
		}
	}
}

int		calcul_params(int i, t_cparam *det, t_cam *p, t_sprite **sp)
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
	if (!(side = check_hit(p, det, sp)))
		p->walldist = fabs((p->mapx - p->posx + (1 - p->stepx) / 2) / p->rdirx);
	else
		p->walldist = fabs((p->mapy - p->posy + (1 - p->stepy) / 2) / p->rdiry);
	p->line = (int)(det->render_v / p->walldist);
	p->dstart = (-(p->line) / 2 + det->render_v / 2);
	if (p->dstart < 0)
		p->dstart = 0;
	p->dend = p->line / 2 + det->render_v / 2;
	if (p->dend >= det->render_v)
		p->dend = det->render_v - 1;
	return (side);
}

t_text	**get_texture(t_cparam *det, t_mlx *p)
{
	t_text	**tab;

	tab = (t_text**)malloc(sizeof(t_text**) * 4);
	tab[0] = (t_text*)malloc(sizeof(t_text));
	tab[1] = (t_text*)malloc(sizeof(t_text));
	tab[2] = (t_text*)malloc(sizeof(t_text));
	tab[3] = (t_text*)malloc(sizeof(t_text));
	tab[0]->image = mlx_xpm_file_to_image(p->mlx_ptr, det->no, &(tab[0]->w),
	&(tab[0]->h));
	tab[0]->text = mlx_get_data_addr(tab[0]->image, &tab[0]->bpp,
	&(tab[0]->size_line), &(tab[0]->end));
	tab[1]->image = mlx_xpm_file_to_image(p->mlx_ptr, det->so, &(tab[1]->w),
	&(tab[1]->h));
	tab[1]->text = mlx_get_data_addr((tab[1]->image), &(tab[1]->bpp),
	&(tab[1]->size_line), &(tab[1]->end));
	tab[2]->image = mlx_xpm_file_to_image(p->mlx_ptr, det->we, &(tab[2]->w),
	&(tab[2]->h));
	tab[2]->text = mlx_get_data_addr(tab[2]->image, &tab[2]->bpp,
	&tab[2]->size_line, &tab[2]->end);
	tab[3]->image = mlx_xpm_file_to_image(p->mlx_ptr, det->ea, &(tab[3]->w),
	&(tab[3]->h));
	tab[3]->text = mlx_get_data_addr(tab[3]->image, &tab[3]->bpp,
	&tab[3]->size_line, &tab[3]->end);
	return (tab);
}
