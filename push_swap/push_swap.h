/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:23:18 by adjemaa           #+#    #+#             */
/*   Updated: 2021/04/01 16:39:22 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>

typedef	struct	s_move
{
	char	*mov;
	int		len;
	struct s_move	*next;
}				t_move;


typedef struct	s_node
{
	int				value;
	int				len;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct	s_stack
{
	t_node	*stack;
	t_move	*move;
	int		turn;
	int		len;
}				t_stack;

void			exec_instructions(t_stack *stack_a, t_stack *stack_b,
				char *line);
t_stack			*check_values(int argc, char **argv);
int				error_msg(void);
int				ft_strcmp(char *s1, char *s2);
int				check_sorting(t_stack *stack_a, t_stack *stack_b);
t_stack			*free_list(t_stack *stack_a);
t_stack			*init_stack(void);
int				lstadd_front(t_node *new, t_stack *stack_a);
t_node			*lstlast(t_node *lst);
void			exec_r(t_stack *stack_a, t_stack *stack_b, int con);
void			exec_rrr(t_stack *stack_a, t_stack *stack_b, int con);
void			execute(t_stack *stack_a, t_stack *stack_b, char *line);
void			show_stacks(t_stack *stack_a, t_stack *stack_b);
void			exec_five_instr(t_stack *stack_a, t_stack *stack_b);
void			write_exec(t_stack *stack_a, t_stack *stack_b, char *str);
void			exec_three_instr(t_stack *stack_a, t_stack *stack_b);
void			exec_two_instr(t_stack *stack_a, t_stack *stack_b);
void			exec_half_algo(t_stack *stack_a, t_stack *stack_b);
int				min_val(t_stack *stack_a, int pos);
int				max_val(t_stack *stack_a);
int				find_med(t_stack *stack_a, int rank, int cur);
char			*optimal_path(t_stack *stack_a);
void			opti_rot(t_stack *stack_a, t_stack *stack_b, int med, int cond);
void			opti_rot_b(t_stack *stack_a, t_stack *stack_b);
void			exec_quarter_algo(t_stack *stack_a, t_stack *stack_b, int len);
void			push_rotate_stack(t_stack *stack_a, t_stack *stack_b);
void			double_rot(t_stack *stack_a, t_stack *stack_b, char *str);
void			align_stack(t_stack *stack_a, t_stack *stack_b);
int				optimal_path_b(t_stack *stack_b);
int				rot_b_stack(t_stack *stack_b);
void			fix_b_three(t_stack *stack_a, t_stack *stack_b);
void	add_back(t_stack *stack_a, char *str);
int			test_medians(t_stack *stack_a, t_stack *stack_b, int tech);
t_stack		*copy_stacks(t_stack *stack);

#endif
