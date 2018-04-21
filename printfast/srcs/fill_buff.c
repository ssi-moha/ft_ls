
#include "../includes/printfast.h"

void	fill_buff(char *buff, int *idx, char *ret)
{
	int i;

	i = 0;
	while (ret[i])
	{
		if (*idx == BUFF_SIZE)
		{
			write(1, buff, *idx);
			*idx = 0;
			ft_bzero(buff, BUFF_SIZE + 1);
		}
		buff[(*idx)++] = ret[i++];
	}
}