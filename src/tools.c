/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 21:06:39 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 15:31:00 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_closest_shps_touch(t_ray *r, t_touch tch, t_shapes *shps)
{
	if (tch.t1 > r->min && tch.t1 < r->max && tch.t1 < r->toch_clt)
	{
		r->toch_clt = tch.t1;
		r->shps_clt = shps;
	}
	if (tch.t2 > r->min && tch.t2 < r->max && tch.t2 < r->toch_clt)
	{
		r->toch_clt = tch.t2;
		r->shps_clt = shps;
	}
}

void	get_discrim(t_xyz *calc, t_touch *tch)
{
	double	discrim;

	discrim = calc->y * calc->y - 4 * calc->x * calc->z;
	if (discrim < 0.0)
	{
		tch->t1 = MAX;
		tch->t2 = MAX;
	}
	tch->t1 = (-calc->y + sqrt(discrim)) / (2. * calc->x);
	tch->t2 = (-calc->y - sqrt(discrim)) / (2. * calc->x);
}

void	set_direction_for_cam(t_xyz *dir, t_xyz *rot)
{
	t_xyz	buf;

	buf = *dir;
	dir->x = buf.x * cos(rot->x) + buf.z * sin(rot->x);
	dir->z = -dir->x * sin(rot->x) + dir->z * cos(rot->x);
	buf = *dir;
	dir->y = buf.y * cos(rot->y) + buf.z * sin(rot->y);
	dir->z = -buf.y * sin(rot->y) + buf.z * cos(rot->y);
	buf = *dir;
	dir->x = buf.x * cos(rot->z) - buf.y * sin(rot->z);
	dir->y = buf.x * sin(rot->z) + buf.y * cos(rot->z);
}
