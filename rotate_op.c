#include "push_swap.h"

void rotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *last;

    if (!stack || !*stack || !(*stack)->next)
    {
        return;
    }
    tmp = (*stack);
    (*stack) = (*stack)->next;
    last = *stack;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = tmp;
    tmp->next = NULL;
}

void do_ra(t_stack **stack_a)
{
    rotate(stack_a);
    ft_putstr("ra\n");
}

void do_rb(t_stack **stack_b)
{
    rotate(stack_b);
    ft_putstr("rb\n");
}

void do_rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_putstr("rr\n");
}
