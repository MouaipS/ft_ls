#include "ft_ls.h"
#include "stdio.h"

void ft_error(char c){
    printf("ls: invalid option -- '%c'\n", c);
    printf("Try 'ls --help' for more information.\n");
    exit(2);
}