/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:08:06 by adjemaa           #+#    #+#             */
/*   Updated: 2021/03/12 16:27:57 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_r(t_stack *stack_a, t_stack *stack_b, int con)
{
	t_node *tmp;

	if (con == 1)
		exec_r(stack_b, stack_a, 0);
	if (stack_a->len < 2)
		return ;
	tmp = stack_a->stack;
	stack_a->stack->prev = lstlast(stack_a->stack);
	lstlast(stack_a->stack)->prev->next = NULL;
	stack_a->stack = stack_a->stack->prev;
	stack_a->stack->next = tmp;
	stack_a->stack->prev = NULL;
}

void	exec_rrr(t_stack *stack_a, t_stack *stack_b, int con)
{
	t_node *tmp;

	if (con == 1)
		exec_rrr(stack_b, stack_a, 0);
	if (stack_a->len < 2)
		return ;
	tmp = stack_a->stack->next;
	stack_a->stack->prev = lstlast(stack_a->stack);
	lstlast(stack_a->stack)->next = stack_a->stack;
	stack_a->stack->next = NULL;
	stack_a->stack = tmp;
	tmp->prev = NULL;
}
