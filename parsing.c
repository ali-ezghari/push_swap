/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezghari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:10:21 by aezghari          #+#    #+#             */
/*   Updated: 2025/03/15 21:11:07 by aezghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_num(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (-1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9' && i <= 11)
			i++;
		else
			return (-1);
	}
	return (0);
}

int	parsing(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (is_num(arr[i]) == -1)
			return (-1);
		if (ft_atol(arr[i]) > INT_MAX || ft_atol(arr[i]) < INT_MIN)
			return (-1);
		i++;
	}
	return (0);
}

int	check_doubles(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (-1);
	while (stack != NULL)
	{
		tmp = stack->next;
		while (tmp != NULL)
		{
			if (stack->num == tmp->num)
				return (-1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}
