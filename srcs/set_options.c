/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:07:29 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/23 19:56:02 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static inline int   set_option(char **av, int i, int j)
{
    char *option_index;

    option_index = ft_strchr(OPTIONS, av[i][j]);

    return (option_index ? 1 << (int)(option_index - OPTIONS) : 0);
}

int                 set_options(int ac, char **av, int *i)
{
    int options;
    int j;

    (void)ac;
    options = 0;
    j = 1;
    
    while(av[*i] && av[*i][0] == '-')
    {
        j = 0;
        while (av[*i][j])
            options |= set_option(av, *i, j++);
        (*i)++;
    }
    return (options);
}