/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 05:17:47 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/02 22:57:30 by adjemaa          ###   ########.fr       */
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
				map_error();
	}
	else
	{
		while (++i < det->maph - 1)
			if (det->map[det->mapv - 1][i] != 1)
				map_error();
	}
}

void		init_all(t_cparam *d)
{
	d->render_h = 1;
	d->render_v = 1;
	d->maph = 0;
	d->mapv = 0;
}

int			find_config(char *str, int *i)
{
	int val;
	int	tmp;

	while (!(str[*i] >= '0' && str[*i] <= '9') && str[*i] != '\0')
		(*i)++;
	val = ft_atoi(&str[*i]);
	tmp = val;
	while (tmp >= 10)
	{
		(*i)++;
		tmp = tmp / 10;
	}
	(*i)++;
	return (val);
}

void		parse_params(t_cparam *d, char *str)
{
	int		i;
	char	*line;

	i = 0;
	line = ft_strdup(str);
	if (line[0] == 'R')
	{
		d->render_h = find_config(line, &i);
		d->render_v = find_config(line, &i);
	}
	else if (line[0] == 'F')
	{
		d->flor = (find_config(line, &i) * 65536);
		d->flor += (find_config(line, &i) * 256);
		d->flor += find_config(line, &i);
	}
	else if (line[0] == 'C')
	{
		d->ceil = (find_config(line, &i) * 65536);
		d->ceil += (find_config(line, &i) * 256);
		d->ceil += find_config(line, &i);
	}
}

t_cparam	*init_params(char **argv)
{
	int			fd;
	t_cparam	*details;
	char		*line;
	int			ret;

	if ((details = (t_cparam*)malloc(sizeof(t_cparam))) == NULL)
		return (NULL);
	init_all(details);
	fd = open(argv[1], O_RDWR);
	while ((((ret = get_next_line(fd, &line)) == 1)) && line[0] != '\0' &&
			line[0] != '0' && line[0] != '1')
		parse_params(details, line);
	details->maph = ft_strlen(line);
	parse_map(details, line);
	while (get_next_line(fd, &line))
	{
		parse_map(details, line);
		free(line);
	}
	free(line);
	details->maph--;
	place_player(details);
	return (details);
}
