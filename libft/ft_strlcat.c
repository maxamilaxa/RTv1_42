/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:15:00 by mkopiika          #+#    #+#             */
/*   Updated: 2018/11/13 15:15:05 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ret;

	i = 0;
	j = 0;
	if (ft_strlen(dst) <= dstsize)
		ret = ft_strlen(dst);
	else if (ft_strlen(dst) > dstsize)
		ret = dstsize;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && i < dstsize - 1 && dstsize > 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ret + ft_strlen(src));
}
