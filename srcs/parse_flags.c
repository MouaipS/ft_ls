#include "ft_ls.h"
#include <unistd.h>

/**
 * @brief parse the arguments to extract flags and separate the paths
 * @param ac/av : classic input
 * @param paths : array of remaining arguments (paths)
 * @param nb_paths : number of paths
 * @return ptr to the allocated t_flags struct
 * @warning malloc element
 * @warning invalid flag -> exit(2)
 */
t_flags	*parse_flags(int ac, char **av, char ***paths, int *nb_paths)
{
	t_flags	*flags;
	int		opt;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	ft_memset(flags, 0, sizeof(t_flags));
	opterr = 0;
	while ((opt = getopt(ac, av, "laRrt")) != -1)
	{
		if (opt == 'l')
			flags->l = true;
		else if (opt == 'R')
			flags->R = true;
		else if (opt == 'a')
			flags->a = true;
		else if (opt == 'r')
			flags->r = true;
		else if (opt == 't')
			flags->t = true;
		else
			ft_error(optopt);
	}
	*paths = av + optind;
	*nb_paths = ac - optind;
	return (flags);
}
