/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:16:27 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/04/04 14:58:09 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "printfast.h"

int		get_width(char *s, int *i)
{
	while (is_type(s[*i]) < 0 && s[*i])
	{
		if (ft_isdigit(s[*i]))
			return (ft_atoi(s + *i));
		(*i)++;
	}
	return (-1);
}
