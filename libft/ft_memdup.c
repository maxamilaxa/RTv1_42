/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:07:48 by mkopiika          #+#    #+#             */
/*   Updated: 2018/12/24 14:07:53 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memdup(const void *mem, size_t size)
{
	void	*dup;

	dup = malloc(size);
	if (dup == NULL)
		return (NULL);
	else
		ft_memcpy(dup, mem, size);
	return (dup);
}
