#include "push_swap.h"

void ft_push_swap(t_list **stack, char **arr)
{
    if (!stack || !(*stack)->stack_a)
        return;
    if (check_doubles((*stack)->stack_a) == -1)
    {
        free_arr(arr);
        err_msg(stack, 1);
    }
    if (is_sorted((*stack)->stack_a))
    {
        free_arr(arr);
        free_mem(stack);
        exit(EXIT_SUCCESS);
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
