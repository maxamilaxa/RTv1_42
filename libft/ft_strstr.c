/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:14:16 by mkopiika          #+#    #+#             */
/*   Updated: 2018/11/01 15:14:36 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strstr(const char *hst, const char *ndl)
{
	size_t	len;

	if (!*ndl)
		return ((char*)hst);
	len = ft_strlen(ndl);
	while (*hst != '\0')
	{
		if (*hst == *ndl)
		{
			if (ft_strncmp(hst, ndl, len) == 0)
				return ((char*)hst);
		}
		hst++;
	}
	return (NULL);
}
