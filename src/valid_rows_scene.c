/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_rows_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:41:38 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 14:51:40 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	is_valid_double(int i, char *str)
{
	int	count;

	count = 0;
	if (i > 0)
	{
		if (ft_isdigit(str[i - 1]))
			count++;
		if (ft_isdigit(str[i + 1]))
			count++;
		if (count == 2)
			return (true);
	}
	return (false);
}

static bool	is_valid_char(char sym)
{
	if (sym == '|'
		|| sym == '-'
		|| sym == ' '
		|| sym == '.'
		|| ft_isdigit(sym)
		|| ft_isalpha(sym))
		return (true);
	return (false);
}

static void	is_valid_symbl_in_str(int rows, t_valid *lst)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = lst->length;
	str = lst->str;
	while (i < len)
	{
		if (is_valid_char(str[i]) == false)
			get_error(rows, FAIL_SYMBL);
		if (str[i] == '-' && !(ft_isdigit(str[i + 1])))
			get_error(rows, FAIL_MNS);
		if (str[i] == '.' && (is_valid_double(i, str) == false))
			get_error(rows, FAIL_NUMBR);
		i++;
	}
}

void		valid_rows_scene(t_valid *lst)
{
	int	row;

	row = 0;
	while (lst)
	{
		is_valid_symbl_in_str(row, lst);
		lst = lst->nxt;
		row++;
	}
}
