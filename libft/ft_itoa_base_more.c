#include "libft.h"

char	*ft_itoa_base_more(unsigned long long int n, char *base)
{
	char	*str;

	str = (char *)ft_calloc(sizeof(char), 2);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin_f12(str, ft_itoa_base(-n, base));
	}
	else if (n >= (unsigned int)ft_strlen(base))
	{
		free(str);
		str = ft_strjoin_f12(ft_itoa_base_more(n / ft_strlen(base), base),
				ft_itoa_base_more(n % ft_strlen(base), base));
	}
	else if (n < (unsigned int)ft_strlen(base) && n >= 0)
	{
		str[0] = base[n];
		str[1] = '\0';
	}
	return (str);
}
