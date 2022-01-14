#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	ft_left_string(char *str, t_struct *info, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (info->precision > 0)
		while (i < info->precision && str[i])
			j += ft_putchar_fd_return(str[i++], 1);
	else
		while (str[i])
			j += ft_putchar_fd_return(str[i++], 1);
	if (info->precision >= size)
		while (info->width-- + info->precision - size > 0)
			j += ft_putchar_fd_return(' ', 1);
	else if (info->precision > 0 && info->precision < size)
	{
		while (info->width-- + size - info->precision > 0)
			j += ft_putchar_fd_return(' ', 1);
	}
	else
		while (info->width-- > 0)
			j += ft_putchar_fd_return(' ', 1);
	return (j);
}

int	ft_right_string(char *str, t_struct *info, int size, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (info->width > 0 && info->precision == 0)
		size = 0;
	if (info->precision >= size)
		while (info->width-- + info->precision - size > 0)
			j += ft_putchar_fd_return(c, 1);
	else if (info->precision > 0 && info->precision < size)
		while (info->width-- + size - info->precision > 0)
			j += ft_putchar_fd_return(c, 1);
	if (info->precision > 0)
		while (str[i] && i < info->precision)
			j += ft_putchar_fd_return(str[i++], 1);
	else
		while (str[i])
			j += ft_putchar_fd_return(str[i++], 1);
	return (j);
}

int	ft_print_lr_string(t_struct *info, char *str, int *size, char *c)
{
	int	i;

	i = 0;
	if (info->flag == '-')
		i = ft_left_string(str, info, *size);
	else
		i = ft_right_string(str, info, *size, *c);
	return (i);
}

char	ft_cut_str(char *str, t_struct *info)
{
	char	c;
	char	d;

	c = '0';
	d = ' ';
	if (info->pre_save <= -1)
		info->precision = ft_strlen(str);
	if (info->flag == '0')
		return (c);
	return (d);
}

int	ft_print_string(char *str, t_struct *info)
{
	int		size;
	int		size_str;
	int		i;
	char	c;

	i = 0;
	if (info->pre_save == 0 && info->precision == -1)
	{
		info->precision = 0;
		str = ft_strdup("");
		info->x = 1;
	}
	if (!str)
		str = ft_strdup("(null)");
	size = ft_strlen(str);
	c = ft_cut_str(str, info);
	size_str = size;
	if (info->precision > size)
		size_str = info->precision;
	info->width = info->width - size_str;
	i = ft_print_lr_string(info, str, &size, &c);
	if ((info->precision == -1 && info->pre_save == 0)
		|| info->x == 1 || (str[0] == '(' && str[1] == 'n') || !str)
		free(str);
	return (i);
}
