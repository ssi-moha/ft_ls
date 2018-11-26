/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_modification_time.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:14:36 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/25 18:28:59 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <time.h>

static inline void  format_last_update_date(char *date, char *last_update_date_formatted)
{
    int i;

    i = 0;
    if (date[i + 3] == ' ' && date[i + 4])
        i += 4;
    last_update_date_formatted = ft_strncat(last_update_date_formatted, date + i, 12);
}

static inline void format_last_update_year(char *date, char *last_update_year)
{
    int i;
    
    i = 0;
    if (date[i + 19] == ' ' && date[i + 20])
        i += 20;
    last_update_year = ft_strncat(last_update_year, date + i, 4);
}

void    get_last_modification_time(struct stat file_stat, t_file **file_list)
{
    time_t  time_of_day;
    time_t  res;
    t_file  *tmp;
    char    *date;
    
    tmp = *file_list;
    time_of_day = time(NULL);
    res = time_of_day - file_stat.st_mtimespec.tv_sec;
    date = ctime(&file_stat.st_mtimespec.tv_sec);
    if (res < SIX_MONTHS_TIMESTAMP)
        format_last_update_date(date, tmp->last_update);
    else
        format_last_update_year(date, tmp->year);
}