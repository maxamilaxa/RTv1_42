/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hit_shape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 21:39:32 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 15:11:35 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	touch_sphere(t_touch *tch, t_ray *r, t_shapes *sphr)
{
	double	rads;
	t_xyz	orgn_c;
	t_xyz	calc;

	orgn_c = sub_vect(&r->orgn, &sphr->pos);
	rads = sphr->rds;
	calc.x = dot_prod(&r->dir, &r->dir);
	calc.y = 2 * dot_prod(&orgn_c, &r->dir);
	calc.z = dot_prod(&orgn_c, &orgn_c) - (rads * rads);
	get_discrim(&calc, tch);
}

static void	touch_plane(t_touch *tch, t_ray *r, t_shapes *pln)
{
	double	dir_oc;
	double	calc;
	t_xyz	orgn_c;

	calc = dot_prod(&r->dir, &pln->dir);
	if (calc != 0)
	{
		orgn_c = sub_vect(&r->orgn, &pln->pos);
		dir_oc = dot_prod(&orgn_c, &pln->dir);
		tch->t1 = (dir_oc * -1) / calc;
		tch->t2 = 0;
	}
	else
	{
		tch->t1 = MAX;
		tch->t2 = MAX;
	}
}

static void	touch_cone(t_touch *tch, t_ray *r, t_shapes *con)
{
	double		rdns;
	t_xyz		calc;
	t_xyz		orgn_c;
	double		dir_oc;
	double		dot_orgn_c;

	rdns = tan((con->angle * M_PI / 180.0) / 2.0);
	orgn_c = sub_vect(&r->orgn, &con->pos);
	dir_oc = dot_prod(&orgn_c, &con->dir);
	dot_orgn_c = dot_prod(&orgn_c, &orgn_c);
	calc.x = dot_prod(&r->dir, &r->dir);
	calc.y = dot_prod(&r->dir, &con->dir);
	calc.z = dot_prod(&r->dir, &orgn_c);
	calc.x = calc.x - (1 + rdns * rdns) * (calc.y * calc.y);
	calc.y = 2 * (calc.z - (1 + rdns * rdns) * calc.y * dir_oc);
	calc.z = dot_orgn_c - (1 + rdns * rdns) * (dir_oc * dir_oc);
	get_discrim(&calc, tch);
}

static void	touch_cylinder(t_touch *tch, t_ray *r, t_shapes *clndr)
{
	t_xyz		calc;
	t_xyz		orgn_c;
	double		dir_oc;
	double		dot_orgn_c;
	double		rads;

	rads = clndr->rds;
	orgn_c = sub_vect(&r->orgn, &clndr->pos);
	dir_oc = dot_prod(&orgn_c, &clndr->dir);
	dot_orgn_c = dot_prod(&orgn_c, &orgn_c);
	calc.x = dot_prod(&r->dir, &r->dir);
	calc.y = dot_prod(&r->dir, &clndr->dir);
	calc.z = dot_prod(&r->dir, &orgn_c);
	calc.x = calc.x - (calc.y * calc.y);
	calc.y = 2 * (calc.z - calc.y * dir_oc);
	calc.z = dot_orgn_c - (dir_oc * dir_oc) - (rads * rads);
	get_discrim(&calc, tch);
}

void		is_hit_shape(t_ray *r, t_shapes *shps)
{
	t_touch tch;

	r->toch_clt = MAX;
	r->shps_clt = NULL;
	ft_bzero(&tch, sizeof(t_touch));
	while (shps)
	{
		if (shps->is == SH_CONE)
			touch_cone(&tch, r, shps);
		if (shps->is == SH_CLNDR)
			touch_cylinder(&tch, r, shps);
		if (shps->is == SH_SPHR)
			touch_sphere(&tch, r, shps);
		if (shps->is == SH_PLANE)
			touch_plane(&tch, r, shps);
		set_closest_shps_touch(r, tch, shps);
		shps = shps->nxt;
	}
}
