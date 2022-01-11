/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plebiez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:07:26 by plebiez           #+#    #+#             */
/*   Updated: 2020/11/22 12:07:30 by plebiez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char *s;

	if (!(s = malloc(nmemb * size)))
		return (NULL);
	ft_memset(s, 0, nmemb * size);
	return (s);
}
