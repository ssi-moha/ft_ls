/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_modification_time.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:14:36 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/25 16:29:26 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <time.h>

void    get_last_modification_time(struct stat file_stat, t_file **file_list)
{
    time_t time_of_day;
    time_t res;
    
    (void)file_list;
    time_of_day = time(NULL);
    printf("time: %ld\n", time_of_day);
    printf("lastModif: %ld\n", file_stat.st_mtimespec.tv_sec);
    res = time_of_day - file_stat.st_mtimespec.tv_sec; 
    if (res > SIX_MONTHS_TIMESTAMP)
        puts("ok");
    else
        puts("ko");
    printfast("res :%d\n", res);
}