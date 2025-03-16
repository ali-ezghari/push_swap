/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezghari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 04:41:44 by aezghari          #+#    #+#             */
/*   Updated: 2025/03/16 04:50:12 by aezghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_for_start(t_stack **a, t_stack **b, int *start, int *end)
{
	int	j;

	j = ft_lstsize(*a) + ft_lstsize(*b);
	do_pb(a, b);
	do_rb(b);
	if (*start < *end)
		(*start)++;
	if (*end < j - 1)
		(*end)++;
}

static void	push_for_end(t_stack **a, t_stack **b, int *start, int *end)
{
	int	j;

	j = ft_lstsize(*a) + ft_lstsize(*b);
	do_pb(a, b);
	if (*start < *end)
		(*start)++;
	if (*end < j - 1)
		(*end)++;
}

static void	move_big_to_top(t_stack **stack_b)
{
	int	i;
	int	size;
	int	max;

	size = ft_lstsize(*stack_b);
	max = ft_max(*stack_b);
	if (max == 0)
		return ;
	else
	{
		if (max <= size / 2)
		{
			i = -1;
			while (++i < max)
				do_rb(stack_b);
		}
		else
		{
			i = -1;
			while (++i < (size - max))
				do_rrb(stack_b);
		}
	}
}

static void	push_all_to_b(t_stack **a, t_stack **b, int *arr, int size)
{
	int	start;
	int	end;

	start = 0;
	end = get_end(size);
	while (size != 0)
	{
		if ((*a)->num <= arr[start])
		{
			push_for_start(a, b, &start, &end);
			size--;
		}
		else if ((*a)->num <= arr[end])
		{
			push_for_end(a, b, &start, &end);
			size--;
		}
		else
			do_ra(a);
	}
}

void	large_sort(t_list **stack)
{
	int	*arr;
	int	size;

	size = (*stack)->size;
	arr = create_sort_array(*stack);
	if (!arr)
		return ;
	push_all_to_b(&(*stack)->stack_a, &(*stack)->stack_b, arr, size);
	while (size > 0)
	{
		move_big_to_top(&(*stack)->stack_b);
		do_pa(&(*stack)->stack_a, &(*stack)->stack_b);
		size--;
	}
	free(arr);
}
