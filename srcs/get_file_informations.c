/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_informations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:34:21 by ssi-moha          #+#    #+#             */
/*   Updated: 2019/02/28 18:30:17 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <dirent.h>

static inline char get_file_type(struct stat file_stat)
{
    if (S_ISREG(file_stat.st_mode))
        return ('-');
    else if (S_ISDIR(file_stat.st_mode))
        return ('d');
    else if (S_ISCHR(file_stat.st_mode))
        return ('c');
    else if (S_ISLNK(file_stat.st_mode))
        return ('l');
    else if (S_ISFIFO(file_stat.st_mode))
        return ('p');
    else if (S_ISSOCK(file_stat.st_mode))
        return ('s');
    else if (S_ISBLK(file_stat.st_mode))
        return ('b');
    return ('-');
}

static void    get_file_permissions(struct stat file_stat, char *permissions_line)
{
    int i;

    i = 0;
    permissions_line[i++] = get_file_type(file_stat);
    permissions_line[i++] = ((file_stat.st_mode & S_IRUSR) ? 'r' : '-');
    permissions_line[i++] = ((file_stat.st_mode & S_IWUSR) ? 'w' : '-');
    permissions_line[i] = ((file_stat.st_mode & S_IXUSR) ? 'x' : '-');
    if (file_stat.st_mode & S_ISUID)
        permissions_line[i] = (permissions_line[i] == 'x' ? 's' : 'S');
    i++;
    permissions_line[i++] = ((file_stat.st_mode & S_IRGRP) ? 'r' : '-');
    permissions_line[i++] = ((file_stat.st_mode & S_IWGRP) ? 'w' : '-');
    permissions_line[i] = ((file_stat.st_mode & S_IXGRP) ? 'x' : '-');
    if (file_stat.st_mode & S_ISGID)
        permissions_line[i] = (permissions_line[i] == 'x' ? 's' : 'S');
    i++;    
    permissions_line[i++] = ((file_stat.st_mode & S_IROTH) ? 'r' : '-');
    permissions_line[i++] = ((file_stat.st_mode & S_IWOTH) ? 'w' : '-');
    permissions_line[i] = ((file_stat.st_mode & S_IXOTH) ? 'x' : '-');
    if (file_stat.st_mode & S_ISVTX)
        permissions_line[i] = (permissions_line[i] == 'x' ? 't' : 'T');
}

static inline void get_file_hard_link_number(struct stat file_stat, t_file *tmp)
{
    tmp->hard_links = file_stat.st_nlink;
}

static inline void get_file_size(struct stat file_stat, t_file *tmp)
{
    tmp->size = file_stat.st_size;
}


void    get_file_informations(struct stat file_stat, t_file **file_list)
{
    t_file *tmp;
    
    tmp = *file_list;
    get_file_permissions(file_stat, tmp->file_permissions);
    get_file_hard_link_number(file_stat, tmp);
    get_username_from_uid(file_stat, tmp);
    get_groupname_from_gid(file_stat, tmp);
    get_file_size(file_stat, tmp);
    get_last_modification_time(file_stat, file_list);
}