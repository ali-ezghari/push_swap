/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezghari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:08:09 by aezghari          #+#    #+#             */
/*   Updated: 2025/03/18 03:10:57 by aezghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	verify_execute(const char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "pa\n") == 0)
		do_pa(a, b);
	else if (ft_strcmp(str, "pb\n") == 0)
		do_pb(a, b);
	else if (ft_strcmp(str, "sa\n") == 0)
		do_sa(a);
	else if (ft_strcmp(str, "sb\n") == 0)
		do_sb(b);
	else if (ft_strcmp(str, "ss\n") == 0)
		do_ss(a, b);
	else if (ft_strcmp(str, "ra\n") == 0)
		do_ra(a);
	else if (ft_strcmp(str, "rb\n") == 0)
		do_rb(b);
	else if (ft_strcmp(str, "rr\n") == 0)
		do_rr(a, b);
	else if (ft_strcmp(str, "rra\n") == 0)
		do_rra(a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		do_rrb(b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		do_rrr(a, b);
	else
		return (-1);
	return (0);
}

static void	checker_exe(t_list **stack, char **arr)
{
	char	*str;

	if (check_doubles((*stack)->stack_a) == -1)
		err_msg(stack, arr);
	str = get_next_line(0);
	while (str)
	{
		if (verify_execute(str, &(*stack)->stack_a, &(*stack)->stack_b) == -1)
		{
			free(str);
			err_msg(stack, arr);
		}
		free(str);
		str = get_next_line(0);
	}
	if (is_sorted((*stack)->stack_a) && !(*stack)->stack_b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

static char	*ft_joiner(const char *argv[])
{
	char	*str;
	char	*tmp;
	int		i;

	i = -1;
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (argv[++i] != NULL)
	{
		tmp = str;
		str = ft_strjoin(str, argv[i]);
		if (!str)
			return (NULL);
		if (argv[i + 1])
		{
			tmp = str;
			str = ft_strjoin(str, " ");
			if (!str)
				return (NULL);
		}
	}
	return (str);
}

static char	**ft_splitter(const char *argv[])
{
	char	**arr;
	char	*str;

	str = ft_joiner(argv);
	if (!str)
		return (NULL);
	arr = ft_split(str, ' ');
	free(str);
	if (!arr)
		return (NULL);
	return (arr);
}

int	main(int argc, const char *argv[])
{
	t_list	*stack;
	char	**arr;

	stack = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		err_msg(NULL, NULL);
	arr = ft_splitter(argv + 1);
	if (!arr)
		return (-1);
	if (empty_check(argv + 1) == -1 || parsing(arr) == -1)
		err_msg(NULL, arr);
	stack = init_stack();
	if (!stack)
	{
		free_arr(arr);
		exit(EXIT_SUCCESS);
	}
	fill_stack(arr, &stack);
	checker_exe(&stack, arr);
	free_mem(&stack, arr);
	return (0);
}
