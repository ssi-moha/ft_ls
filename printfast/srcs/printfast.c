/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:36:42 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/04/04 14:58:23 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printfast.h"

int		get_ret(char *s, va_list params, int *idx, char *buff)
{
	int i;
	t_att option;

	i = 1;
	option = init_struct();
	if (s[i] == '-')
	{
		i++;
		option.minus = 1;
	}
	option.width = get_width(s, &i);
	if (option.width == -2)
		option.width = get_as(params);
	while (is_type(s[i]) < 0)
		i++;
	option.type = is_type(s[i]);
	fill_buff(buff, idx, ret_type(params, option));
	return (i + 1);
}

void	ft_count(char *s, va_list params, int *k)
{
	char	buff[BUFF_SIZE + 1];
	int		i;
	int		idx_buff;

	i = 0;
	idx_buff = 0;
	while (s[i])
	{
		while (s[i] != '%' && s[i])
		{
			if (idx_buff == BUFF_SIZE)
			{
				write(1, buff, idx_buff);
				idx_buff = 0;
				ft_bzero(buff, BUFF_SIZE + 1);
			}
			buff[idx_buff++] = s[i++];
			(*k)++;
		}
		if (s[i] == '%')
		{
			i += get_ret(s + i , params, &idx_buff, buff);
		}
	}
	write(1, buff, idx_buff);
}

int		printfast(const char *s, ...)
{
	va_list params;
	int k;

	k = 0;
	va_start(params, s);
	ft_count(ft_strdup(s), params, &k);
	va_end(params);
	return (k);
}
