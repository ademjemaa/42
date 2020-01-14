/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 00:33:34 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/12 22:08:36 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	map_error(void)
{
	ft_putstr("Error\nBad map configuration\n");
	exit(0);
}

int		souris(void *param)
{
	t_mlx		*par;
	t_cam		*p;
	t_cparam	*det;
	void		**tab;
	t_text		**txt;

	tab = (void **)param;
	det = tab[1];
	par = tab[0];
	p = tab[2];
	txt = tab[3];
	mlx_destroy_window(par->mlx_ptr, par->mlx_win);
	free(txt);
	free(det->map);
	exit(0);
}

void	start_cube(t_mlx *par, t_cparam *det)
{
	void	*tab[4];
	t_cam	p;
	t_text	**txt;

	p = init_player(det);
	tab[0] = par;
	tab[2] = &p;
	tab[1] = det;
	txt = get_texture(det, par);
	tab[3] = txt;
	draw(par, det, &p, txt);
	mlx_hook(par->mlx_win, 17, 0, souris, (void*)tab);
	mlx_hook(par->mlx_win, 2, 0, move, (void *)tab);
	mlx_loop(par->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_cparam	details;
	t_mlx		par;

	(void)argc;
	details = init_params(argv);
	if ((par.mlx_ptr = mlx_init()) == NULL)
	{
		ft_putstr("Error\n could not initiate mlx\n");
		return (0);
	}
	if ((par.mlx_win = init_window(par.mlx_ptr, &details)) == NULL)
		return (0);
	start_cube(&par, &details);
	return (0);
}
