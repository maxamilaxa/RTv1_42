/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:32:29 by mkopiika          #+#    #+#             */
/*   Updated: 2018/11/16 15:32:33 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	void *m;

	m = (void*)malloc(sizeof(void) * (size));
	if (!m)
		return (NULL);
	ft_bzero(m, size);
	return (m);
}
