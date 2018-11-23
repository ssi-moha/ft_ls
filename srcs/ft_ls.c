/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:57:48 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/23 22:06:04 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <dirent.h>
#include <string.h>

void    ft_ls(char *path, int options)
{
    DIR*            dir;
    struct          dirent *file;
    struct          stat file_stat;
    t_file          *file_list;
    t_file          *tmp;
    char            *new_path;

    new_path = NULL;
    file_list = NULL;

    printfast("%s:\n", path);

    if ((dir = opendir(path)) == NULL)
        return ;
    
    while ((file = readdir(dir)) != NULL)
    {    
        new_path = add_filename_to_path(path, file->d_name);
        stat(new_path, &file_stat);
        if (!(check_option(options, 'a') == 0 && file->d_name[0] == '.'))
        {
            if (check_option(options, 'R') && check_file_access(file_stat, S_IFDIR) == 0040000 && file->d_name[0] != '.')
                ft_ls(new_path, options);
            add_file_to_list(file->d_name, &file_list);
        }
    }
    sort_list(options, &file_list);
    tmp = file_list;
    while (tmp)
    {
        printfast("%s\n", tmp->name);
        tmp = tmp->next;
    }
    puts("");
    closedir(dir);
}
