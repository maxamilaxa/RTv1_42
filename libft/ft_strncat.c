/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:25:59 by mkopiika          #+#    #+#             */
/*   Updated: 2018/11/13 12:26:03 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;
	size_t	j;

	str1 = s1;
	str2 = (char*)s2;
	i = 0;
	while (str1[i] != '\0')
		i++;
	j = 0;
	while (str2[j] != '\0' && j < n)
	{
		str1[i] = str2[j];
		j++;
		i++;
	}
	str1[i++] = '\0';
	return (s1);
}
