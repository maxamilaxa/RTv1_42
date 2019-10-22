/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:51:17 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 14:51:40 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	add_second_part(char *str, double *val_arr, int j)
{
	int		minus;
	double	second_nbr;
	int		nbr_len;

	minus = 1;
	second_nbr = 0;
	nbr_len = 0;
	if (val_arr[j] < 0)
		minus = -1;
	second_nbr = ft_atoi(str);
	while (str[nbr_len] != '\0' && ft_isdigit(str[nbr_len]))
		nbr_len++;
	if (second_nbr != 0)
	{
		while (--nbr_len > -1)
			second_nbr /= 10;
	}
	val_arr[j] += second_nbr * minus;
}

static void	read_str_val(double *val_arr, t_valid *lst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < lst->length)
	{
		while (i < lst->length && lst->str[i] != '-' &&
		(ft_isdigit(lst->str[i]) == 0))
			i++;
		if ((i > 0) && (j > 0) && lst->str[i - 1] == '.')
			add_second_part(&lst->str[i], val_arr, (j - 1));
		else
			val_arr[j++] = ft_atoi(&lst->str[i]);
		if (lst->str[i] == '-')
			i++;
		while (lst->str[i] >= '0' && lst->str[i] <= '9')
			i++;
	}
}

static void	write_val_node(double *val_arr, t_rtv *rtv, int id)
{
	t_xyz	color;
	t_xyz	pos;
	t_xyz	dir;

	pos = (t_xyz){val_arr[0], val_arr[1], val_arr[2]};
	color = (t_xyz){val_arr[5], val_arr[6], val_arr[7]};
	dir = (t_xyz){val_arr[9], val_arr[10], val_arr[11]};
	limit_for_xyz(0.0, 255.0, &color);
	make_len_one(&dir);
	if (id >= SH_SPHR && id <= SH_PLANE && rtv->shps)
	{
		*rtv->shps = (t_shapes) {.pos = pos, .dir = dir, .clr = color,
					.rds = val_arr[4], .angle = val_arr[3], .sp = val_arr[8],
					.is = id, .nxt = rtv->shps->nxt};
		limit_for_int(0, 2000, &rtv->shps->sp);
		limit_for_dbl(0.3, 100000.0, &rtv->shps->rds);
		limit_for_dbl(1.0, 179.0, &rtv->shps->angle);
	}
	if (id >= L_AMBNT && id <= L_DIRCTNL && rtv->light)
	{
		*rtv->light = (t_lights){.id = id, .nxt = rtv->light->nxt, .pos = pos,
						.intns = val_arr[12]};
		limit_for_dbl(0.0, 1.0, &rtv->light->intns);
	}
}

void		node_initialization(t_rtv *rtv, t_valid *lst, int id)
{
	double	*val_arr;

	val_arr = NULL;
	if (!(val_arr = (double*)malloc(sizeof(double) * COUNT_NBR)))
		get_error(-42, FAIL_MALLOC);
	read_str_val(val_arr, lst);
	write_val_node(val_arr, rtv, id);
	if (id == CAMR)
	{
		rtv->cam.pos = (t_xyz){val_arr[0], val_arr[1], val_arr[2]};
		rtv->cam.dir.x = val_arr[9] * M_PI / 180;
		rtv->cam.dir.y = val_arr[10] * M_PI / 180;
		rtv->cam.dir.z = val_arr[11] * M_PI / 180;
	}
	ft_memdel((void**)(&val_arr));
}
