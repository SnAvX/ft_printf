#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	nb_left(t_struct *info, int nb, int size)
{
	int	y;
	int	z;

	y = 0;
	z = info->precision;
	if (nb < 0 && info->precision >= size)
		info->width = info->width - 1;
	if (info->precision >= size && nb < 0)
	{
		ft_putchar_fd('-', 1);
		y += ft_putchar_fd_return('0', 1);
	}
	if ((info->width > 0 && nb < 0 && z == 0 && info->flag == '0')
		|| (nb < 0 && z >= size))
		nb = -nb;
	while (info->precision-- - size > 0)
		y += ft_putchar_fd_return('0', 1);
	if (!(nb == 0 && z == -1))
		ft_putnbr_fd(nb, 1, 0);
	while (info->width-- > 0)
		y += ft_putchar_fd_return(' ', 1);
	while (info->width-- > 0)
		y += ft_putchar_fd_return(' ', 1);
	return (y);
}

int	nb_right(t_struct *info, int nb, char c, int size)
{
	int	x;
	int	y;
	int	z;

	y = info->precision;
	z = info->width + size;
	x = 0;
	if (info->precision >= size && nb < 0)
		info->width = info->width - 1;
	while (info->width-- > 0)
		x += ft_putchar_fd_return(c, 1);
	if (nb < 0 && y >= size)
	{
		ft_putchar_fd('-', 1);
		x += ft_putchar_fd_return('0', 1);
	}
	while (info->precision-- - size > 0)
		x += ft_putchar_fd_return('0', 1);
	if ((nb < 0 && z > 0 && y == 0 && info->flag == '0')
		|| (y >= size && nb < 0)
		|| (nb < 0 && info->pre_save <= -1 && info->flag == '0'))
		nb = -nb;
	if (!(y == -1 && nb == 0))
		ft_putnbr_fd(nb, 1, 0);
	return (x);
}

int	size_len(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	ft_nb_cut(int nb, t_struct *info, int *size)
{
	if (nb == 0 && info->precision == -1)
	{
		if (info->width > 0)
			info->width = info->width + 1;
		*size = 0;
	}
	if (info->pre_save == -1 && nb == 0)
	{
		info->width--;
		info->precision = 0;
		*size = *size + 1;
	}
	if (nb < 0 && info->pre_save <= -1 && info->flag == '0')
		ft_putchar_fd('-', 1);
}

int	ft_print_nb(int nb, t_struct *info)
{
	int		z;
	int		size;
	int		size_save;
	char	c;

	z = 0;
	c = ' ';
	if (info->flag == '0' && (info->precision == 0 || info->pre_save <= -1))
		c = '0';
	size = size_len(nb);
	size_save = size;
	if ((info->precision == -1 && nb == 0) || (nb < 0 && info->pre_save <= -1))
		ft_nb_cut(nb, info, &size);
	if (info->precision == 0 && info->flag == '0' && info->width > 0 && nb < 0)
		ft_putchar_fd('-', 1);
	if (info->precision > size)
		size_save = info->precision;
	info->width = info->width - size_save;
	if (info->flag == '-')
		z = nb_left(info, nb, size);
	else
		z = nb_right(info, nb, c, size);
	return (size + z);
}
