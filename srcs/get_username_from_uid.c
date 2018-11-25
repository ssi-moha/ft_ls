/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_username_from_gid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:48:04 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/25 15:09:55 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <sys/stat.h>


void    get_username_from_uid(struct stat file_stat, t_file *file_list)
{
    struct passwd *user_info;
    
    if ((user_info = getpwuid(file_stat.st_uid)) != NULL)
        file_list->user_name = ft_strdup(user_info->pw_name);
}