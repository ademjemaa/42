/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:07:33 by adjemaa           #+#    #+#             */
/*   Updated: 2021/03/12 16:28:06 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int			error_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

void		show_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	t_node *tmp;

	i = 0;
	tmp = stack_a->stack;
	printf("stack a : \n");
	printf("len == %d\n", stack_a->len);
	 while (i < stack_a->len)
	{
	    printf("val %d \n", tmp->value);
		printf("add == %p\n", tmp);
		printf("add next == %p\n", tmp->next);
		printf("add prev == %p\n", tmp->prev);
	    i++;
	    tmp = tmp->next;
	}
	   i = 0;
	tmp = stack_b->stack;
	printf("\nstack b : \n");
	printf("len == %d\n", stack_b->len);
	while (i < stack_b->len)
	{
	    printf("val %d \n", tmp->value);
		printf("add == %p\n", tmp);
		printf("add next == %p\n", tmp->next);
		printf("add prev == %p\n", tmp->prev);
	    i++;
	    tmp = tmp->next;
	}
}

int			main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		ret;
	char	*line;

	ret = 1;
	stack_b = init_stack();
	if (argc == 1)
		return (0);
	stack_a = check_values(argc, argv);
	if (stack_a == NULL)
		return (error_msg());
	show_stacks(stack_a, stack_b);
	while (!check_sorting(stack_a, stack_b) && ret > 0)
	{
		ret = get_next_line(0, &line);
		exec_instructions(stack_a, stack_b, line);
		show_stacks(stack_a, stack_b);
		free(line);
	}
	free_list(stack_a);
	free_list(stack_b);
}
