#include "push_swap.h"

void push(t_stack **from, t_stack **to)
{
    t_stack *tmp;

    if (!from || !*from)
    {
        return;
    }
    tmp = *from;
    (*from) = (*from)->next;
    tmp->next = *to;
    *to = tmp;
}

void do_pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
    ft_putstr("pa\n");
}

void do_pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    ft_putstr("pb\n");
}
