/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:28:11 by adjemaa           #+#    #+#             */
/*   Updated: 2021/03/12 16:29:12 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorting(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = stack_a->stack;
	if (stack_b->len == 0)
		while (i < stack_a->len - 1)
		{
			if (tmp->value < tmp->next->value)
				return (0);
			tmp = tmp->next;
			i++;
		}
	if (i == stack_a->len - 1 && i != 0)
		return (1);
	return (0);
}
