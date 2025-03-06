#include "push_swap.h"

static void is_num(char *str);

void parsing(char *av[])
{
    int i;
    long nu;

    i = 0;
    while (av[i] != NULL)
    {
        is_num(av[i]);
        nu = ft_atoll(av[i]);
        i++;
    }
}

static void is_num(char *str)
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
