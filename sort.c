/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezghari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 04:57:25 by aezghari          #+#    #+#             */
/*   Updated: 2025/03/16 05:00:32 by aezghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_nums(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if ((*stack_a)->num > (*stack_a)->next->num)
		do_sa(stack_a);
}

void	sort_three_nums(t_stack **stack_a)
{
	int (first_num), (second_num), (third_num);
	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	first_num = (*stack_a)->num;
	second_num = (*stack_a)->next->num;
	third_num = (*stack_a)->next->next->num;
	if (first_num > second_num && second_num < third_num
		&& first_num < third_num)
		do_sa(stack_a);
	else if (first_num > second_num && second_num > third_num)
	{
		do_sa(stack_a);
		do_rra(stack_a);
	}
	else if (first_num > second_num && second_num < third_num)
		do_ra(stack_a);
	else if (first_num < second_num && second_num > third_num
		&& first_num < third_num)
	{
		do_sa(stack_a);
		do_ra(stack_a);
	}
	else if (first_num < second_num && second_num > third_num)
		do_rra(stack_a);
}

void	sort_four_nums(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = ft_min(*stack_a);
	if (min == 1)
		do_ra(stack_a);
	else if (min == 2)
	{
		do_rra(stack_a);
		do_rra(stack_a);
	}
	else if (min == 3)
		do_rra(stack_a);
	do_pb(stack_a, stack_b);
	sort_three_nums(stack_a);
	do_pa(stack_a, stack_b);
}

void	sort_five_nums(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = ft_min(*stack_a);
	if (min == 1)
		do_ra(stack_a);
	else if (min == 2)
	{
		do_ra(stack_a);
		do_ra(stack_a);
	}
	else if (min == 3)
	{
		do_rra(stack_a);
		do_rra(stack_a);
	}
	else if (min == 4)
		do_rra(stack_a);
	do_pb(stack_a, stack_b);
	sort_four_nums(stack_a, stack_b);
	do_pa(stack_a, stack_b);
}
