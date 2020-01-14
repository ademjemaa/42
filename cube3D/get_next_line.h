/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:47:12 by adjemaa           #+#    #+#             */
/*   Updated: 2020/01/11 14:31:36 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

char	*ft_substr(char *s, unsigned int start, size_t len, int crit);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
void	*ft_memcpy(void *dest, void *src, size_t n);
char	*ft_strncat(char *dest, char *src, size_t len);
int		ft_strlen(char *src);
int		get_next_line(int fd, char **line);
size_t	ft_choose(char *s, unsigned int start, size_t len);

#endif
