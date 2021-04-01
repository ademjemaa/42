NAME=push_swap
NAME_C=checker

SRCS= stacks.c\
	  sorting.c\
	  instructions.c\
	  rotate.c\

SRCS_C:= \
	checker.c\

SRCS_PS:= swap_push.c\
	choose_instr.c\
	quarter_split.c\
	align.c\
	rotate_stack.c\
	median.c\

OBJ:= $(SRCS:.c=.o)
OBJ_C:= $(SRCS_C:.c=.o)
OBJ_PS:= $(SRCS_PS:.c=.o)

INCLS:= .

LIBFT:= ./libft/libft.a

VPATH:= \

FLAGS:=  -Wall -Wextra -Werror

all : $(NAME_C) $(NAME)

all : $(NAME_C) 

%.o : %.c
	gcc -c $< -I $(INCLS) $(FLAGS)

$(NAME) : $(OBJ) $(OBJ_PS) $(LIBFT)
	gcc -o $(NAME) $(OBJ) $(OBJ_PS) $(LIBFT) $(FLAGS)

$(NAME_C) : $(OBJ) $(OBJ_C) $(LIBFT)
	gcc -o $(NAME_C) $(OBJ) $(OBJ_C) $(LIBFT) $(FLAGS)

$(LIBFT) :
	make -C ./libft/

clean :
	find . -type f -name "*~" -delete
	find . -type f -name "*.gch" -delete
	find . -type f -name "\#*.c\#" -delete
	find . -type f -name "*.o" -delete
	make fclean -C ./libft/

fclean : clean
	rm -f $(NAME) $(NAME_C)
	make fclean -C ./libft/

re : fclean all
