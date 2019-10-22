/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:03:35 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 14:51:40 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	what_id_is(int *id, t_valid *lst, int rows)
{
	if (lst->length == 0)
		return (false);
	if (ft_strstr(lst->str, "AMBIENT"))
		*id = L_AMBNT;
	else if (ft_strstr(lst->str, "DIRECTIONAL"))
		*id = L_DIRCTNL;
	else if (ft_strstr(lst->str, "POINT"))
		*id = L_POINT;
	else if (ft_strstr(lst->str, "PLANE"))
		*id = SH_PLANE;
	else if (ft_strstr(lst->str, "CYLINDER"))
		*id = SH_CLNDR;
	else if (ft_strstr(lst->str, "CAMERA"))
		*id = CAMR;
	else if (ft_strstr(lst->str, "SPHERE"))
		*id = SH_SPHR;
	else if (ft_strstr(lst->str, "CONE"))
		*id = SH_CONE;
	if (*id == 0)
		get_error(rows, FAIL_PARAM);
	return (true);
}

static void	check_number(t_valid *lst, int *i, int *count_dot, int *count_num)
{
	if (ft_isdigit(lst->str[*i]))
	{
		*count_dot = 0;
		*count_num += 1;
		while (*i < lst->length && (lst->str[*i] == '.'
									|| ft_isdigit(lst->str[*i])))
		{
			if (lst->str[*i] == '.')
				*count_dot += 1;
			*i += 1;
		}
	}
}

static void	numbers_check(int rows, t_valid *lst)
{
	int	i;
	int	count_num;
	int	count_dot;

	i = 0;
	count_num = 0;
	count_dot = 0;
	while (i < lst->length)
	{
		check_number(lst, &i, &count_dot, &count_num);
		if (count_dot > 1)
			get_error(rows, FAIL_PARAM);
		i++;
	}
	if (i > 0 && count_num != COUNT_NBR)
		get_error(rows, FAIL_NUMBR);
}

void		value_parsing(t_rtv *rtv)
{
	t_valid	*lst;
	int		id;
	int		rows;
	bool	need_parse;

	lst = rtv->lst;
	rows = 0;
	while (lst)
	{
		id = 0;
		need_parse = what_id_is(&id, lst, rows);
		numbers_check(rows, lst);
		if (need_parse == true)
		{
			if (id >= SH_SPHR && id <= SH_PLANE)
				rtv->shps = shapes_node_malloc(rtv->shps);
			if (id >= L_AMBNT && id <= L_DIRCTNL)
				rtv->light = light_node_malloc(rtv->light);
			node_initialization(rtv, lst, id);
		}
		lst = lst->nxt;
		rows++;
	}
}
