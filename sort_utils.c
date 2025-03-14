#include "push_swap.h"


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

int	get_end(int size)
{
	if (size <= 16)
		return (3);
	else if (size <= 100)
		return (16);
	else if (size <= 500)
		return (35);
	else
		return (50);
}