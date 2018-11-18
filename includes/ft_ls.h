/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:47:37 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/18 19:08:34 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../printfast/includes/printfast.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# define OPTIONS "lratR" 

int                 handle_options(int ac, char **av, int *i);

typedef struct      s_file
{
    struct s_file   *next;
    struct s_file   *prev;
    char            *name;
}                   t_file;

t_file              *add_file_to_list(char *filename, t_file **file_list);
void                sort_list(int options, t_file file_list);

#endif