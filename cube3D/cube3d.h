/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 01:26:45 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/02 22:45:11 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct		s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		keycode;
}					t_mlx;

typedef struct		s_cparam
{
	int		render_h;
	int		render_v;
	double	playerx;
	double	playery;
	int		playerr;
	int		ceil;
	int		flor;
	int		maph;
	int		mapv;
	int		**map;
}					t_cparam;

typedef struct		s_text
{
	void	*image;
	char	*text;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		end;
}					t_text;

typedef	struct		s_cam
{
	void	*image;
	void	*i_p;
	double	planex;
	double	planey;
	double	camx;
	double	rdirx;
	double	rdiry;
	int		stepx;
	int		stepy;
	double	sdistx;
	double	sdisty;
	double	ddistx;
	double	ddisty;
	double	walldist;
	double	dirx;
	double	posx;
	double	posy;
	double	diry;
	int		color;
	int		bpp;
	int		size_l;
	int		endian;
	int		line;
	int		dstart;
	int		dend;
	int		mapx;
	int		mapy;

}					t_cam;

void				*init_window(char *mlx_ptr, t_cparam *det);
int					ft_atoi(const char *str);
void				ft_putstr(char *str);
void				draw(t_mlx *par, t_cparam *det, t_cam *p, t_text **txt);
t_cparam			*init_params(char **argv);
void				parse_map(t_cparam *det, char *line);
void				map_error(void);
void				*ft_memcpy(void *dst, void *src, size_t n);
char				*ft_cat(char *dest, const char *src, int lens1, int lens2);
char				*conv_num(int num);
char				*ft_cat_one(char *tab, char c);
void				config_colors(t_cparam *d);
char				*ft_strjoinfr(char *s1, char *s2, int lens1, int lens2);
int					move(int ketycode, void *params);
t_cam				*init_player(t_cparam *det);
void				move_lr(int keycode, t_cam *p, double var);
void				check_map(t_cparam *det, char *line, int cond);
void				place_player(t_cparam *det);
int					calcul_params(int i, t_cparam *det, t_cam *p);
int					check_hit(t_cam *p, t_cparam *det);
void				step_cal(t_cam *play);
void				draw_sky_floor(int x, t_cam *p, t_cparam *det);
t_text				**get_texture(int type, t_mlx *par);

#endif
