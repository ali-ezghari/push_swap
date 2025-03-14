#include "push_swap.h"

long ft_atol(const char *str)
{
    int i;
    int sign;
    long int res;

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
    {
        write(2,"Error\n",5);
    }
    return (res * sign);
}

t_stack *create_node(int data)
{
    t_stack *node;

    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->prev = NULL;
    node->num = data;
    node->next = NULL;
    return (node);
}

void free_mem(t_list **stack)
{
    t_stack *tmp;

    if (!stack || !*stack)
        return;
    while ((*stack)->stack_a)
    {
        tmp = (*stack)->stack_a;
        (*stack)->stack_a = (*stack)->stack_a->next;
        free(tmp);
    }
    while ((*stack)->stack_b)
    {
        tmp = (*stack)->stack_b;
        (*stack)->stack_b = (*stack)->stack_b->next;
        free(tmp);
    }
    free(*stack);
    *stack = NULL;
}

void err_msg(t_list **stack, int status)
{
    int i;

    if (status == 1)
    {
        free_mem(stack);
    }
    i = write(2, "Error\n", 6);
    i++;
    exit(1);
}

void ft_putstr(char *str)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (str[i])
    {
        j = write(1, &str[i], 1);
        i++;
        j++;
    }
}