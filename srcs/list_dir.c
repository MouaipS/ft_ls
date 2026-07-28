#include "ft_ls.h"
#include <dirent.h>
#include <stdio.h>

static void   noop(void *content){(void)content;}

/**
 * @brief list a directory's entries and return them as a t_file array
 * @param path : directory to list
 * @param nb_files : out param, filled with the number of entries returned
 * @param show_hidden : if false, entries starting with '.' are skipped
 * @return array of t_file*, or NULL on opendir failure
 * @warning malloc element (array + each t_file, see build_file)
 */
t_file **list_dir(const char *path, int *nb_files, bool show_hidden){
    DIR *dir;
    struct dirent *entry;
    t_list *head = NULL;
    if((dir = opendir(path)) == NULL){
        perror(path);
        return(NULL);
    }
    while ((entry = readdir (dir)) != NULL) {
        if(ft_strcmp(entry->d_name, ".") == 0 || ft_strcmp(entry->d_name, "..") == 0)
            continue;
        if(entry->d_name[0] == '.' && !show_hidden)
            continue;
        t_file *tmp = build_file(path, entry->d_name);
        if(!tmp)
            return (NULL);
        t_list *node = ft_lstnew(tmp);
        ft_lstadd_front(&head, node);
    }
    closedir(dir);
    *nb_files = ft_lstsize(head);
    t_file **list = malloc(sizeof(t_file *) * ft_lstsize(head));
    if(!list)
        return(NULL);
    t_list *cur = head;
    for(int i=0; i < *nb_files; i++){
        list[i] = cur->content;
        cur = cur->next;
    }
    ft_lstclear(&head, noop);
    return(list);
}