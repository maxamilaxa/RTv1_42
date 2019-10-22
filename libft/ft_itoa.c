/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:23:26 by mkopiika          #+#    #+#             */
/*   Updated: 2018/12/14 13:23:45 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ifmax(int n)
{
	if (n == -2147483648)
		return (147483648);
	else if (n < 0)
		return (n * -1);
	return (n);
}

char			*ft_itoa(int n)
{
	char		*s;
	int			nbr;
	int			i;

	nbr = n;
	i = 1;
	while ((nbr = nbr / 10))
		i++;
	if (n < 0)
		i++;
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	nbr = 0;
	if (n < 0)
		s[nbr++] = '-';
	if (n == -2147483648)
		s[nbr++] = '2';
	n = ft_ifmax(n);
	s[i] = '\0';
	while (--i >= nbr)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
	}
	return (s);
}
