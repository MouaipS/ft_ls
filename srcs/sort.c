#include "ft_ls.h"

static t_flags	*g_flags;

/**
 * @brief qsort comparator for t_file*, reads g_flags for -t/-r
 * @warning a/b are t_file** (pointers to array elements), not t_file*
 */
static int	compare(const void *a, const void *b)
{
	t_file	*fa;
	t_file	*fb;
	int		result;

	fa = *(t_file **)a;
	fb = *(t_file **)b;
	if (g_flags->t)
	{
		if (fa->data.st_mtime < fb->data.st_mtime)
			result = 1;
		else if (fa->data.st_mtime > fb->data.st_mtime)
			result = -1;
		else
			result = 0;
	}
	else
		result = ft_strcmp(fa->name, fb->name);
	if (g_flags->r)
		result = -result;
	return (result);
}

/**
 * @brief sort a t_file array in place according to flags (-t, -r)
 * @param files : array of t_file* to sort
 * @param nb_files : number of elements in files
 * @param flags : sort criteria (-t: by mtime, -r: reverse order)
 */
void	sort_files(t_file **files, int nb_files, t_flags *flags)
{
	g_flags = flags;
	qsort(files, nb_files, sizeof(t_file *), compare);
}
