/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:47:12 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/13 14:35:39 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

char	*ft_substr(char *s, unsigned int start, size_t len, int crit);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strncat(char *dest, const char *src, size_t len);
size_t	ft_strlen(const char *src);
int		get_next_line(int fd, char **line);
size_t	ft_choose(char const *s, unsigned int start, size_t len);

#endif
