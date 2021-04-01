/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quarter_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:29:48 by adjemaa           #+#    #+#             */
/*   Updated: 2021/04/01 16:48:49 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opti_rot_quad(t_stack *stack_a, t_stack *stack_b, int med, int med2)
{
	int		i;
	int		j;
	t_node	*tmp;

	i = 1;
	j = 0;
	tmp = stack_a->stack;
	while (tmp)
	{
		if (tmp->value <= med && tmp->value > med2 && i <= (stack_a->len / 2))
			j += -i;
		else if (tmp->value <= med && tmp->value >
			med2 && i > (stack_a->len / 2))
			j += (stack_a->len) - i;
		i++;
		tmp = tmp->next;
	}
	while (!(lstlast(stack_a->stack)->value >= med2 &&
		lstlast(stack_a->stack)->value <= med))
	{
		if (j <= 0)
		{
			if (lstlast(stack_a->stack)->prev->value <= med && lstlast(stack_a->stack)->prev->value > med2)
				write_exec(stack_a, stack_b, "SA");
			else
				double_rot(stack_a, stack_b, "RRA");
		}
		else
			double_rot(stack_a, stack_b, "RA");
	}
}

int		check_quad(int med, int med2, t_stack *stack_a)
{
	t_node	*tmp;

	tmp = stack_a->stack;

	while (tmp)
	{
		if (tmp->value <= med && tmp->value >= med2)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	
	return (0);
}

int		find_val(t_stack *stack_a, int rank, int cur)
{
	t_node	*tmp;
	int		val;

	tmp = stack_a->stack;
	val = min_val(stack_a, 0);
	while (tmp)
	{
		if (tmp->value > val)
			if (rank == 1 || tmp->value < cur)
				val = tmp->value;
		tmp = tmp->next;
	}
	return (val);
}

int		find_quad_med(t_stack *stack_a, int rank, int turn, int cur)
{
	int	med;
	int	val;

	med = stack_a->len - ((stack_a->len / turn) * stack_a->turn);
	val = find_val(stack_a, rank, cur);
	if (rank >= med)
		return (val);
	return (find_quad_med(stack_a, rank + 1, turn, val));
}

void	exec_quarter_algo(t_stack *stack_a, t_stack *stack_b, int len)
{
	int med;
	int med2;

	stack_a->turn = 0;
	med2 = min_val(stack_a, 0);
	while (++(stack_a->turn) < len + 1)
	{
		med = find_quad_med(stack_a, 1, len, min_val(stack_a, 0));
		while (check_quad(med, med2, stack_a) &&
			!check_sorting(stack_a, stack_b))
		{
			if (lstlast(stack_a->stack)->value <= med &&
				lstlast(stack_a->stack)->value >= med2)
				write_exec(stack_a, stack_b, "PB");
			if (check_quad(med, med2, stack_a))
				opti_rot_quad(stack_a, stack_b, med, med2);
		}
		med2 = med + 1;
		align_stack(stack_a, stack_b);
		push_rotate_stack(stack_a, stack_b);
	}
	while (!check_sorting(stack_a, stack_b))
		align_stack(stack_a, stack_b);
	show_stacks(stack_a, stack_b);
}
