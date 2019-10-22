/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 15:28:08 by mkopiika          #+#    #+#             */
/*   Updated: 2018/11/04 15:28:14 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char*)dest;
	s = (char*)src;
	i = 0;
	if (!src && !dest)
		return (NULL);
	if (s < d)
	{
		s = s + (len - 1);
		d = d + (len - 1);
		while (len-- > 0)
			*d-- = *s--;
	}
	else
	{
		while (len-- > 0)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
