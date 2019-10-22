/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:35:57 by mkopiika          #+#    #+#             */
/*   Updated: 2018/12/12 09:36:01 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strwrite(char const *first, char const *second, char *concat)
{
	int i;

	i = 0;
	while (first[i])
	{
		concat[i] = first[i];
		i++;
	}
	concat = ft_strcat(concat, second);
	return (concat);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		slen1;
	size_t		slen2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup((char*)s2));
	if (!s2)
		return (ft_strdup((char*)s1));
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	if (!(str = ft_strnew(slen1 + slen2)))
		return (NULL);
	str = ft_strwrite(s1, s2, str);
	return (str);
}
