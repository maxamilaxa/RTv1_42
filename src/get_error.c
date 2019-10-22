/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:28:44 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 15:36:52 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_error(int rows, int fail)
{
	if (rows >= 0)
	{
		ft_putnbr(++rows);
		ft_putstr(" row: ");
	}
	if (fail == FAIL_ARGC)
		ft_putendl("Usage: ./RTv1 <select the scene>");
	else if (fail == FAIL_MALLOC)
		ft_putendl("Error: Malloc failed");
	else if (fail == FAIL_SDL)
	{
		ft_putendl("Pointer to SDL failed");
		ft_putendl(SDL_GetError());
	}
	else if (fail == FAIL_INVAL)
		ft_putendl("File is invalid");
	else if (fail == FAIL_SYMBL)
		ft_putendl("Invalid symbol");
	else if (fail == FAIL_NUMBR)
		ft_putendl("Invalid numbers");
	else if (fail == FAIL_MNS)
		ft_putendl("Invalid position for minus");
	else if (fail == FAIL_PARAM)
		ft_putendl("Invalid some parameter");
	exit(fail);
}
