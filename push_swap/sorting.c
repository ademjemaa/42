/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:28:11 by adjemaa           #+#    #+#             */
/*   Updated: 2021/03/25 13:38:04 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] - s2[i] == 0)
		return (1);
	return (0);
}

int		max_val(t_stack *stack_a)
{
	t_node	*tmp;
	int		max;

	tmp = stack_a->stack;
	max = stack_a->stack->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int		judge(t_stack *stack_a, t_stack *stack_b, int i)
{
	if (stack_b)
	{
		if (stack_b->len == 0 && i == stack_a->len - 1 && i != 0)
			return (1);
	}
	else if (i == stack_a->len - 1 && i != 0)
		return (1);
	printf("zero\n");
	return (0);
}

int		check_sorting(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = stack_a->stack;
	while (i < stack_a->len - 1)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
		i++;
	}
	printf("judge\n");
	return (judge(stack_a, stack_b, i));
}
