/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezghari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:06:35 by aezghari          #+#    #+#             */
/*   Updated: 2025/03/18 03:06:39 by aezghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*init_stack(void)
{
	t_list	*stack;

	stack = malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	return (stack);
}

void	fill_stack(char **arr, t_list **stack)
{
	t_stack	*new_node;
	int		num;
	int		size;

	if (!stack || !*stack)
		err_msg(stack, arr);
	size = 0;
	while (arr[size])
		size++;
	while (--size >= 0)
	{
		num = (int)ft_atol(arr[size]);
		new_node = create_node(num);
		if (!new_node)
			err_msg(stack, arr);
		if ((*stack)->stack_a != NULL)
			(*stack)->stack_a->prev = new_node;
		new_node->next = (*stack)->stack_a;
		(*stack)->stack_a = new_node;
	}
}
