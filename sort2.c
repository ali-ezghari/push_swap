#include "push_swap.h"

static void push_for_start(t_stack **stack_a, t_stack **stack_b, int *start, int *end)
{
    int j;

    j = ft_lstsize(*stack_a) + ft_lstsize(*stack_b);
    do_pb(stack_a, stack_b);
    do_rb(stack_b);
    if (*start < *end)
        *start += 1;
    if (*end < j - 1)
        *end += 1;
}

static void push_for_end(t_stack **stack_a, t_stack **stack_b, int *start, int *end)
{
    int j;

    j = ft_lstsize(*stack_a) + ft_lstsize(*stack_b);
    do_pb(stack_a, stack_b);
    if (*start < *end)
        *start += 1;
    if (*end < j - 1)
        *end += 1;
}

static void move_big_to_top(t_stack **stack_b)
{
    int i;
    int size;
    int max;

    size = ft_lstsize(*stack_b);
    max = ft_max(*stack_b);
    if (max == 0)
        return;
    else
    {
        if (max <= size / 2)
        {
            i = -1;
            while (++i < max)
                do_rb(stack_b);
        }
        else
        {
            i = -1;
            while (++i < (size - max))
                do_rrb(stack_b);
        }
    }
}

static void push_to_a(t_stack **stack_a, t_stack **stack_b)
{
    move_big_to_top(stack_b);
    do_pa(stack_a, stack_b);
}

static void push_all_to_b(t_stack **stack_a, t_stack **stack_b, int *arr, int size)
{
    int start, end;

    start = 0;
    end = get_end(size);
    while (size != 0)
    {
        if ((*stack_a)->num <= arr[start])
        {
            push_for_start(stack_a, stack_b, &start, &end);
            size--;
        }
        else if ((*stack_a)->num <= arr[end])
        {
            push_for_end(stack_a, stack_b, &start, &end);
            size--;
        }
        else
        {
            do_ra(stack_a);
        }
    }
}

void large_sort(t_list **stack)
{
    int *arr;
    int size;

    size = (*stack)->size;
    arr = create_sort_array(*stack);
    if (!arr)
        return;
    push_all_to_b(&(*stack)->stack_a, &(*stack)->stack_b, arr, size);
    while (size > 0)
    {
        push_to_a(&(*stack)->stack_a, &(*stack)->stack_b);
        size--;
    }
    free(arr);
}