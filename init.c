#include "push_swap.h"

t_list *init_stack()
{
    t_list *stack;

    stack = malloc(sizeof(t_list));
    if (!stack)
        return (NULL);
    stack->stack_a = NULL;
    stack->stack_b = NULL;
    stack->size = 0;
    return (stack);
}

void fill_stack(char **arr, t_list **stack)
{
    t_stack *new_node;
    int num;
    int size;

    if (!stack || !*stack)
        err_msg(stack, 1);
    size = 0;
    while (arr[size])
        size++;
    while (--size >= 0)
    {
        num = (int)ft_atol(arr[size]);
        new_node = create_node(num);
        if (!new_node)
            err_msg(stack, 1);
        if ((*stack)->stack_a != NULL)
            (*stack)->stack_a->prev = new_node;
        new_node->next = (*stack)->stack_a;
        (*stack)->stack_a = new_node;
        (*stack)->size++;
    }
}