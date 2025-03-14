#include "push_swap.h"

void ft_swap(t_list **stack)
{
    if (!stack || !(*stack)->stack_a)
        return;
    if (check_doubles((*stack)->stack_a) == -1)
    {
        err_msg(stack, 1);
    }
    if (is_sorted((*stack)->stack_a))
    {
        free_mem(stack);
        exit(1);
    }
    if ((*stack)->size == 2)
        sort_two_nums(&(*stack)->stack_a);
    else if ((*stack)->size == 3)
        sort_three_nums(&(*stack)->stack_a);
    else if ((*stack)->size == 4)
        sort_four_nums(&(*stack)->stack_a, &(*stack)->stack_b);
    else if ((*stack)->size == 5)
        sort_five_nums(&(*stack)->stack_a, &(*stack)->stack_b);
    else
        large_sort(stack);
}
