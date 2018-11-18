/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:07:07 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/18 19:04:09 by ssi-moha         ###   ########.fr       */
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
    int i;

    i = 1;
    handle_options(ac, av, &i);
    dir = opendir(av[i]);
    file_list = NULL;

    while ((file = readdir(dir)) != NULL)
        add_file_to_list(file->d_name, &file_list);
    tmp = file_list;
    while (tmp)
    {
        printf("%s\n", tmp->name);
        tmp = tmp->next;
    }
    closedir(dir);
}