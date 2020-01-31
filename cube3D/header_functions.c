/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:39:44 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/22 22:54:46 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_putstr_fd(unsigned char *s, int fd, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n && str[i])
	{
		str[i] = 0;
		i++;
	}
}

void	header_img(void *img, int fd, t_cparam *det)
{
	int	i;
	int	j;

	i = det->render_v - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < det->render_h)
		{
			write(fd, img + 4 * det->render_h * i + j
			* 4, sizeof(int));
			j++;
		}
		i--;
	}
}
