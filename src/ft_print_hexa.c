#include "../include/ft_printf.h"
#include "../libft/libft.h"

void	ft_more(t_struct *info, unsigned long long int *nb, int *k, int *j)
{
	int		i;
	char	*str;

	i = 0;
	if (info->identifier == 'x')
		str = ft_itoa_base(*nb, "0123456789abcdef");
	else
		str = ft_itoa_base(*nb, "0123456789ABCDEF");
	if (!(*k == -1 && *nb == 0))
		while (str[i])
			*j += ft_putchar_fd_return(str[i++], 1);
	free(str);
}

int	ft_left_hexa(t_struct *info, unsigned long long int nb, int size)
{
	int	i;
	int	j;
	int	k;

	k = info->precision;
	i = 0;
	j = 0;
	if (info->pre_save == -1 && nb == 0)
	{
		j += ft_putchar_fd_return('0', 1);
		info->width--;
	}
	while (info->precision-- - size > 0)
		j += ft_putchar_fd_return('0', 1);
	ft_more(info, &nb, &k, &j);
	while (info->width-- > 0)
		j += ft_putchar_fd_return(' ', 1);
	return (j);
}

int	ft_right(t_struct *info, unsigned long long int nb, int size, char c)
{
	int	i;
	int	j;
	int	k;

	k = info->precision;
	i = 0;
	j = 0;
	if (info->pre_save == -1 && nb == 0)
	{
		info->precision = 2;
		info->width--;
	}
	if (info->precision > 0 && info->flag == '0' && info->width > 0)
		while (info->width-- > 0)
			j += ft_putchar_fd_return(c, 1);
	while (info->width-- > 0)
		j += ft_putchar_fd_return(c, 1);
	while (info->precision-- - size > 0)
		j += ft_putchar_fd_return('0', 1);
	ft_more(info, &nb, &k, &j);
	return (j);
}

int	count_hexa(unsigned long long int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_print_hexa(long long int nb, t_struct *info)
{
	int		size;
	int		size_save;
	char	c;
	int		i;

	i = 0;
	c = ' ';
	if (info->precision == -1 && info->width > 0 && nb == 0)
		info->width = info->width + 1;
	if (info->flag == '0' && (info->precision == 0 || info->pre_save <= -1))
		c = '0';
	size = count_hexa(nb);
	if (nb == 0)
		size = 1;
	size_save = size;
	if (info->precision > size)
		size_save = info->precision;
	info->width = info->width - size_save;
	if (info->flag == '-')
		i = ft_left_hexa(info, nb, size);
	else
		i = ft_right(info, nb, size, c);
	return (i);
}
