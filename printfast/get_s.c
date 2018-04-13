
#include "printfast.h"

char	*get_s(va_list params, t_att option)
{
	return(ft_strdup(va_arg(params, char*)));
}
