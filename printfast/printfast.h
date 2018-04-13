/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:16:03 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/04/04 14:58:40 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFAST_H
# define PRINTFAST_H
# define BUFF_SIZE 10
# define CONV_PRINT "sdiucl"
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_att
{
	int		minus;
	int			width;
	short		type;
	char		*mod;
	int			len;
	int			count;
}				t_att;

int		is_type(char c);
int		get_width(char *s, int *i);
t_att	init_struct(void);
int		printfast(const char *s, ...);
char 	*get_s(va_list params, t_att option);
char	*ret_type(va_list params, t_att option);

#endif
