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
	int i;

	i = 0;
	if (info->identifier  == 'z') 
		return(0);
	else if (info->identifier == 'c') // Char
                i = ft_print_char(va_arg(arg, int), info);
	else if (info->identifier =='%')
		i = ft_print_char('%', info);
	else if (info->identifier  == 'd' || info->identifier == 'i') // int
                i = ft_print_nb(va_arg(arg, int), info);
	else if (info->identifier  == 's') // string
                i = ft_print_string(va_arg(arg, char *), info);
	else if (info->identifier  == 'p') // pointeur
                i = ft_print_pointer(va_arg(arg, long long int), info);
	else if (info->identifier  == 'u') // unsigned int
                i = ft_print_unsint(va_arg(arg, unsigned int), info);
	else if (info->identifier  == 'x' || info->identifier == 'X') // entier hexadecimal 
                i = ft_print_hexa((long long)va_arg(arg, unsigned int), info);
	return (i);
}

void ft_struct(const char *line, va_list arg, int *i, t_struct *info)
{
	init_info(info);
	flag_check(line, info, &i);
	width_check(line, info, arg, &i);
	precision_check(line, info, arg, &i);
	check_identifier(line, &i, info);
}

int	ft_printf(const char *line, ...)
{
	int 		i;
	int		j;
	va_list		arg;
	t_struct	*info;	

	i = 0;
	j = 0;
	info = (t_struct *)malloc(sizeof(t_struct));
	va_start(arg, line); // debut va_list 
	while (line[i])
	{
		if(line[i] == '%')//type affichage;
		{
			i++;
			ft_struct(line, arg, &i, info);// Remplissage de la struct
			j += choose_your_identifier(arg, info);//scan et mise en place de l'argument
		}
		else
			j += ft_putchar_fd_return(line[i++], 1); //prise en charge normal / ft_putchar normal
	}
	free(info); //Liberation memoire avnt renvoi
	va_end(arg);
	return(j);
}
