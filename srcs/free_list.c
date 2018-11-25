/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:57:56 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/25 15:05:04 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdlib.h>

void    free_list(t_file **file_list)
{
    t_file *tmp;
    t_file *tmp2;

    if (!*file_list)
        return;
    tmp = *file_list;
    tmp2 = NULL;
    while((tmp2 = tmp->next) != NULL)
    {
        ft_strdel(&(tmp->name));
        ft_strdel(&(tmp->user_name));
        ft_strdel(&(tmp->group_name));
        free(tmp);
        tmp = tmp2;
    }
    ft_strdel(&(tmp->name));
    ft_strdel(&(tmp->user_name));
    ft_strdel(&(tmp->group_name));
    free(tmp);
}