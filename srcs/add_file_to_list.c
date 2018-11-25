/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:00:07 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/25 15:13:46 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file  *add_file_to_list(char *filename, t_file **file_list)
{
    t_file *file;

    file = (t_file*)malloc(sizeof(t_file));
    file->name = ft_strdup(filename);
    file->hard_links = 0;
    ft_bzero(file->file_permissions, PERMISSIONS_LINE_LEN);
    file->user_name = NULL;
    file->group_name = NULL;
    file->size = 0;

    if (file_list)
        file->next = *file_list;
    else
        file->next = *file_list;
    *file_list = file;
    return (*file_list);
}
