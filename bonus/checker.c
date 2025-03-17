#include "checker.h"

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
	free_mem(&stack, arr);
	return (0);
}
