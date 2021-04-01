/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:07:57 by adjemaa           #+#    #+#             */
/*   Updated: 2021/03/25 13:37:57 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lstlast(t_node *tmp)
{
	t_node *lst;

	lst = tmp;
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	exec_sp(t_stack *stack_a, t_stack *stack_b, int con)
{
	t_node *tmp;

	if (con == 1)
		exec_sp(stack_b, stack_a, 0);
	if (stack_a->len < 2)
		return ;
	tmp = lstlast(stack_a->stack)->prev;
	if (stack_a->len > 2)
	{
		lstlast(stack_a->stack)->prev = tmp->prev;
		tmp->prev->next = lstlast(stack_a->stack);
		tmp->prev = tmp->prev->next;
		tmp->prev->next = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->prev = tmp->next;
		lstlast(stack_a->stack)->next = tmp;
		tmp->prev->prev = NULL;
		tmp->next = NULL;
		stack_a->stack = tmp->prev;
	}
}

void	exec_pp(t_stack *stack_a, t_stack *stack_b)
{
	t_node *tmp;

	if (stack_a->len != 0)
	{
		tmp = lstlast(stack_a->stack)->prev;
		if (stack_b->len == 0)
		{
			stack_b->stack = lstlast(stack_a->stack);
			stack_b->stack->prev->next = NULL;
			stack_b->stack->prev = NULL;
		}
		else
		{
			lstlast(stack_a->stack)->prev = lstlast(stack_b->stack);
			lstlast(stack_b->stack)->next = lstlast(stack_a->stack);
		}
		stack_b->len++;
		stack_a->len--;
		if (stack_a->len == 0)
			stack_a->stack = NULL;
		if (tmp != NULL)
			tmp->next = NULL;
	}
}

void	execute(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (ft_strncmp(line, "SA", 3) == 0)
		exec_sp(stack_a, stack_b, 0);
	if (ft_strncmp(line, "SB", 3) == 0)
		exec_sp(stack_b, stack_a, 0);
	if (ft_strncmp(line, "SS", 3) == 0)
		exec_sp(stack_a, stack_b, 1);
	if (ft_strncmp(line, "PA", 3) == 0)
		exec_pp(stack_b, stack_a);
	if (ft_strncmp(line, "PB", 3) == 0)
		exec_pp(stack_a, stack_b);
	if (ft_strncmp(line, "RA", 3) == 0)
		exec_r(stack_a, stack_b, 0);
	if (ft_strncmp(line, "RB", 3) == 0)
		exec_r(stack_b, stack_a, 0);
	if (ft_strncmp(line, "RR", 3) == 0)
		exec_r(stack_a, stack_b, 1);
	if (ft_strncmp(line, "RRA", 4) == 0)
		exec_rrr(stack_a, stack_b, 0);
	if (ft_strncmp(line, "RRB", 4) == 0)
		exec_rrr(stack_b, stack_a, 0);
	if (ft_strncmp(line, "RRR", 4) == 0)
		exec_rrr(stack_a, stack_b, 1);
}

void	exec_instructions(t_stack *stack_a, t_stack *stack_b, char *line)
{
	int i;

	i = -1;
	while (line[++i])
		line[i] = ft_toupper(line[i]);
	if (ft_strcmp(line, "SA") || ft_strcmp(line, "SB") || ft_strcmp(line, "SS")
		|| ft_strcmp(line, "PA") || ft_strcmp(line, "PB") || ft_strcmp(line,
		"RA") || ft_strcmp(line, "RB") || ft_strcmp(line, "RR") || ft_strcmp(
		line, "RRA") || ft_strcmp(line, "RRB") || ft_strcmp(line, "RRR"))
	{
		execute(stack_a, stack_b, line);
	}
	else
	{
		free_list(stack_a);
		free_list(stack_b);
		free(line);
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
}
