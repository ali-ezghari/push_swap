/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezghari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:11:28 by aezghari          #+#    #+#             */
/*   Updated: 2025/03/18 03:12:17 by aezghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	tmp = 0;
	if (!stack || !stack->next)
		return ;
	tmp = stack->next->num;
	stack->next->num = stack->num;
	stack->num = tmp;
}

void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
}

void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
}
