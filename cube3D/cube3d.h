/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 01:26:45 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/31 15:41:16 by adjemaa          ###   ########.fr       */
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
	int		cond;
	int		maph;
	int		mapv;
	int		**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	void	*image;
	void	*text;
	int		w;
	int		h;
	int		bpp;
	int		s_l;
	int		end;
}					t_cparam;

typedef struct		s_calc
{
	double	spx;
	double	spy;
	double	inv;
	double	tranx;
	double	trany;
	int		spscx;
	int		sph;
	int		dstarty;
	int		dendy;
	int		spw;
	int		dstartx;
	int		dendx;
	int		tex;
	int		tey;
	int		cond;
	int		color;
	int		i;
	int		y;
}					t_calc;

typedef struct		s_text
{
	void	*image;
	char	*text;
	int		w;
	int		h;
	int		bpp;
	int		size_line;
	int		end;
}					t_text;

typedef struct		s_sprite
{
	int		x;
	int		y;
	double	dist;
}					t_sprite;

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
	double	wallx;
	int		texx;
	double	sdistx;
	double	sdisty;
	double	ddistx;
	double	ddisty;
	double	walldist;
	double	*zbuffer;
	double	dirx;
	double	posx;
	double	posy;
	double	diry;
	int		color;
	int		bpp;
	int		size_l;
	int		endian;
	double	line;
	double	dstart;
	double	dend;
	int		mapx;
	int		mapy;

}					t_cam;

void				*init_window(char *mlx_ptr, t_cparam *det);
int					ft_atoi(char *str);
void				ft_putstr(char *str);
void				draw(t_mlx *par, t_cparam *det, t_cam *p, t_text **txt);
t_cparam			init_params(char **argv, int argc);
void				parse_map(t_cparam *det, char *line);
int					check_hit(t_cam *p, t_cparam *det, t_sprite **sp);
void				map_error(void *parms);
void				*ft_memcpy(void *dst, void *src, size_t n);
char				*ft_cat(char *dest, const char *src, int lens1, int lens2);
char				*conv_num(int num);
char				*ft_cat_one(char *tab, char c);
void				config_colors(t_cparam *d);
char				*ft_strjoinfr(char *s1, char *s2, int lens1, int lens2);
int					move(int ketycode, void *params);
t_cam				init_player(t_cparam *det);
void				move_lr(int keycode, t_cam *p, double var);
void				check_map(t_cparam *det, char *line, int cond);
void				place_player(t_cparam *det);
int					calcul_params(int i, t_cparam *det, t_cam *p,
					t_sprite **sp);
void				step_cal(t_cam *play);
void				draw_sky_floor(int x, t_cam *p, t_cparam *det);
t_text				**get_texture(t_cparam *det, t_mlx *p);
void				texture_cal(t_text *txt, t_cam *p, int side);
void				grab_textures(t_cparam *d, char *line);
void				add_sprite(int x, int y, t_cam *p, t_sprite **sp);
void				init_dda(t_cam *p, t_sprite **sp, t_cparam *det,
					t_mlx *par);
void				ver_sprite(t_cam *p, t_sprite *sp, t_cparam *det);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					find_dstart(t_calc *cal, t_cparam *det);
void				sprite_calcul(t_calc *cal, t_cparam *det, int type,
					t_cam *p);
int					ft_strcmp(char *s1, char *s2);
void				make_bmp_map(void *img_ptr, t_cparam *det);
void				ft_bzero(void *s, size_t n);
void				header_img(void *img, int fd, t_cparam *det);
void				ft_putstr_fd(unsigned char *s, int fd, int size);
void				text_error(t_text **tab, t_cparam *d);
int					ext_error(char *str, t_cparam *det, int type);
void				position_error(t_cparam *det);
void				map_parser(int fd, t_cparam *details, char *line);
int					find_conf(char *str, int *i, int type);
void				parse_settings(char *line, t_cparam *d, int type);
void				check_digits(char *line, int type);

#endif
