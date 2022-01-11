#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	ft_left_pointer(t_struct *info, char *str, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (info->precision-- - size > 0)
	{
		ft_putchar_fd('0', 1);
		j++;
	}
	write(1, "0x", 2);
	while (str[i])
		ft_putchar_fd(str[i++], 1);
	while (info->width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		j++;
	}
	return (j);
}

int	ft_right_pointer(t_struct *info, char *str, int size, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (info->width-- > 0)
	{
		ft_putchar_fd(c, 1);
		j++;
	}
	while (info->precision-- -size > 0)
	{
		ft_putchar_fd('0', 1);
		j++;
	}
	write(1, "0x", 2);
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);// i++ ?
		i++;
	}
	return (j);
}

void	ft_str_cut_p_vol2(t_struct *info, int *size, int nb, char *str)
{
	if (nb == 0 && info->precision == -1)
	{
		free(str);
		str = ft_strdup("");
		*size = *size - 1;
	}
}

char	*ft_str_cut_p(long long int nb)
{
	char *str;

	if (nb !=0)
		str = ft_itoa_base_more(nb, "0123456789abcdef");
	else
		str = ft_strdup("0");
	return (str);
}

int	ft_print_pointer(long long int nb, t_struct *info)
{
	int	size;
	int 	save_size;
	int	i;
	char	*str;
	char	c;

	i = 0;
	c = ' ';
	if (info->flag == '0')
		c = '0';
	str = ft_str_cut_p(nb);
	size = ft_strlen(str) + 2;
	ft_str_cut_p_vol2(info, &size, nb, str);
	save_size = size;
	if (info->precision > size)
		save_size = info->precision;
	info->width = info->width - save_size;
	if (info->flag == '-')
		i = ft_left_pointer(info, str, size);
	else
		i = ft_right_pointer(info, str, size, c);
	free(str);
	return (size + i);
}
