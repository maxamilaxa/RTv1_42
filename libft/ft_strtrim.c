/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:55:48 by mkopiika          #+#    #+#             */
/*   Updated: 2018/12/12 09:55:52 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	char	*dst;
	char	*bg;
	char	*en;

	if (!s)
		return (NULL);
	bg = (char*)s;
	en = (char*)s;
	while (*(en + 1))
		en++;
	while (*bg == ' ' || *bg == '\t' || *bg == '\n')
		bg++;
	while (*en == ' ' || *en == '\t' || *en == '\n')
		en--;
	if (bg > en)
		return (ft_strnew(0));
	if (!(dst = ft_strnew((en - bg) + 1)))
		return (NULL);
	dst = dst + (en - bg) + 1;
	*dst = '\0';
	while (en >= bg)
		*(--dst) = *(en--);
	return (dst);
}
