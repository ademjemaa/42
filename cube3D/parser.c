/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 05:17:47 by adjemaa           #+#    #+#             */
/*   Updated: 2020/02/03 11:53:06 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "get_next_line.h"

void		check_map(t_cparam *det, char *line, int cond)
{
	int i;

	i = -1;
	if (cond)
	{
		while (line[++i])
			if (line[i] != '1')
				map_error((void*)det);
	}
	else
	{
		while (++i < det->maph - 1)
			if (det->map[det->mapv - 1][i] != 1)
				map_error((void*)det);
	}
	if (det->ceil == -1 || det->flor == -1 || det->render_v == -1 ||
	det->render_h == -1)
	{
		ft_putstr("Error\nuncorrect configuration\n");
		free(det->map);
		exit(0);
	}
}

void		init_all(t_cparam *d)
{
	d->render_h = -1;
	d->render_v = -1;
	d->maph = 0;
	d->mapv = 0;
	d->ceil = -1;
	d->flor = -1;
	d->playery = -2;
	d->playerx = -2;
	d->playerr = -2;
}

int			find_conf(char *str, int *i, int type)
{
	int val;
	int	tmp;

	while (!(str[*i] >= '0' && str[*i] <= '9') && str[*i] != '\0' &&
		str[*i] != '+' && str[*i] != '-')
		(*i)++;
	val = ft_atoi(&str[*i]);
	if (val < 0)
	{
		ft_putstr("Error\nBad screen resolution or colors\n");
		exit(0);
	}
	tmp = val;
	if (type == 1 && (val > 255 || val < 0))
	{
		ft_putstr("Error\nBad color config\n");
		exit(0);
	}
	while (tmp >= 10)
	{
		(*i)++;
		tmp = tmp / 10;
	}
	(*i)++;
	return (val);
}

void		parse_params(t_cparam *d, char *line)
{
	int		i;

	i = 0;
	if ((line[0] == 'R' && d->render_v != -1) || (line[0] == 'F'
		&& d->flor != -1) || (line[0] == 'C' && d->ceil != -1))
	{
		ft_putstr("Error\nBad line configuration\n");
		free(line);
		exit(0);
	}
	else if (line[0] == 'R')
		parse_settings(line, d, 2);
	else if (line[0] == 'F')
		parse_settings(line, d, 0);
	else if (line[0] == 'C')
		parse_settings(line, d, 1);
	else
		grab_textures(d, line);
}

t_cparam	init_params(char **argv, int argc)
{
	int			fd;
	t_cparam	details;
	char		*line;
	int			ret;

	init_all(&details);
	details.cond = 1;
	if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
		details.cond = 0;
	else if (argc != 2 || (!(ext_error(argv[1], &details, 0))))
		ext_error("", &details, 1);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
	{
		ft_putstr("Error\nFile error\n");
		exit(0);
	}
	while ((((ret = get_next_line(fd, &line)) != 0)) &&
			line[0] != '0' && line[0] != '1' && ret != -1)
	{
		parse_params(&details, line);
		free(line);
	}
	map_parser(fd, &details, line);
	return (details);
}
