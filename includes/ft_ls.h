/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:47:37 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/23 22:05:14 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../printfast/includes/printfast.h"
# include <stdlib.h>
# include <stdarg.h>
# define OPTIONS "lratR" 
# define OPTIONS_END "--"
# include <sys/stat.h>


int                 set_options(int ac, char **av, int *i);

typedef struct      s_file
{
    struct s_file   *next;
    char            *name;
}                   t_file;

t_file              *add_file_to_list(char *filename, t_file **file_list);
void                sort_list(int options, t_file **file_list);
void                ft_ls(char *path, int options);
int                 check_option(int options, char flag);
char                *add_filename_to_path(char *old_path, char *filename);
int                check_file_access(struct stat file_stat, int define);

#endif