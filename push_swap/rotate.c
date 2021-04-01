/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:08:06 by adjemaa           #+#    #+#             */
/*   Updated: 2021/03/25 17:19:20 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			min_val(t_stack *stack_a, int pos)
{
	int		min;
	int		smin;
	t_node	*tmp;

	tmp = stack_a->stack;
	min = stack_a->stack->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	if (!pos)
		return (min);
	tmp = stack_a->stack;
	smin = (min == stack_a->stack->value) ? tmp->next->value : tmp->value;
	while (tmp)
	{
		if (tmp->value != min && tmp->value < smin)
			smin = tmp->value;
		tmp = tmp->next;
	}
	return (smin);
}

void		show_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node *tmp;
	t_node *tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = stack_a->stack;
	tmp2 = stack_b->stack;
	printf("len a == %d, len b == %d\n", stack_a->len, stack_b->len);
	printf("%10s       %s\n", "stack_a", "stack_b");
	while (tmp || tmp2)
	{

		printf("%10s", "#");
		if (tmp)
		{
	//				printf("%p  #  %p  #  %p     ", tmp->prev, tmp, tmp->next);
			printf("%d", tmp->value);
		}
		else
			printf(" ");
		printf("||");
		if (tmp2)
		{
			printf("%d", tmp2->value);
	//		printf("     %p  #   %p  #   %p", tmp2->prev,tmp2, tmp2->next);
		}
		printf("\n");
		if (tmp)
			tmp = tmp->next;
		if (tmp2)
			tmp2 = tmp2->next;
	}
}

t_stack		*free_list(t_stack *stack_a)
{
	t_node	*tmp;
	int		i;

	i = 0;
	while (i < stack_a->len)
	{
		tmp = stack_a->stack;
		if (i < stack_a->len - 1)
			stack_a->stack = stack_a->stack->next;
		free(tmp);
		i++;
	}
	free(stack_a);
	return (NULL);
}

void		exec_r(t_stack *stack_a, t_stack *stack_b, int con)
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

void		exec_rrr(t_stack *stack_a, t_stack *stack_b, int con)
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
