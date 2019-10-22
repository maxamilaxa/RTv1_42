/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_shapes_norml.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 09:36:32 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 14:59:46 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	get_cone_normal(t_ray *r, double calc)
{
	t_xyz	orgn_c;
	t_xyz	point_c;
	double	dot_dir;
	double	dir_oc;
	double	calc_m;

	orgn_c = sub_vect(&r->orgn, &r->shps_clt->pos);
	point_c = sub_vect(&r->point, &r->shps_clt->pos);
	dot_dir = dot_prod(&r->dir, &r->shps_clt->dir);
	dir_oc = dot_prod(&orgn_c, &r->shps_clt->dir);
	calc_m = dot_dir * r->toch_clt + dir_oc;
	calc = tan((r->shps_clt->angle * M_PI / 180.0) / 2.0);
	mlty_sclr(&r->norml, &r->shps_clt->dir, (1 + calc * calc));
	mlty_sclr(&r->norml, &r->norml, calc_m);
	r->norml = sub_vect(&point_c, &r->norml);
}

static void	get_cylindr_normal(t_ray *r)
{
	t_xyz	orgn_c;
	t_xyz	point_c;
	double	dot_dir;
	double	dir_oc;
	double	calc_m;

	orgn_c = sub_vect(&r->orgn, &r->shps_clt->pos);
	point_c = sub_vect(&r->point, &r->shps_clt->pos);
	dot_dir = dot_prod(&r->dir, &r->shps_clt->dir);
	dir_oc = dot_prod(&orgn_c, &r->shps_clt->dir);
	calc_m = dot_dir * r->toch_clt + dir_oc;
	mlty_sclr(&r->norml, &r->shps_clt->dir, calc_m);
	r->norml = sub_vect(&point_c, &r->norml);
}

void		calc_shapes_norml(t_ray *r)
{
	double	calc;

	if (r->shps_clt->is == SH_SPHR)
		r->norml = sub_vect(&r->point, &r->shps_clt->pos);
	if (r->shps_clt->is == SH_PLANE)
	{
		calc = dot_prod(&r->dir, &r->shps_clt->dir);
		if (calc > 0.0)
			mlty_sclr(&r->norml, &r->shps_clt->dir, -1.0);
		else
			r->norml = r->shps_clt->dir;
	}
	if (r->shps_clt->is == SH_CLNDR)
		get_cylindr_normal(r);
	if (r->shps_clt->is == SH_CONE)
		get_cone_normal(r, calc);
}
