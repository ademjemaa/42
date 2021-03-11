#ifndef PUSH_SWAP
#define PUSH_SWAP

#include "./libft/libft.h"
#include <stdio.h>
typedef struct  s_node 
{
    int value;
    int len;
    struct s_node *next;
    struct s_node *prev;  
}               t_node;

typedef struct  s_stack
{
    t_node *stack;
    int len;
}               t_stack;

void    exec_instructions(t_stack *stack_a, t_stack *stack_b, char *line);
t_stack  *check_values(int argc, char **argv);
int     error_msg(void);
int     check_sorting(t_stack *stack_a, t_stack *stack_b);
t_stack    *free_list(t_stack *stack_a);
t_stack    *init_stack(void);
int    lstadd_front(t_node *new, t_stack *stack_a);
t_node	*lstlast(t_node *lst);
void    exec_r(t_stack *stack_a, t_stack *stack_b, int con);
void exec_rrr(t_stack *stack_a, t_stack *stack_b);

#endif
