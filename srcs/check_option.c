/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:20:24 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/20 20:21:47 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int     check_option(int options, char flag)
{
    return (options & 1 << (int)(ft_strchr(OPTIONS, flag) - OPTIONS));
}