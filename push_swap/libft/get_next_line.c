/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:33:15 by abarbour          #+#    #+#             */
/*   Updated: 2021/03/11 15:21:44 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		has_nl(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *stack)
{
	char	*line;
	int		i;

	if (!(stack))
		return (ft_strdup(""));
	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (stack[i] == '\n')
		line = ft_substrr(stack, 0, i, 0);
	else
		line = ft_strdup(stack);
	return (line);
}

char	*get_new_stack(char *stack)
{
	int		i;

	if (!(stack))
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (stack[i] == '\n')
	{
		if (stack[i + 1])
			return (ft_substrr(stack, i + 1, ft_strlen(stack) - (i + 1), 0));
		else
			return (NULL);
	}
	return (NULL);
}

int		ft_error_check(int fd, char **stack, char **line)
{
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || !line)
	{
		free(*stack);
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*stack;
	char		*aux;
	char		buf[BUFFER_SIZE + 1];
	int			aux1;

	if (ft_error_check(fd, &stack, line))
		return (-1);
	aux1 = 1;
	while (!has_nl(stack) && aux1 > 0)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		aux1 = read(fd, buf, BUFFER_SIZE);
		aux = stack;
		stack = ft_strjoin(stack, buf);
		ft_bzero(buf, BUFFER_SIZE + 1);
		free(aux);
	}
	*line = get_line(stack);
	aux = stack;
	stack = get_new_stack(stack);
	free(aux);
	if (aux1 <= 0)
		return (aux1);
	return (1);
}
