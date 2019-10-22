/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:49:34 by mkopiika          #+#    #+#             */
/*   Updated: 2018/11/01 14:55:47 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*dest;
	char	*sour;
	size_t	i;

	dest = dst;
	sour = (char*)src;
	i = 0;
	while ((sour[i] != '\0') && (i < len))
	{
		dest[i] = sour[i];
		i++;
	}
	while (len > i)
	{
		dest[i] = '\0';
		i++;
	}
	return (dst);
}
