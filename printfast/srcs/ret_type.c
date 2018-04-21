 
#include "../includes/printfast.h"

char	*ret_type(va_list params, t_att option)
{
	char *(*tab[7])(va_list params, t_att option);

	tab[0] = &get_s;
	tab[1] = &get_d;
	tab[2] = &get_c;
	tab[3] = &get_d;
	return (tab[option.type](params, option));
}