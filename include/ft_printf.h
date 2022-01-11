/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plebiez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:27:53 by plebiez           #+#    #+#             */
/*   Updated: 2020/12/08 15:47:04 by paullebie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef	struct	s_struct
{
	char	identifier ; //type ?
	char	flag;
	int	width;
	int	precision;
	int	pre_save; // Save de la precision en verif
	int	x;
	int	check;// flag pour la berif de taille
}		t_struct;

void    ft_printmore_hexa(t_struct *info,unsigned long long int *nb, int *k, int *j);
int     ft_left_hexa(t_struct *info, unsigned long long int nb, int size);
int     ft_right_hexa(t_struct *info, unsigned long long int nb, int size, char c);
int     count_hexa(unsigned long long int nb);
int     ft_print_hexa(long long int nb, t_struct *info);

int     len_u(unsigned int nb,char *c, t_struct *info);
int     ft_right_unsint(int nb, t_struct *info,int size, char c);
int     ft_left_unsint(int nb, t_struct *info, int size);
void    ft_cut_unsint(t_struct *info, int nb, int *size, int *i);
int     ft_print_unsint(unsigned int nb, t_struct *info);

int     ft_left_pointer(t_struct *info, char *str, int size);
int     ft_right_pointer(t_struct *info, char *str, int size, char c);
void    ft_str_cut_p_vol2(t_struct *info, int *size, int nb, char *str);
char	*ft_str_cut_p(long long int nb);
int     ft_print_pointer(long long int nb, t_struct *info);

int     ft_left_string(char *str, t_struct *info, int size);
int     ft_right_string(char *str, t_struct *info, int size, char c);
int     ft_print_lr_string(t_struct *info, char *str, int *size, char *c);
char    ft_cut_str(char *str, t_struct *info);
int	ft_print_string(char *str, t_struct *info);

int	size_len(int nb);
void	ft_nb_cut(int nb, t_struct *info, int *size);
int	ft_print_nb(int nb, t_struct *info);

int	ft_left_char(char a, int size, t_struct *info);
int	ft_right_char(char a, int size, t_struct *info, char c);
int	ft_print_char(char a, t_struct *info);

int     choose_your_identifier(va_list arg, t_struct *info);
void	ft_struct(const char *line, va_list arg, int *i, t_struct *info);
int     ft_printf(const char *line, ...);

void	check_identifier(const char *line, int **i,t_struct *info);
void	precision_check(const char *line, t_struct *info, va_list arg, int **i);
void    width_check(const char *line, t_struct *info, va_list arg, int **i);
void    flag_check(const char *line, t_struct *info , int **i);
void	init_info(t_struct *info);

#endif
