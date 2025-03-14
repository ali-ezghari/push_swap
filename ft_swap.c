#include "push_swap.h"

static int get_end(int size)
{
    if (size <= 16)
    {
        return (3);
    }
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
void push_all_to_a(t_stack **stack_a, t_stack **stack_b, int size)
{
    int max_index;
    int stack_b_size; // Track the current size of stack_b

    stack_b_size = size;
    while (*stack_b != NULL)
    {
        max_index = ft_max(*stack_b); // Get the index of the maximum value in stack_b

        if (max_index < stack_b_size / 2)
        {
            // Rotate stack_b to bring the max value to the top
            while (max_index-- > 0)
                do_rb(stack_b);
        }
        else
        {
            // Reverse rotate stack_b to bring the max value to the top
            while (max_index++ < stack_b_size)
                do_rrb(stack_b);
        }

        // Push the max value from stack_b to stack_a
        do_pa(stack_a, stack_b);

        // Decrease the size counter
        stack_b_size--;
    }
}
static void sort_stack(t_list **stack, int *arr, int range)
{
    int start;
    int end;
    int size;
    int unsorted_count;
    t_stack **stack_a_ptr;
    t_stack **stack_b_ptr;

    stack_a_ptr = &((*stack)->stack_a);
    stack_b_ptr = &((*stack)->stack_b);
    end = range;
    size = (*stack)->size;
    unsorted_count = size; // Track how many elements still need to be processed

    while (unsorted_count > 0)
    {
        start = end - 2;
        // Check if indices are in bounds

        if ((*stack_a_ptr)->num <= arr[start])
        {
            do_pb(stack_a_ptr, stack_b_ptr);
            do_sb(stack_b_ptr);
            unsorted_count--;
        }
        else if ((*stack_a_ptr)->num <= arr[end])
        {
            do_pb(stack_a_ptr, stack_b_ptr);
            unsorted_count--;
        }
        else
        {
            do_ra(stack_a_ptr);
            if (--unsorted_count <= 0)
                break;
        }

        if (end < size - 1)
        {
            end++;
        }
    }

    // Update the stack pointers in the original structure
    (*stack)->stack_a = *stack_a_ptr;
    (*stack)->stack_b = *stack_b_ptr;

    // Now push everything back to stack_a
    push_all_to_a(stack_a_ptr, stack_b_ptr, size);
    // while (stack_a != NULL)
    // {
    //     printf("Prev: %d | Current: %d | Next: %d\n",
    //            stack_a->prev ? stack_a->prev->num : -1,
    //            stack_a->num,
    //            stack_a->next ? stack_a->next->num : -1);
    //     stack_a = stack_a->next;
    // }
    // exit(0);
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
