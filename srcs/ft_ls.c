/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:57:48 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/21 21:17:07 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>


void    ft_ls(char *arg, int options)
{
    DIR*            dir;
    struct          dirent *file;
    struct          stat file_stat;
    t_file          *file_list;
    t_file          *tmp;
    char            *new_path;

    new_path = NULL;
    file_list = NULL;
    dir = opendir(arg);
    
    while ((file = readdir(dir)) != NULL)
    {    
        new_path = add_filename_to_path(arg, file->d_name);
        stat(new_path, &file_stat);
        if (S_ISDIR(file_stat.st_mode) && file->d_name[0] != '.')
        {
            //printfast("arg: %s\nfileName: %s\n", arg, file->d_name);
            ft_ls(new_path, options);
        }
        if (check_option(options, 'a') && file->d_name[0] == '.')
        ;
        else
            add_file_to_list(file->d_name, &file_list);
    }
    sort_list(options, &file_list);
    tmp = file_list;
    while (tmp)
    {
        printf("%s\n", tmp->name);
        tmp = tmp->next;
    }
    puts("");
    closedir(dir);
}
