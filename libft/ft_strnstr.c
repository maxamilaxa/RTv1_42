/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:54:06 by mkopiika          #+#    #+#             */
/*   Updated: 2018/11/14 17:54:09 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *hst, const char *ndl, size_t len)
{
	size_t		c;
	size_t		l;

	c = 0;
	if (!*ndl)
		return ((char*)hst);
	l = ft_strlen(ndl);
	if (!*hst)
		return (NULL);
	while (*hst && (len - c) >= l && c < len)
	{
		if (*hst == *ndl)
		{
			if (ft_strncmp(hst, ndl, l) == 0)
				return ((char*)hst);
		}
		hst++;
		c++;
	}
	return (NULL);
}
