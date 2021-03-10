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

void    exec_sp(t_stack *stack_a, t_stack *stack_b, int con)
{
    t_node *tmp;

    if (con == 1)
        exec_sp(stack_b, stack_a, 0);
    if (stack_a->len < 2)
        return ;
    tmp = lstlast(stack_a->stack)->prev;
    lstlast(stack_a->stack)->prev = tmp->prev;
    tmp->prev->next = lstlast(stack_a->stack);
    tmp->prev = tmp->prev->next;
    tmp->prev->next = tmp;
}

void    exec_pp(t_stack *stack_a, t_stack *stack_b)
{
    t_node *tmp;

    tmp = lstlast(stack_a->stack)->prev;
    if (stack_a->len != 0)
    {
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
        tmp->next = NULL;
    }
}

void    execute(t_stack *stack_a, t_stack *stack_b, char *line)
{
    if (ft_strncmp(line, "SA", 2))
        exec_sp(stack_a, stack_b, 0);
    if (ft_strncmp(line, "SB", 2))
        exec_sp(stack_b, stack_b, 0);
    if (ft_strncmp(line, "SS", 2))
        exec_sp(stack_a, stack_b, 1);
    if (ft_strncmp(line, "PA", 2))
        exec_pp(stack_b, stack_a);
    if (ft_strncmp(line, "PB", 2))
        exec_pp(stack_a, stack_b);
    if (ft_strncmp(line, "RA", 2))
        exec_r(stack_a, stack_b, 0);
    if (ft_strncmp(line, "RB", 2))
        exec_r(stack_b, stack_a, 0);
    if (ft_strncmp(line, "RR", 2))
        exec_r(stack_a, stack_b, 0);
    if (ft_strncmp(line, "RRA", 3))
        exec_rrr(stack_a, stack_b);
    if (ft_strncmp(line, "RRB", 3))
        exec_rrr(stack_b, stack_a);
    if (ft_strncmp(line, "RRR", 3))
        exec_rrr(stack_a, stack_b);
}

void    exec_instructions(t_stack *stack_a, t_stack *stack_b, char *line)
{
    int i;

    i = -1;
    while (line[++i])
        line[i] = ft_toupper(line[i]);
    if (ft_strncmp(line, "SA", 2) || ft_strncmp(line, "SB", 2) || ft_strncmp(line, "SS", 2) ||
        ft_strncmp(line, "PA", 2) || ft_strncmp(line, "PB", 2) || ft_strncmp(line, "RA", 2) ||
        ft_strncmp(line, "RB", 2) || ft_strncmp(line, "RR", 2) || ft_strncmp(line, "RRA", 3) ||
        ft_strncmp(line, "RRB", 3) || ft_strncmp(line, "RRR", 3))
    {
        execute(stack_a, stack_b, line);
    }
    else
    {
        free_list(stack_a);
        free_list(stack_b);
        free(line);
    }
}