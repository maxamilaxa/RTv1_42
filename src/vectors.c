/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 13:52:46 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 14:51:40 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_xyz		sub_vect(t_xyz *v1, t_xyz *v2)
{
	t_xyz	vect;

	vect.x = v1->x - v2->x;
	vect.y = v1->y - v2->y;
	vect.z = v1->z - v2->z;
	return (vect);
}

void		add_vect(t_xyz *ret, t_xyz *v1, t_xyz *v2)
{
	ret->x = v1->x + v2->x;
	ret->y = v1->y + v2->y;
	ret->z = v1->z + v2->z;
}

double		dot_prod(t_xyz *v1, t_xyz *v2)
{
	double	dot;
	double	x;
	double	y;
	double	z;

	x = v1->x * v2->x;
	y = v1->y * v2->y;
	z = v1->z * v2->z;
	dot = x + y + z;
	return (dot);
}

void		mlty_sclr(t_xyz *ret, t_xyz *vct, double scalar)
{
	ret->x = vct->x * scalar;
	ret->y = vct->y * scalar;
	ret->z = vct->z * scalar;
}

void		clamp_color(t_xyz *color)
{
	if (color->x < 0.0)
		color->x = 0.0;
	if (color->x > 255.0)
		color->x = 255.0;
	if (color->y < 0.0)
		color->y = 0.0;
	if (color->y > 255.0)
		color->y = 255.0;
	if (color->z < 0.0)
		color->z = 0.0;
	if (color->z > 255.0)
		color->z = 255.0;
}
