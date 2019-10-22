/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:13:01 by mkopiika          #+#    #+#             */
/*   Updated: 2018/12/05 14:13:04 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	size_t	c;
	size_t	i;
	char	*dst;

	if (s == NULL || f == NULL || !*s || !*f)
		return (NULL);
	c = ft_strlen(s);
	if (!(dst = ft_strnew(c)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dst[i] = f(s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
