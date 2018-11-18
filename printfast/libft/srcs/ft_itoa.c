/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <ssi-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 00:22:36 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/11/18 00:22:38 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_len(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_putnbr_tab(char *str, int len, int n)
{
	str[len] = n % 10 + 48;
	n = n / 10;
	len--;
	if (n != 0)
		ft_putnbr_tab(str, len, n);
	return (str);
}

static char		*ft_exept(void)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * (9 + 3))))
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str = ft_putnbr_tab(str, 10, 147483648);
	str[11] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		str = ft_exept();
	else if (n < 0)
	{
		len = ft_len(-n);
		if (!(str = (char *)malloc(sizeof(char) * len + 2)))
			return (NULL);
		str[0] = '-';
		str = ft_putnbr_tab(str, len, -n);
		str[len + 1] = '\0';
	}
	else
	{
		len = ft_len(n);
		if (!(str = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		str = ft_putnbr_tab(str, len - 1, n);
		str[len] = '\0';
	}
	return (str);
}
