#include "push_swap.h"

int main(int argc,const char *argv[])
{
    if (argc < 2)
        err_msg();
    parsing(argv + 1);
    return 0;
}