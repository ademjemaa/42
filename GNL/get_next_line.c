/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:46:59 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/16 14:52:03 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_line(char **str, char **line)
{
	int i;

	i = 0;
	while ((*str)[i] && i < (int)ft_strlen(*str))
	{
		if ((*str)[i] == '\n')
		{
			if (((*line) = ft_substr(*str, 0, i, 0)) == NULL)
				return (-1);
			*str = ft_substr(*str, i + 1, ft_strlen(*str), 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int		free_all(char **str, char *buff, int crit)
{
	if (*str && (crit == -1 || crit == 0))
	{
		free(*str);
		*str = NULL;
	}
	if (buff != NULL)
		free(buff);
	if (crit == -1)
		return (-1);
	else if (crit)
		return (1);
	return (0);
}

int		setup(char **buff, char **str, char **line, int fd)
{
	int ret;

	if (!(*buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (!*str)
		if (!(*str = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	if (*str)
	{
		ret = check_line(str, line);
		if (ret == -1)
			return (-1);
		else if (ret)
			return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	int			ret;
	static char	*str;

	if ((ret = setup(&buff, &str, line, fd)) == -1)
		return (free_all(&str, buff, -1));
	if (ret)
		return (free_all(&str, buff, 1));
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((str = ft_strjoin(str, buff)) == NULL)
			return (-1);
		free(buff);
		buff = NULL;
		if ((ret = check_line(&str, line)) == -1)
			return (free_all(&str, buff, -1));
		if (ret)
			return (free_all(&str, buff, 1));
		if (!(buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (free_all(&str, buff, -1));
	}
	if (((*line) = ft_substr(str, 0, ft_strlen(str), 0)) == NULL || ret == -1)
		return (free_all(&str, buff, -1));
	return (free_all(&str, buff, 0));
}
