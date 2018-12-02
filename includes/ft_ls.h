/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbaudino <lucasbaudino@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:47:37 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/12/02 15:39:35 by lucasbaudin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../printfast/includes/printfast.h"
# include <stdlib.h>
# include <stdarg.h>
# include <sys/stat.h>
# define OPTIONS "lratR" 
# define OPTIONS_END "--"
# define SIX_MONTHS_TIMESTAMP 15638400
# define PERMISSIONS_LINE_LEN 13
# define LAST_UPDATE_DATE 13
# define YEAR_LEN 5

int                 set_options(int ac, char **av, int *i);
typedef struct      s_file
{
    struct s_file   *next;
    char            *name;
    char            *user_name;
    char            *group_name;
    char            file_permissions[PERMISSIONS_LINE_LEN];
    int             hard_links;
    off_t           size;
    char            last_update[LAST_UPDATE_DATE];
    char            year[YEAR_LEN];
}                   t_file;

t_file              *add_file_to_list(char *filename, t_file **file_list);
void                sort_list(int options, t_file **file_list);
void                ft_ls(char *path, int options);
int                 check_option(int options, char flag);
char                *add_filename_to_path(char *old_path, char *filename);
int                 check_file_access(struct stat file_stat, int define);
void                free_list(t_file **file_list);
void                handle_file_from_stat(char *old_path, char *file_name, int options, t_file **file_list);
void                get_file_informations(struct stat file_stat, t_file **file_list);
void                get_username_from_uid(struct stat file_stat, t_file *file_list);
void                get_groupname_from_gid(struct stat file_stat, t_file *file_list);
void                get_last_modification_time(struct stat file_stat, t_file **file_list);

#endif