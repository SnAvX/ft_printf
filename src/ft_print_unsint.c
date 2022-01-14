#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	len_u(unsigned int nb, char *c, t_struct *info)
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
		i++;
		nb = nb / 10;
	}
	if (info->flag == '0' && (info->precision == 0 || info->pre_save <= -1))
		*c = '0';
	return (i);
}

int	ft_right_unsint(int nb, t_struct *info, int size, char c)
{
	int	i;
	int	j;

	i = 0;
	j = info->precision;
	if (info->pre_save == 0 && info->flag != '0' && nb == 0)
		i--;
	if (info->pre_save >= 0 && info->flag == '0' && nb == 0 && info->check != 1)
		i--;
	if (info->pre_save >= 0 && info->check == 1 && nb == 0)
		i--;
	if (info->flag == '0' && info->width > 0 && info->precision > 0)
		while (info->width-- > 0)
			i += ft_putchar_fd_return(' ', 1);
	while (info->width-- > 0)
		i += ft_putchar_fd_return(c, 1);
	while (info->precision-- - size > 0)
		i += ft_putchar_fd_return('0', 1);
	if (!(j == -1 && nb == 0) || (nb == 0 && info->pre_save <= -1))
		ft_putnbr_unsigned(nb);
	return (i);
}

int	ft_left_unsint(int nb, t_struct *info, int size)
{
	int	i;
	int	j;

	i = 0;
	j = info->precision;
	if (info->pre_save >= 0 && nb == 0)
		i--;
	while (info->precision-- - size > 0)
		i += ft_putchar_fd_return('0', 1);
	if (!(j == -1 && nb == 0))
		ft_putnbr_unsigned(nb);
	while (info->width-- > 0)
		i += ft_putchar_fd_return(' ', 1);
	return (i);
}

void	ft_cut_unsint(t_struct *info, int nb, int *size, int *i)
{
	if (info->pre_save >= 0 && nb == 0)
	{
		*i = *i + 1;
		*size = *size + 1;
	}
	if (info->flag == 0 && info->check == 1 && info->pre_save == 0 && nb == 0)
		info->width++;
	if (info->flag == '0' && info->check == 1 && info->pre_save == 0 && nb == 0)
	{
		*i = *i + 1;
		info->width++;
	}
	if (info->flag == '-' && info->check == 1 && info->pre_save == 0 && nb == 0)
	{
		*i = *i - 1;
		info->width++;
	}
	if (info->precision == -1 && nb == 0 && info->check != 1)
	{
		*i = *i + 1;
		info->width++;
	}
}

int	ft_print_unsint(unsigned int nb, t_struct *info)
{
	int		size;
	int		save_size;
	char	c;
	int		i;

	i = 0;
	c = ' ';
	if (info->pre_save <= -1 && nb == 0)
	{
		info->width--;
		info->precision = 0;
		i++;
	}
	size = len_u(nb, &c, info);
	ft_cut_unsint(info, nb, &size, &i);
	save_size = size;
	if (info->precision > size)
		save_size = info->precision;
	info->width = info->width - save_size;
	if (info->flag == '-')
		i += ft_left_unsint(nb, info, size);
	else
		i += ft_right_unsint(nb, info, size, c);
	return (i + size);
}
