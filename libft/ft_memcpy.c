/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 19:45:03 by mkopiika          #+#    #+#             */
/*   Updated: 2018/11/03 19:45:08 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dt;
	unsigned char	*sr;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	dt = (unsigned char*)dest;
	sr = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dt[i] = sr[i];
		i++;
	}
	return (dest);
}
