/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:57:48 by ssi-moha          #+#    #+#             */
/*   Updated: 2019/02/28 19:48:55 by ssi-moha         ###   ########.fr       */
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
    static int      first_file = 0;
            
    file_list = NULL;
    
    if (++first_file != 1)
        printfast("%s:\n", path);
    //printfast("path: %s", path);
    if ((dir = opendir(path)) == NULL)
        return ;
    
    while ((file = readdir(dir)) != NULL)
        if (!(check_option(options, 'a') == 0 && file->d_name[0] == '.'))
            handle_file_from_stat(path, file->d_name, options, &file_list);

    sort_list(options, &file_list);
    tmp = file_list;
    while (tmp)
    {
        if (check_option(options, 'l'))
        {
            printf("%s\n", tmp->file_permissions);
            printf("%d\n", tmp->hard_links);
            printf("%s\n", tmp->user_name);
            printf("%s\n", tmp->group_name);
            printf("%lld\n", tmp->size);
            printf("lastUpdate: %s\n", ft_strlen(tmp->last_update) > 0 ? tmp->last_update : tmp->year);
            printf("name:\n");
            printf("%s\n", tmp->name);
            ft_putchar('\n');
        }
        else
            printf("%s\n", tmp->name);
        tmp = tmp->next;
    }
    free_list(&file_list);
    closedir(dir);
    ft_putchar('\n');
}

/*printf(
                "%s  %d  %s  %s  %lld  %s  %s\n", 
                tmp->file_permissions, 
                tmp->hard_links, 
                tmp->user_name, 
                tmp->group_name,
                tmp->size,
                tmp->last_update,
                tmp->name
            );*/