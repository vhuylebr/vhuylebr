
#include "ft_select.h"

char		*ft_strdup(char *str)
{
	int		len;
	int		i;
	char	*str_mal;

	len = ft_strlen(str);
	i = -1;
	if (!(str_mal = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i++ < len)
		str_mal[i] = str[i];
	return (str_mal);
}
