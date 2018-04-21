
#include "../includes/printfast.h"

char    *get_d(va_list params, t_att option)
{
    char *str;
	char *ret;
	int len;

    if (option.type == 3)
        str = ft_ltoa(va_arg(params, long));
    else 
	    str = ft_itoa(va_arg(params, int));
    len = ft_strlen(str);
    if (option.width > len)
    {
        ret = ft_strnew(option.width - len);
        ft_memset(ret, ' ', option.width - len); 
        if (option.minus)   
            ret = ft_strjoin(str, ret);
        else 
            ret = ft_strjoin(ret, str);
    }
    else
        return (str);  
    return (ret);
}