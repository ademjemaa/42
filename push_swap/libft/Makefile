# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 21:13:47 by adjemaa           #+#    #+#              #
#    Updated: 2021/03/11 14:34:39 by adjemaa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = ft_memset.c\
       ft_bzero.c\
       ft_memcpy.c\
       ft_memccpy.c\
       ft_memmove.c\
       ft_memchr.c\
       ft_memcmp.c\
       ft_strlen.c\
       ft_isalpha.c\
       ft_isdigit.c\
       ft_isalnum.c\
       ft_isascii.c\
       ft_isprint.c\
       ft_toupper.c\
       ft_tolower.c\
       ft_strchr.c\
       ft_strrchr.c\
       ft_strncmp.c\
       ft_strlcpy.c\
       ft_strlcat.c\
       ft_strnstr.c\
       ft_atoi.c\
       ft_calloc.c\
       ft_substr.c\
       ft_strtrim.c\
       ft_split.c\
       ft_itoa.c\
       ft_strmapi.c\
       ft_putchar_fd.c\
       ft_putstr_fd.c\
       ft_putendl_fd.c\
       ft_putnbr_fd.c\
       get_next_line.c\
       get_next_line_utils.c\

BS = ft_lstnew_bonus.c\
     ft_lstadd_front_bonus.c\
     ft_lstsize_bonus.c\
     ft_lstlast_bonus.c\
     ft_lstadd_back_bonus.c\
     ft_lstdelone_bonus.c\
     ft_lstclear_bonus.c\
     ft_lstiter_bonus.c\
     ft_lstmap_bonus.c\

HEADERS = libft.h

OBJECT = $(SRCS:.c=.o)

OBJECT_B = $(BS:.c=.o)

$(NAME): ${OBJECT}
	@$(CC) $(FLAGS) -c $(SRCS)
	@ar rc $(NAME)  $(OBJECT)
	@ranlib $(NAME)

bonus: ${OBJECT_B} ${OBJECT}
	@$(CC) $(FLAGS) -c $(BS) $(SRCS)
	@ar rc $(NAME)  $(OBJECT_B) $(OBJECT) 
	@ranlib $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJECT) $(OBJECT_B)

fclean : clean 
	@rm -rf $(NAME)

re : fclean all

.PHONY: re clean fclean all bonus
