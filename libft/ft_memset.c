/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 16:05:26 by mkopiika          #+#    #+#             */
/*   Updated: 2018/11/03 16:23:24 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*m;

	i = 0;
	m = (unsigned char*)b;
	while (i < len)
	{
		m[i] = (unsigned char)c;
		i++;
	}
	if (b == NULL)
		return (NULL);
	return (b);
}
