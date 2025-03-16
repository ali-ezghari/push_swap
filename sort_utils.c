/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezghari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 04:31:37 by aezghari          #+#    #+#             */
/*   Updated: 2025/03/16 07:31:15 by aezghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bubble_sort(int arr[], int size)
{
	int (i), (tmp), (j);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	is_sorted(t_stack *stack_a)
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
