#include "ft_ls.h"
#include <stdio.h> 

void print_files(t_file **files, int nb_files, t_flags *flags){
    (void)flags;
    for(int i=0; i < nb_files; i++){
        printf("%s\n", files[i]->name);
    }
}