/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_filename_to_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:10:53 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/24 16:16:53 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <string.h>

char    *add_filename_to_path(char *old_path, char *filename)
{
    char    *newpath;
    int     len;

    len = ft_strlen(old_path) + ft_strlen(filename) + 2;
    if (!old_path || !filename)
        return (NULL);
    newpath = ft_strnew(len);        
    newpath = ft_strcpy(newpath, old_path);
    newpath = ft_strcat(newpath, "/");
    newpath = ft_strcat(newpath, filename);
    return (newpath);
}