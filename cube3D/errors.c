/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:21:12 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/31 15:46:00 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "get_next_line.h"

void	parse_settings(char *line, t_cparam *d, int type)
{
	int	i;

	i = 0;
	check_digits(line, type);
	if (type == 0)
	{
		d->flor = (find_conf(line, &i, 1) * 65536) +
		(find_conf(line, &i, 1) * 256) + find_conf(line, &i, 1);
	}
	else if (type == 1)
	{
		d->ceil = (find_conf(line, &i, 1) * 65536) +
		(find_conf(line, &i, 1) * 256) + find_conf(line, &i, 1);
	}
	else if (type == 2)
	{
		if (((d->render_h = find_conf(line, &i, 0)) > 2560) || d->render_h <= 0
		|| ((d->render_v = find_conf(line, &i, 0)) > 1440) || d->render_v <= 0)
		{
			d->render_v = 1440;
			d->render_h = 2560;
		}
	}
}

void	map_parser(int fd, t_cparam *details, char *line)
{
	details->maph = ft_strlen(line);
	parse_map(details, line);
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) != details->maph)
			map_error((void*)details);
		parse_map(details, line);
	}
	(details->maph)--;
	place_player(details);
}

void	position_error(t_cparam *det)
{
	if (det->playery == -2 && det->playerx == -2 && det->playerr == -2)
	{
		ft_putstr("Error\nNo start position\n");
		free(det->map);
		exit(0);
	}
}

int		ext_error(char *str, t_cparam *det, int type)
{
	int i;
	int res;

	i = ft_strlen(str) - 4;
	res = 1;
	if (type)
	{
		ft_putstr("Error\nBad arguements format\n");
		exit(0);
		return (0);
	}
	if (str[i] == '.')
		res = ft_strcmp(&str[i], ".cub");
	if (res != 0 || str[i] != '.')
	{
		ft_putstr("Error\nBad file name\n");
		exit(0);
		return (0);
	}
	return (1);
}

void	text_error(t_text **tab, t_cparam *d)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tab[i]->image == NULL || d->image == NULL)
		{
			ft_putstr("Error\nBad image configuration\n");
			i = 0;
			while (i < 4)
			{
				free(tab[i]);
				i++;
			}
			free(tab);
			free(d->map);
			exit(0);
		}
		tab[i]->text = mlx_get_data_addr(tab[i]->image, &tab[i]->bpp,
		&(tab[i]->size_line), &(tab[i]->end));
		i++;
	}
	d->text = mlx_get_data_addr(d->image, &(d->bpp), &(d->s_l), &(d->end));
}
