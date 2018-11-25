/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file_from_stat.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:25:27 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/24 18:35:47 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <dirent.h>

static inline int   is_parent_or_current(char *dir_name)
{
    return (dir_name[0] == '.' && (!dir_name[1] || dir_name[1] == '.'));
}

void    handle_file_from_stat(char *old_path, char *file_name, int options, t_file **file_list)
{
    char            *new_path;
    struct stat     file_stat;

    new_path = add_filename_to_path(old_path, file_name);
    stat(new_path, &file_stat);
    if (check_option(options, 'R') && check_file_access(file_stat, S_IFDIR) == 0040000 && !is_parent_or_current(file_name))
        ft_ls(new_path, options);
    add_file_to_list(file_name, file_list);
    if (check_option(options, 'l'))
        get_file_informations(file_stat, file_list);
    ft_strdel(&new_path);
}