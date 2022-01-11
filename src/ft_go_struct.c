#include "../include/ft_printf.h"
#include "../libft/libft.h"

void	check_identifier(const char *line, int **i, t_struct *info)
{
	if (line[**i] && (line[**i] == 'c' || line[**i] == 's' || line[**i] == 'p' ||
		line[**i] == 'd' || line[**i] == 'i' || line[**i] == 'u' ||
		line[**i] == 'u' || line[**i] == 'x' || line[**i] == 'X' ||
		line[**i] == '%'))
	{
		info->identifier = line[**i];
		**i += 1;
	}
	else
		info->identifier = 'z';
}

void	precision_check(const char *line, t_struct *info, va_list arg, int **i)
{
	if (line[**i] && line[**i] == '.')
	{
		**i += 1;
		if (line[**i] == '*')
		{
			info->check = 1;
			info->precision = va_arg(arg, int);
			info->pre_save = info->precision;
			if(info->precision == 0)
				info->precision = -1;
		}
		else
			info->precision = ft_atoi(&line[**i]) != 0 ? ft_atoi(&line[**i]) : -1;
		while (line[**i] && ((line[**i] >= '0' && line[**i]<= '9') || line[**i] == '*'))
			**i += 1;
	}
}

void	width_check(const char *line, t_struct *info, va_list arg, int **i)
{
	if (line[**i] >= '0' && line[**i] <= '9')
		info->width = ft_atoi(&line[**i]);
	if (line[**i] == '*')
	{
		info->width = va_arg(arg, int);
		if (info->width < 0)
		{
			info->width = -info->width;
			info->flag = '-';
		}
	}
	while (line[**i] && ((line[**i] >= '0' && line[**i] <= '9' ) ||
		line[**i] == '*'))
		**i += 1;
}

void	flag_check(const char *line, t_struct *info , int **i)
{
	if (line[**i] == '-') //Left justify
	{
		info->flag = '-';
		while (line[**i] && (line[**i] == '-' || line[**i] == '0'))
			**i += 1;
		return;
	}
	if (line[**i] == '0')
	{
		info->flag = '0';
		while (line[**i] && (line[**i] == '0' || line[**i] == '-'))
		{
			if(line[**i] == '-')
				info->flag = '-';
			**i += 1;
		}
		return;
	}
	
}

void	init_info(t_struct *info)
{
	info->identifier = 0;
	info->flag = 0;
	info->width = 0;
	info->precision = 0;
	info->pre_save = 0;
	info->x = 0;
	info->check = 0;
}
