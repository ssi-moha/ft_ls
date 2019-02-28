/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_update_timestamp.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:52:27 by ssi-moha          #+#    #+#             */
/*   Updated: 2019/02/28 18:29:10 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void get_last_update_timestamp(struct stat file_stat, t_file **file_list)
{
    t_file *tmp;

    tmp = *file_list;
    tmp->last_update_timestamp = file_stat.st_mtimespec.tv_sec;
}