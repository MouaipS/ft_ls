#include "../includes/ft_ls.h"
#include <stdio.h>

static bool	is_directory(const char *path)
{
	struct stat	st;

	if (stat(path, &st) == -1)
		return (false);
	return (S_ISDIR(st.st_mode));
}

int	main(int ac, char **av)
{
	t_flags	*flags;
	char	**paths;
	int		nb_paths;
	char	*default_path[1];
	int		i;

	flags = parse_flags(ac, av, &paths, &nb_paths);
	if (nb_paths == 0)
	{
		default_path[0] = ".";
		paths = default_path;
		nb_paths = 1;
	}
	i = 0;
	while (i < nb_paths)
	{
		if (is_directory(paths[i]))
			printf("%s: directory\n", paths[i]);
		else
			printf("%s: file\n", paths[i]);
		i++;
	}
	free(flags);
	return (0);
}
