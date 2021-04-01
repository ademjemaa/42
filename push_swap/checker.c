/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:07:33 by adjemaa           #+#    #+#             */
/*   Updated: 2021/03/25 17:19:07 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			error_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
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
	ret = get_next_line(0, &line);
	while (ret > 0)
	{
		exec_instructions(stack_a, stack_b, line);
		free(line);
		ret = get_next_line(0, &line);
	}
	if (check_sorting(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(stack_a);
	free_list(stack_b);
}
