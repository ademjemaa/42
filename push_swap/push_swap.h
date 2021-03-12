/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:23:18 by adjemaa           #+#    #+#             */
/*   Updated: 2021/03/12 16:35:27 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>

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
	int		len;
}				t_stack;

void			exec_instructions(t_stack *stack_a, t_stack *stack_b,
				char *line);
t_stack			*check_values(int argc, char **argv);
int				error_msg(void);
int				check_sorting(t_stack *stack_a, t_stack *stack_b);
t_stack			*free_list(t_stack *stack_a);
t_stack			*init_stack(void);
int				lstadd_front(t_node *new, t_stack *stack_a);
t_node			*lstlast(t_node *lst);
void			exec_r(t_stack *stack_a, t_stack *stack_b, int con);
void			exec_rrr(t_stack *stack_a, t_stack *stack_b, int con);

#endif
