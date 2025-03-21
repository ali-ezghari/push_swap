/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezghari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:13:29 by aezghari          #+#    #+#             */
/*   Updated: 2025/03/18 03:16:02 by aezghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	res;

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
	return (res * sign);
}

t_stack	*create_node(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->num = data;
	node->next = NULL;
	return (node);
}

void	free_mem(t_list **stack, char **arr)
{
	t_stack	*tmp;

	if (arr)
		free_arr(arr);
	if (!stack || !*stack)
		return ;
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

void	err_msg(t_list **stack, char **arr)
{
	free_mem(stack, arr);
	write(2, "Error\n", 6);
	exit(255);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
