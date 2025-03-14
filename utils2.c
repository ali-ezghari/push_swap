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

int *create_sort_array(t_list *stack)
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

int	ft_lstsize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}