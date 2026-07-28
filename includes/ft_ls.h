#ifndef FT_LS_H
# define FT_LS_H

#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <printf.h>
#include "../libft/libft.h"

typedef struct s_flags {
	bool l;
	bool R;
	bool a;
	bool r;
	bool t;
}		t_flags;

typedef struct s_file{
	char *name;
	char *path;
	struct stat data;
	struct s_file *next;
}		t_file;

t_flags		*parse_flags(int ac, char **av, char ***paths, int *nb_paths);
void		ft_error(char c);

/*stat_utils.c*/
t_file *build_file(const char *dir, const char *name);
void  free_file(t_file *file);

t_file **list_dir(const char *path, int *nb_files, bool show_hidden);
/* TODO: build_file failure in list_dir leaks the already-built
 * t_file/t_list entries (return NULL instead of freeing everything) */

 
#endif