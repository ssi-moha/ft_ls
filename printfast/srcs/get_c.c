
#include "../includes/printfast.h"

char    *get_c(va_list params, t_att option)
{
    char c;
	char *ret;

    c = va_arg(params, int);
    if (option.width > 1)
    {
        ret = ft_strnew(option.width);
        ft_memset(ret, ' ', option.width); 
        if (option.minus)   
            ret[0] = c;
        else 
            ret[option.width] = c;
    }
    else
    {
        ret = ft_strnew(1);
        ret[0] = c;
    }
    return (ret);
}