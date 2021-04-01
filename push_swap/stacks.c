/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:29:16 by adjemaa           #+#    #+#             */
/*   Updated: 2021/03/22 17:16:05 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->stack = NULL;
	stack->move = NULL;
	(stack)->len = 0;
	return (stack);
}

t_node		*lstnew(char *content)
{
	t_node	*elem;
	int		val;
	int		i;

	i = -1;
	if (content[i + 1] == '-' || content[i + 1] == '+')
		i++;
	while (content[++i])
		if (!ft_isdigit(content[i]))
			return (NULL);
	val = ft_atoi(content);
	elem = malloc(sizeof(t_node));
	if (elem == NULL)
		return (NULL);
	elem->value = val;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

int			lstadd_front(t_node *new, t_stack *stack_a)
{
	if (new == NULL)
		return (0);
	stack_a->len++;
	if (stack_a->stack != 0)
	{
		new->next = stack_a->stack;
		new->prev = NULL;
		stack_a->stack->prev = new;
		stack_a->stack = new;
	}
	else
		stack_a->stack = new;
	return (1);
}

int			check_dupli(t_stack *stack_a)
{
	t_node *tmp;
	t_node *tp;

	tmp = stack_a->stack;
	while (tmp)
	{
		tp = tmp->next;
		while (tp)
		{
			if (tp->value == tmp->value)
				return (1);
			tp = tp->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

t_stack		*check_values(int argc, char **argv)
{
	int		i;
	int		j;
	t_stack	*stack_a;
	char	**str;

	i = 1;
	stack_a = init_stack();
	while (argc > i)
	{
		j = -1;
		str = ft_split(argv[i], ' ');
		while (str[++j])
			if (!lstadd_front(lstnew(str[j]), stack_a))
				return (free_list(stack_a));
		j = 0;
		while (str[j])
			free(str[j++]);
		free(str);
		i++;
	}
	if (check_dupli(stack_a))
		return (free_list(stack_a));
	return (stack_a);
}
