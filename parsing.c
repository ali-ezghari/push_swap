#include "push_swap.h"

static void is_num(const char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
    {
        write(2, "Error\n", 6);
        exit(1);
    }
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9' && i <= 11)
            i++;
        else
        {
            write(2, "Error\n", 6);
            exit(1);
        }
    }
}

void parsing(char **arr)
{
    int i;

    i = 0;
    while (arr[i] != NULL)
    {
        is_num(arr[i]);
        ft_atol(arr[i]);
        i++;
    }
}

int check_doubles(t_stack *stack)
{
    t_stack *tmp;

    if (!stack)
    {
        return (-1);
    }
    while (stack != NULL)
    {
        tmp = stack->next;
        while (tmp != NULL)
        {
            if (stack->num == tmp->num)
            {
                return (-1);
            }
            tmp = tmp->next;
        }
        stack = stack->next;
    }
    return (1);
}