/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:23:51 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/04/04 14:41:23 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printfast.h"

t_att		init_struct(void)
{
	t_att ret;

	ret.minus = 0;
	ret.width = -1;
	ret.type = -1;
	ret.len = 0;
	ret.count = 0;
	return (ret);
}
