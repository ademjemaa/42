/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:04:42 by adjemaa           #+#    #+#             */
/*   Updated: 2021/04/01 16:40:09 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*copy_values(t_node *stack)
{
	t_node	*tmp;
	t_node	*res;
	t_node	*mov;

	tmp = malloc(sizeof(t_node));
	tmp->prev = NULL;
	res = tmp;
	mov = stack;
	while (mov)
	{
		tmp->len = mov->len;
		tmp->value = mov->value;
		if (mov->next)
		{
			tmp->next = malloc(sizeof(t_node));
			tmp->next->prev = tmp;
		}
		tmp = tmp->next;
		mov = mov->next;
	}
	return (res);
}

t_stack		*copy_stacks(t_stack *stack)
{
	t_stack	*copy;

	copy = malloc(sizeof(t_stack));
	show_stacks(stack, stack);
	copy->turn = stack->turn;
	copy->len = stack->len;
	copy->stack = copy_values(stack->stack);
	copy->move = stack->move;
	return (copy);
}

int		rot_b_stack(t_stack *stack_b)
{
	if (lstlast(stack_b->stack)->value == min_val(stack_b, 0)
		|| lstlast(stack_b->stack)->value == max_val(stack_b))
		return (1);
	return (0);
}

void	double_rot(t_stack *stack_a, t_stack *stack_b, char *str)
{
	if (ft_strncmp(str, "RRA", 3) == 0)
	{
		if (optimal_path_b(stack_b))
			write_exec(stack_a, stack_b, "RRA");
		else
			write_exec(stack_a, stack_b, "RRR");
	}
	if (ft_strncmp(str, "RA", 2) == 0)
	{
		if (!optimal_path_b(stack_b))
			write_exec(stack_a, stack_b, "RA");
		else
			write_exec(stack_a, stack_b, "RR");
	}
}

void	opti_rot_b(t_stack *stack_a, t_stack *stack_b)
{
	int		cond;

	cond = optimal_path_b(stack_b);
	if (cond == 2)
		write_exec(stack_a, stack_b, "SB");
	while (lstlast(stack_b->stack)->value != min_val(stack_b, 0) &&
		lstlast(stack_b->stack)->value != max_val(stack_b))
	{
		if (cond)
			write_exec(stack_a, stack_b, "RRB");
		else
			write_exec(stack_a, stack_b, "RB");
	}
}
