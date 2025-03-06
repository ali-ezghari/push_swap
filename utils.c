#include "push_swap.h"

long ft_atoll(char *str)
{
    int i;
    int sign;
    long res;

    res = 0;
    sign = 1;
    i = 0;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
        err_msg();
    return (res * sign);
}

void err_msg(void)
{
    write(2, "Error\n", 6);
    exit(1);
}
