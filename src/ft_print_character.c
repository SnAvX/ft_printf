#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	ft_left_char(char a, int size, t_struct *info)
{
	int	i;

	i = 0;
	if ((info->width > 0 && a == '%') || (info->precision > 0 && a == '%'))
	{
		ft_putchar_fd('%', 1);
		while (info->precision-- - size > 0)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	while (info->precision-- - size > 0)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	if (a != '%')
		ft_putchar_fd(a, 1);
	while (info->width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	return (i);
}

int	ft_right_char(char a, int size, t_struct *info, char c)
{
	int	i;

	i = 0;
	while (info->width-- > 0)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	if (info->precision > 0 && a == '%')
	{
		ft_putchar_fd('%', 1);
		return (i);
	}
	while (info->precision-- - size > 0)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	ft_putchar_fd(a, 1);
	return (i);
}

int	ft_print_char(char a, t_struct *info)
{
	int		size;
	int		size_left;
	char	c;
	int		b;

	b = 0;
	c = ' ';
	if (info->flag == '0' && info->identifier == '%' && info->precision > 0)
			info->width = info->width++;
	if (info->flag == '0')
		c = '0';
	size = 1;
	size_left = size;
	if (info->precision > size)
		size_left = info->precision;
	info->width = info->width - size_left;
	if (info->flag == '-')
		b = ft_left_char(a, size, info);
	else
		b = ft_right_char(a, size, info, c);
	return (size + b);
}
