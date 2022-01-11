/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plebiez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:22:02 by plebiez           #+#    #+#             */
/*   Updated: 2020/11/22 12:23:00 by plebiez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putnbr_fd(int n, int fd, int i)
{
        long nb;

        nb = n;
        if (nb < 0)
        {
                if (i == 1)
                        ft_putchar_fd('0', fd);
                else
                        ft_putchar_fd('-', fd);
                nb = -nb;
        }
        if (nb > 9)
                ft_putnbr_fd(nb / 10, fd, 0);
        ft_putchar_fd((nb % 10) + '0', fd);
}
