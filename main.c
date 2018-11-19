/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovrsea <ovrsea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:07:07 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/19 20:39:17 by ovrsea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <dirent.h>
#include <math.h>
#include "printfast/includes/printfast.h"
#include "includes/ft_ls.h"

/*DIR* dir;
    struct dirent *file;

    dir = opendir("TEST");
    while ((file = readdir(dir)) != NULL)
        printfast("%s\n", file->d_name);
    closedir(dir);
*/


int     main(int ac, char **av)
{
    DIR* dir;
    struct dirent *file;
    t_file *file_list;
    t_file *tmp;
    int options;
    int i;

    i = 1;
    options = handle_options(ac, av, &i);
    dir = opendir(av[i]);
    file_list = NULL;

    if (options & 1 << (int)(ft_strchr(OPTIONS, 'a') - OPTIONS))
        puts("a ON");
    else
        puts("a OFF");
    while ((file = readdir(dir)) != NULL)
    {
        add_file_to_list(file->d_name, &file_list);
    }
    //tmp = file_list;
    /*while (tmp)
    {
        printf("%s\n", tmp->name);
        tmp = tmp->next;
    }*/
    puts("");
    sort_list(options, &file_list);
    tmp = file_list;
    while (tmp)
    {
        printf("%s\n", tmp->name);
        tmp = tmp->next;
    }
    closedir(dir);
}