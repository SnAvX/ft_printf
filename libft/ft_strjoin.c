/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plebiez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:24:39 by plebiez           #+#    #+#             */
/*   Updated: 2020/11/23 06:06:10 by plebiez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	size_t		len;
	char		*new;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	j = 0;
	while (i + j < len)
	{
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			new[j + i] = s2[j];
			j++;
		}
	}
	new[i + j] = '\0';
	return (new);
}
