/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 01:28:08 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/12 23:11:37 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "get_next_line.h"

int			check_hit(t_cam *p, t_cparam *det, t_sprite **sp)
{
	int	hit;
	int side;

	hit = 0;
	while (hit == 0)
	{
		if (p->sdistx < p->sdisty)
		{
			p->sdistx += p->ddistx;
			p->mapx += p->stepx;
			side = 0;
		}
		else
		{
			p->sdisty += p->ddisty;
			p->mapy += p->stepy;
			side = 1;
		}
		if (det->map[p->mapx][p->mapy] > 0)
			hit = 1;
		if (det->map[p->mapx][p->mapy] == 2)
			add_sprite(p->mapx, p->mapy, p, sp);
	}
	return (side);
}

static int	ft_check_sign(char *str)
{
	int i;
	int sign;

	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	return (sign);
}

int			ft_atoi(char *str)
{
	int i;
	int sign;
	int total;

	total = 0;
	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == 32)
		i++;
	sign = ft_check_sign((char *)(str + i));
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10;
		total = (str[i] - '0') + total;
		i++;
	}
	return (total * sign);
}

void		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void		texture_cal(t_text *txt, t_cam *p, int side)
{
	p->wallx -= floor(p->wallx);
	p->texx = (int)(p->wallx * (double)txt->w);
	if (side == 0 || side == 3)
		p->texx = txt->w - p->texx - 1;
	p->texx = abs(p->texx);
}
