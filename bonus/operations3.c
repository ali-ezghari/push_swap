/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezghari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:12:34 by aezghari          #+#    #+#             */
/*   Updated: 2025/03/18 03:13:11 by aezghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
}

void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
}

void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
