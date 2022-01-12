/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullebiez <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:45:30 by paullebie         #+#    #+#             */
/*   Updated: 2020/12/08 15:46:51 by paullebie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	choose_your_identifier(va_list arg, t_struct *info)
{
	int	i;

	i = 0;
	if (info->identifier == 'z')
		return (0);
	else if (info->identifier == 'c')
		i = ft_print_char(va_arg(arg, int), info);
	else if (info->identifier == '%')
		i = ft_print_char('%', info);
	else if (info->identifier == 'd' || info->identifier == 'i')
		i = ft_print_nb(va_arg(arg, int), info);
	else if (info->identifier == 's')
		i = ft_print_string(va_arg(arg, char *), info);
	else if (info->identifier == 'p')
		i = ft_print_pointer(va_arg(arg, long long int), info);
	else if (info->identifier == 'u')
		i = ft_print_unsint(va_arg(arg, unsigned int), info);
	else if (info->identifier == 'x' || info->identifier == 'X')
		i = ft_print_hexa((long long)va_arg(arg, unsigned int), info);
	return (i);
}

void	ft_struct(const char *line, va_list arg, int *i, t_struct *info)
{
	init_info(info);
	flag_check(line, info, &i);
	width_check(line, info, arg, &i);
	precision_check(line, info, arg, &i);
	check_identifier(line, &i, info);
}

int	ft_printf(const char *line, ...)
{
	int			i;
	int			j;
	va_list		arg;
	t_struct	*info;	

	i = 0;
	j = 0;
	info = (t_struct *)malloc(sizeof(t_struct));
	va_start(arg, line);
	while (line[i])
	{
		if (line[i] == '%')
		{
			i++;
			ft_struct(line, arg, &i, info);
			j += choose_your_identifier(arg, info);
		}
		else
			j += ft_putchar_fd_return(line[i++], 1);
	}
	free(info);
	va_end(arg);
	return (j);
}
