#include "push_swap.h"

static int get_end(int size)
{
    if (size <= 16)
    {
        return (3);
    }
    // else if (size <= 64)
    // {
    //     return (6);
    // }
    // else if (size <= 256)
    // {
    //     return (12);
    // }
    // else
    // {
    //     return (24);
    // }
    return (0);
}

static int *FromStackToArray(t_list *stack)
{
    int *arr;
    int i;
    t_stack *tmp;

    arr = (int *)malloc(sizeof(int) * stack->size);
    if (!arr)
        return (0);
    i = 0;
    tmp = stack->stack_a;
    while (tmp)
    {
        arr[i] = tmp->num;
        tmp = tmp->next;
        i++;
    }
    return (insertion_sort(arr, stack->size));
}
// void push_all_to_a(t_stack **stack_a, t_stack **stack_b, int size)
// {
//     int max;

//     while (*stack_b != NULL)
//     {
//         max = ft_max(*stack_b);
//         if (max < size / 2)
//         {
//             while (max-- > 0)
//                 do_rb(stack_b);
//         }
//         else
//         {
//             while (max++ < size - 1)
//                 do_rrb(stack_b);
//         }
//         do_pa(stack_a, stack_b);
//     }
// }
static void sort_stack(t_list **stack, int *arr, int range)
{
    int start;
    int end;
    int size;
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = (*stack)->stack_a;
    stack_b = (*stack)->stack_b;
    end = range;
    size = (*stack)->size;
    while (stack_a != NULL)
    {
        start = end - 2;
        if (stack_a->num <= arr[start])
        {
            do_pb(&stack_a, &stack_b);
            do_sb(&stack_b);
        }
        else if (stack_a->num <= arr[end])
        {
            do_pb(&stack_a, &stack_b);
        }
        else
        {
            do_ra(&stack_a);
        }
        if (end < size - 1)
        {
            end++;
        }
    }
    // printf("size = > %d\n", size);
    // exit(1);
    // push_all_to_a(&stack_a, &stack_b, size);
    // while (stack_b != NULL)
    // {
    //     printf("Prev: %d | Current: %d | Next: %d\n",
    //            stack_b->prev ? stack_b->prev->num : -1,
    //            stack_b->num,
    //            stack_b->next ? stack_b->next->num : -1);

    //     stack_b = stack_b->next;
    // }

    exit(0);
}
static void large_sort(t_list **stack)
{
    int range;
    int *arr;

    arr = FromStackToArray(*stack);
    if (!arr)
        return;
    range = get_end((*stack)->size);
    sort_stack(stack, arr, range);
}

void ft_swap(t_list **stack)
{
    if (!stack || !(*stack)->stack_a)
        return;
    if (check_doubles((*stack)->stack_a) == -1)
    {
        free_mem(stack);
        err_msg();
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
