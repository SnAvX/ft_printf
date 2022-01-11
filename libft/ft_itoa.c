/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plebiez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:09:08 by plebiez           #+#    #+#             */
/*   Updated: 2020/11/23 05:30:03 by plebiez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	char	*str;

	nb = n;
	len = (n > 0) ? 0 : 1;
	nb = (nb > 0) ? nb : -nb;
	while (n)
		n = len++ ? n / 10 : n / 10;
	str = (char *)malloc(sizeof(str) * len + 1);
	if (!str)
		return (NULL);
	*(str + len--) = '\0';
	while (nb > 0)
	{
		*(str + len--) = nb % 10 + '0';
		nb /= 10;
	}
	if (len == 0 && str[1] == '\0')
		*(str + len) = '0';
	if (len == 0 && str[1] != '\0')
		*(str + len) = '-';
	return (str);
}
