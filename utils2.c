#include "push_swap.h"

int ft_min(t_stack *stack)
{
    int min;
    int index;
    int i;

    min = stack->num;
    i = 0;
    index = 0;
    while (stack)
    {
        if (stack->num < min)
        {
            min = stack->num;
            index = i;
        }
        stack = stack->next;
        i++;
    }
    return (index);
}

int ft_max(t_stack *stack)
{
    int max;
    int index;
    int i;

    max = stack->num;
    i = 0;
    index = 0;
    while (stack)
    {
        if (stack->num > max)
        {
            max = stack->num;
            index = i;
        }
        stack = stack->next;
        i++;
    }
    return (index);
}

int *insertion_sort(int arr[], int size)
{
    int i, tmp, j;

    if (size <= 1)
        return arr;

    for (i = 1; i < size; i++) // Start from index 1
    {
        tmp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > tmp)
        {
            arr[j + 1] = arr[j]; // Shift instead of swapping
            j--;
        }
        arr[j + 1] = tmp; // Insert tmp once in the correct place
    }
    return (arr);
}


int is_sorted(t_stack *stack_a)
{
    if (!stack_a || !stack_a->next)
        return (1);
    while (stack_a->next != NULL)
    {
        if (stack_a->num > stack_a->next->num)
        {
            return (0);
        }
        stack_a = stack_a->next;
    }
    return (1);
}