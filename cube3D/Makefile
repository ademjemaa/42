# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/25 20:59:03 by adjemaa           #+#    #+#              #
#    Updated: 2020/01/30 18:07:42 by adjemaa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

MLXLIB = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

NAME = cube3D

SRCS =	cube_utils.c\
		drawing.c\
		get_next_line.c\
		get_next_line_utils.c\
		header_functions.c\
		initialize.c\
		main.c\
		more_utils.c\
		movement.c\
		parser.c\
		sprite.c\
		utils.c\
		errors.c\
		errors2.c\

HEADERS =	cube3d.h\
			get_next_line.h\

OBJECT = $(SRCS:.c=.o)

$(NAME): ${OBJECT}
	$(CC) $(FLAGS) $(MLXLIB) -o $(NAME) ${OBJECT}

all:	$(NAME)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY:	re clean fclean all
