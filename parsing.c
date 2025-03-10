#include "push_swap.h"

static void is_num(const char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        err_msg();
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9' && i <= 11)
            i++;
        else
            err_msg();
    }
}

void parsing(const char *av[])
{
    int i;

    i = 0;
    while (av[i] != NULL)
    {
        is_num(av[i]);
        ft_atol(av[i]);
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