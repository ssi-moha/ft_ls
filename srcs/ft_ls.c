/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:57:48 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/24 17:04:10 by ssi-moha         ###   ########.fr       */
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
    /*while (tmp)
    {
        printfast("%s\n", tmp->name);
        tmp = tmp->next;
    }*/
    puts("");
    free_list(&file_list);
    closedir(dir);
}
