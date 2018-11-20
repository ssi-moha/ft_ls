/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:47:37 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/20 20:22:56 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../printfast/includes/printfast.h"
# include <stdlib.h>
# include <stdarg.h>
# define OPTIONS "lratR" 
# define OPTIONS_END "--"

int                 handle_options(int ac, char **av, int *i);

typedef struct      s_file
{
    struct s_file   *next;
    struct s_file   *prev;
    char            *name;
}                   t_file;

t_file              *add_file_to_list(char *filename, t_file **file_list);
void                sort_list(int options, t_file **file_list);
void                ft_ls(char *arg, int options);
int                 check_option(int options, char flag);

#endif