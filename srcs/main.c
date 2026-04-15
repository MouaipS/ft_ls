#include "../includes/ft_ls.h"

int main(int ac, char **av) {
	t_flags	*flags;
	char	**paths;
	int		nb_paths;

	flags = parse_flags(ac, av);
	paths = parse_paths(ac, av, &nb_paths);
	if(paths == NULL){
		exit(EXIT_FAILURE);
	}
}
