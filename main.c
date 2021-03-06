/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:07:07 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/24 15:03:29 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <dirent.h>
#include <math.h>
#include "printfast/includes/printfast.h"
#include "includes/ft_ls.h"

int     main(int ac, char **av)
{
    int options;
    int i;
   
    i = 1;
    options = set_options(ac, av, &i);
    
    if (i == ac)
        ft_ls(".", options);
    while (i < ac)
        ft_ls(av[i++], options);
}