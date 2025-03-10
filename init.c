#include "push_swap.h"

t_list *init_stack()
{
    t_list *stack;

    stack = malloc(sizeof(t_list));
    if (!stack)
        err_msg();
    stack->stack_a = NULL;
    stack->stack_b = NULL;
    stack->size = 0;
    return (stack);
}

void fill_stack(const char *argv[], t_list **stack)
{
    t_stack *new_node;
    int num;
    int i;

    if (!stack || !*stack)
        err_msg();
    i = 0;
    while (argv[i] != NULL)
    {
        num = (int)ft_atol(argv[i]);
        new_node = create_node(num);
        if (!new_node)
            err_msg();
        if ((*stack)->stack_a != NULL)
            new_node->next = (*stack)->stack_a;
        new_node->next = (*stack)->stack_a;
        (*stack)->stack_a = new_node;
        (*stack)->size++;
        i++;
    }
}