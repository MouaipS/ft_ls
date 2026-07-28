#include "ft_ls.h"

/**
 * @brief allocate a t_file and fill it (name, full path, lstat data)
 * @param dir : parent directory path
 * @param name : entry name inside dir
 * @return ptr to the allocated t_file, or NULL on failure
 * @warning malloc element
 */
t_file *build_file(const char *dir, const char *name){
    t_file *file;

    file = malloc(sizeof(t_file));
    if(!file)
        return(NULL);
    file->name = ft_strdup(name);
    int len = ft_strlen(dir);
    if(!(len > 0 && dir[len-1] == '/')){
        char *tmp = ft_strjoin(dir, "/");
        file->path = ft_strjoin(tmp, name);
        free(tmp);
    } else 
        file->path = ft_strjoin(dir, name);
    if (!file->name || !file->path || lstat(file->path, &file->data) == -1){
        free(file->name);
        free(file->path);
        free(file);
        return (NULL);
    }
    return (file);
}

/**
 * @brief free a t_file and its members
 * @param file : the t_file to free (NULL-safe)
 */
void  free_file(t_file *file)
{
  if (!file)
    return ;
  free(file->name);
  free(file->path);
  free(file);
}