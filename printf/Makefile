# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 16:25:25 by adjemaa           #+#    #+#              #
#    Updated: 2019/11/29 16:36:08 by adjemaa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS_DIR = srcs/

INCS_DIR = includes/

SRCS_LIST = con_uint.c\
            con_uint_utils.c\
            conv_add.c\
            conv_char.c\
            conv_hexa.c\
            conv_int.c\
            conv_per.c\
            conv_string.c\
            first.c\
            ft_printf.c\
            ft_printf_ibez.c\
			ft_printf_tools.c\
			printf_flags.c\

SRCS =  $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJECT = $(patsubst %.c, %.o, $(SRCS))

AR = ar rc

LIB = ranlib

HEADERS = $(INCS_DIR)ft_printf.h

all : $(NAME)

.c.o :
	${CC} ${FLAGS} -c -I $(INCS_DIR) $< -o ${<:.c=.o}

$(NAME): $(OBJECT) $(INCS_DIR)
	 $(AR) $(NAME) $(OBJECT)
	$(LIB) $(NAME)

clean:
	@rm -rf $(OBJECT)

fclean: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: re clean fclean
