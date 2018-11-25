/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_groupname_from_gid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:00:33 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/25 15:08:35 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <grp.h>
#include <uuid/uuid.h>

void    get_groupname_from_gid(struct stat file_stat, t_file *file_list)
{
    struct group *group_info;
    
    if ((group_info = getgrgid(file_stat.st_gid)) != NULL)
        file_list->group_name = ft_strdup(group_info->gr_name);
}