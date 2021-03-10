#include "push_swap.h"

void    init_stack(t_stack **stack)
{
    *stack = malloc(sizeof(t_stack));
    (*stack)->len = 0;
}

t_node  *lstnew(char *content)
{
        t_node  *elem;
        int     val;
        int     i;

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
        return (elem);
}

int    lstadd_front(t_node **alst, t_node *new, t_stack *stack_a)
{
        if (new == NULL)
            return (0);
        stack_a->len++;
        if (*alst != 0)
        {
                new->next = *alst;
                new->prev = NULL;
                (*alst)->prev = new;
                *alst = new;
        }
        else
                *alst = new;
        return (1);
}

int     check_dupli(t_stack *stack_a)
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

t_stack  *check_values(int argc, char **argv)
{
    int     i;
    t_stack *stack_a;

    i = 1;
    init_stack(&stack_a);
    while (argc > i)
        if (!lstadd_front(&stack_a->stack, lstnew(argv[i++]), stack_a))
            return (free_list(stack_a));
    if (check_dupli(stack_a))
        return (free_list(stack_a));
    return (stack_a);
}