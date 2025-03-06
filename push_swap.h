#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
    int num;
    struct s_stack *next;    
} t_stack;

typedef struct s_list
{
    t_stack *a;
    t_stack *b;
    int size;
} t_list;

long ft_atoll(char *str);
void err_msg(void);
void parsing(char *av[]);

#endif
