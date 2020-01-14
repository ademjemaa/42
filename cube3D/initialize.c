/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 05:13:53 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/12 22:01:53 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "get_next_line.h"

char	*ft_cat_one(char *tab, char c)
{
	char	*tmp;
	int		i;

	i = ft_strlen(tab);
	if ((tmp = malloc(sizeof(*tmp) * i + 2)) == NULL)
		return (NULL);
	tmp[i + 1] = '\0';
	ft_memcpy(tmp + 1, tab, i);
	tmp[0] = c;
	free(tab);
	return (tmp);
}

void	re_malloc(t_cparam *det)
{
	int i;
	int j;
	int	**tmp;

	tmp = malloc(sizeof(int *) * (det->mapv + 1));
	i = 0;
	tmp[i] = malloc(sizeof(int) * (det->maph));
	while (i < det->mapv)
	{
		j = 0;
		while (j < det->maph)
		{
			tmp[i][j] = det->map[i][j];
			j++;
		}
		free(det->map[i]);
		i++;
		tmp[i] = malloc(sizeof(int *) * det->maph);
	}
	free(det->map);
	det->map = tmp;
}

void	*init_window(char *mlx_ptr, t_cparam *d)
{
	void	*mlx_window;

	mlx_window = mlx_new_window(mlx_ptr, d->render_h, d->render_v, "Cube 3D");
	if (mlx_window == NULL)
	{
		ft_putstr("Error\n unable to create window correctly\n");
		return (NULL);
	}
	return (mlx_window);
}

void	parse_map(t_cparam *det, char *line)
{
	int j;

	j = -1;
	re_malloc(det);
	if (det->mapv == 0)
		check_map(det, line, 1);
	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
		map_error();
	while (line[++j])
	{
		if (line[j] == '1' || line[j] == '0' || line[j] == '2')
			det->map[det->mapv][j] = line[j] - '0';
		else if (line[j] == 'N' || line[j] == 'S' || line[j] == 'W' ||
				line[j] == 'E')
			det->map[det->mapv][j] = line[j];
		else
			map_error();
	}
	free(line);
	det->mapv++;
}
