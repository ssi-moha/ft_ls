/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbaudino <lucasbaudino@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:57:48 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/12/02 17:33:41 by lucasbaudin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <dirent.h>
#include <string.h>

void    ft_ls(char *path, int options)
{
    DIR*            dir;
    struct          dirent *file;
    t_file          *file_list;
    t_file          *tmp;

    file_list = NULL;

    printfast("%s:\n", path);

    if ((dir = opendir(path)) == NULL)
        return ;
    
    while ((file = readdir(dir)) != NULL)
    {    
        if (!(check_option(options, 'a') == 0 && file->d_name[0] == '.'))
        {
            handle_file_from_stat(path, file->d_name, options, &file_list);
        }
    }
    sort_list(options, &file_list);
    tmp = file_list;
    while (tmp)
    {
        if (check_option(options, 'l'))
            printfast(
                "%s  %d  %s  %s  %d  %s  %s\n", 
                tmp->file_permissions, 
                tmp->hard_links, 
                tmp->user_name, 
                tmp->group_name,
                tmp->size,
                tmp->last_update,
                tmp->name
            );
        else
            printfast("%s\n", tmp->name);
        tmp = tmp->next;
    }
    free_list(&file_list);
    closedir(dir);
}
