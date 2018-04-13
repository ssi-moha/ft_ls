
#include "printfast.h"

char	*get_s(va_list params, t_att option)
{
	char *str;
	char *ret;
	int len;

	str = va_arg(params, char*);
	len = ft_strlen(str);
	if (option.width == -1 || option.width >= ft_strlen(str))
		ret = ft_strdup(str);
	else
		ret = ft_strndup(str, option.width);
	return (ret);
}
