/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:00:07 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/23 22:05:26 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file  *add_file_to_list(char *filename, t_file **file_list)
{
    t_file *file;

    file = (t_file*)malloc(sizeof(t_file));
    file->name = ft_strdup(filename);
    if (file_list)
        file->next = *file_list;
    else
        file->next = *file_list;
    *file_list = file;
    return (*file_list);
}
