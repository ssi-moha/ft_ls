/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_filename_to_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:10:53 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/21 23:44:50 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <string.h>

char    *add_filename_to_path(char *old_path, char *filename)
{
    char    *newpath;

    if (!old_path || !filename)
        return (NULL);
    newpath = ft_strjoin(old_path, ft_strjoin("/", filename));
    return (newpath);
}