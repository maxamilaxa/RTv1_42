/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:43:30 by mkopiika          #+#    #+#             */
/*   Updated: 2018/11/13 17:43:33 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr(const char *s, int c)
{
	char	*chr;
	char	sim;
	int		i;

	chr = (char*)s;
	sim = (char)c;
	i = 0;
	while (chr[i] != '\0')
	{
		if (chr[i] == sim)
			return (chr + i);
		i++;
	}
	if (sim == '\0')
		return (chr + i);
	return (NULL);
}
