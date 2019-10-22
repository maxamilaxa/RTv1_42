/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:17:37 by mkopiika          #+#    #+#             */
/*   Updated: 2018/11/01 15:17:48 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 1;
	if (n == 0)
		return (0);
	while ((*s1 == *s2) && *s1 && *s2 && n > c && n > 0)
	{
		s1++;
		s2++;
		c++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
