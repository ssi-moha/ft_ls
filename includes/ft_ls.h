/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:47:37 by ssi-moha          #+#    #+#             */
/*   Updated: 2019/02/28 17:54:24 by ssi-moha         ###   ########.fr       */
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
# define LAST_UPDATE_DATE 12
# define YEAR_LEN 4

int                     set_options(int ac, char **av, int *i);
typedef struct          s_file
{
    struct s_file       *next;
    char                *name;
    char                *user_name;
    char                *group_name;
    char                file_permissions[PERMISSIONS_LINE_LEN];
    int                 hard_links;
    unsigned long long  last_update_timestamp;
    off_t               size;
    char                last_update[LAST_UPDATE_DATE + 1];
    char                year[YEAR_LEN + 1];
}                       t_file;

t_file                  *add_file_to_list(char *filename, t_file **file_list);
void                    sort_list(int options, t_file **file_list);
void                    ft_ls(char *path, int options);
int                     check_option(int options, char flag);
char                    *add_filename_to_path(char *old_path, char *filename);
int                     check_file_access(struct stat file_stat, int define);
void                    free_list(t_file **file_list);
void                    handle_file_from_stat(char *old_path, char *file_name, int options, t_file **file_list);
void                    get_file_informations(struct stat file_stat, t_file **file_list);
void                    get_username_from_uid(struct stat file_stat, t_file *file_list);
void                    get_groupname_from_gid(struct stat file_stat, t_file *file_list);
void                    get_last_modification_time(struct stat file_stat, t_file **file_list);
void                    get_last_update_timestamp(struct stat file_stat, t_file **file_list);

#endif