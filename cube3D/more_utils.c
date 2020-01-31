/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 23:12:29 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/30 16:37:36 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	make_bmp_map(void *img_ptr, t_cparam *det)
{
	unsigned char	header[54];
	int				fd;
	int				var;
	short			sho;

	fd = 54 + det->render_v * det->render_h * 4;
	ft_bzero(header, 54);
	ft_memcpy(header, "BM", 2);
	ft_memcpy(&header[2], &fd, 4);
	var = 54;
	ft_memcpy(&header[10], &var, 4);
	var = 40;
	ft_memcpy(&header[14], &var, 4);
	ft_memcpy(&header[18], &(det->render_h), 4);
	ft_memcpy(&header[22], &(det->render_v), 4);
	sho = 1;
	ft_memcpy(&header[26], &sho, 2);
	sho = 32;
	ft_memcpy(&header[28], &sho, 2);
	ft_memcpy(&header[34], &fd, 4);
	fd = open("file.bmp", O_WRONLY | O_CREAT, 508);
	ft_putstr_fd(header, fd, 54);
	header_img(img_ptr, fd, det);
	close(fd);
}

void	sprite_calcul(t_calc *cal, t_cparam *det, int type, t_cam *p)
{
	if (type == 0)
	{
		cal->tex = (int)(256 * (cal->i - (-(cal->spw) / 2 +
		cal->spscx)) * det->w / cal->spw) / 256;
		if (cal->trany > 0 && cal->i > 0 && cal->i < det->render_h &&
			cal->trany < p->zbuffer[cal->i])
			cal->cond = 1;
		else
			cal->cond = 0;
	}
	else if (type == 1)
	{
		cal->tey = (((int)(cal->y * 256 - det->render_v * 128 +
		cal->sph * 128) * det->h) / cal->sph) / 256;
	}
}

int		find_dstart(t_calc *cal, t_cparam *det)
{
	if (cal->dstarty < 0)
		cal->dstarty = 0;
	if (cal->dendy >= det->render_v)
		cal->dendy = det->render_v - 1;
	cal->dstartx = -(cal->spw) / 2 + cal->spscx;
	if (cal->dstartx < 0)
		cal->dstartx = 0;
	cal->dendx = cal->spw / 2 + cal->spscx;
	if (cal->dendx >= det->render_h)
		cal->dendx = det->render_h - 1;
	cal->color = 0x000000;
	return (cal->dstartx);
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*str;
	unsigned char		*ptr;

	i = 0;
	str = (unsigned char *)s1;
	ptr = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str[i] == ptr[i] && i < n - 1)
		i++;
	return ((int)str[i] - (int)ptr[i]);
}
