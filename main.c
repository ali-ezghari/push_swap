#include "push_swap.h"

void free_arr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i++]);
    }
    free(arr);
}

static char **ft_joiner(const char *argv[])
{
    char **arr;
    char *str;
    char *tmp;
    int i;

    i = 0;
    str = ft_strdup("");
    if (!str)
        return NULL;
    while (argv[i] != NULL)
    {
        tmp = str;
        str = ft_strjoin(str, argv[i]);
        free(tmp);
        if (!str)
            return NULL;
        if (argv[i + 1])
        {
            tmp = str;
            str = ft_strjoin(str, " ");
            free(tmp);
            if (!str)
                return NULL;
        }
        i++;
    }
    arr = ft_split(str, ' ');
    free(str);
    if (!arr)
        return (NULL);
    return (arr);
}

int main(int argc, const char *argv[])
{
    t_list *stack;
    char **arr;

    if (argc < 2 || argv[1][0] == '\0')
        return 1;
    arr = ft_joiner(argv + 1);
    if (!arr)
        return (-1);
    parsing(arr);
    stack = init_stack();
    if (!stack)
    {
        free_arr(arr);
        exit(EXIT_SUCCESS);
    }
    fill_stack(arr, &stack);
    ft_push_swap(&stack, arr);
    free_mem(&stack);
    free_arr(arr);
    return 0;
}
