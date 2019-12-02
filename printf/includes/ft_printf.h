/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:46:15 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/29 16:39:02 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_det
{
	char		conv;
	int			len;
	int			minus;
	int			zero;
	int			precision;
	int			point;
	int			justify;
}				t_det;

typedef struct	s_f
{
	char	*f;
	int		s;
}				t_f;

int				ft_strlen(char *str);
int				ft_printf(const char *format, ...);
int				ft_caller(char *str, va_list *ap);
char			*ft_substr(char	*s, unsigned int start, size_t len, int con);
size_t			ft_choose(char *s, unsigned int start, size_t len);
char			*create_s(t_det *check, va_list *ap, t_f **fn);
char			*take_point(char *format, t_det *check, va_list *ap);
char			*take_width(char *format, t_det *check, va_list *ap);
char			*take_zero(char *format, t_det *check, va_list *ap);
char			*take_minus(char *format, t_det *check, va_list *ap);
char			*ft_strdup(const char *s1);
int				ft_check_sign(char *str);
int				ft_atoi(char *str, int *dec);
int				ft_strtotal(char const *str);
char			*take_minus(char *format, t_det *check, va_list *ap);
char			*create_c(t_det *check, va_list *ap, t_f **fn);
char			*ft_strjoin(char *s1, char *s2, int crit);
char			*ft_strjoinfree(char *s1, char *s2);
int				ft_purstr(char *str, int j, t_f *fn);
char			*ft_itoa(int n);
char			*create_d(t_det *check, va_list *ap, t_f **fn);
char			*create_p(t_det *check, va_list *ap, t_f **fn);
char			*create_u(t_det *check, va_list *ap, t_f **fn);
char			*ft_uitoa(unsigned int n);
char			*ft_cat_one(char *tab, char c);
char			*create_x(t_det *check, va_list *ap, t_f **fn);
char			*ft_int_point(char *final, t_det *check);
char			*ft_int_zero(char *final, t_det *check);
char			*ft_int_jus(char *final, t_det *check);
char			*create_pr(t_det *check, t_f **fn);
char			*ft_strjoinfreeboth(char *s1, char *s2, int lens1, int lens2);
void			*ft_memcpy(void *dst, const void *src, size_t n);

#endif
