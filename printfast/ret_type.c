
#include "printfast.h"

char	*ret_type(va_list params, t_att option)
{
	char *(*tab[7])(va_list params, t_att option);

	tab[0] = get_s;

	return (tab[option.type](params, option));
}