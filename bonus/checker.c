#include "checker.h"

static char *ft_joiner(const char *argv[])
{
	char *str;
	char *tmp;
	int i;

	i = -1;
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (argv[++i] != NULL)
	{
		tmp = str;
		str = ft_strjoin(str, argv[i]);
		free(tmp);
		if (!str)
			return (NULL);
		if (argv[i + 1])
		{
			tmp = str;
			str = ft_strjoin(str, " ");
			free(tmp);
			if (!str)
				return (NULL);
		}
	}
	return (str);
}

static char **ft_splitter(const char *argv[])
{
	char **arr;
	char *str;

	str = ft_joiner(argv);
	if (!str)
		return (NULL);
	arr = ft_split(str, ' ');
	free(str);
	if (!arr)
		return (NULL);
	return (arr);
}

int verifyAndExecute(char *str, t_stack **a, t_stack **b)
{
	if (strncmp(str, "pa", 2) == 0)
		do_pa(a, b);
	else if (strncmp(str, "pb", 2) == 0)
		do_pb(a, b);
	else if (strncmp(str, "sa", 2) == 0)
		do_sa(a);
	else if (strncmp(str, "sb", 2) == 0)
		do_sb(b);
	else if (strncmp(str, "ss", 2) == 0)
		do_ss(a, b);
	else if (strncmp(str, "ra", 2) == 0)
		do_ra(a);
	else if (strncmp(str, "rb", 2) == 0)
		do_rb(b);
	else if (strncmp(str, "rr", 2) == 0)
		do_rr(a, b);
	else if (strncmp(str, "rra", 2) == 0)
		do_rra(a);
	else if (strncmp(str, "rrb", 2) == 0)
		do_rrb(b);
	else if (strncmp(str, "rrr", 2) == 0)
		do_rrr(a, b);
	else
		return (-1);
	return (0);
}

static void checker_exe(t_list **stack, char **arr)
{
	char *str;

	str = get_next_line(0);
	while (str)
	{
		if (verifyAndExecute(str, (*stack)->stack_a, (*stack)->stack_b) == -1)
			err_msg(stack, arr);
		str = get_next_line(0);
	}
	if (is_sorted((*stack)->stack_a))
		ft_putstr("OK");
	else
		ft_putstr("KO");
}

int main(int argc, const char *argv[])
{
	t_list *stack;
	char **arr;
	char *str;

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
