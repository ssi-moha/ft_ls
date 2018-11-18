/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 00:09:14 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/18 00:15:18 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

static inline int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == ' ');
}

long long			ft_atoi(const char *str)
{
	long long		i;
	int				sign;
	long long		result;

	i = 0;
	result = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - 48);
	return (result * sign);
}
