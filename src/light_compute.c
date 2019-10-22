/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_compute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:05:43 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 15:23:47 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		vect_lenght(t_xyz *v)
{
	double	x;
	double	y;
	double	z;
	double	len;

	x = v->x * v->x;
	y = v->y * v->y;
	z = v->z * v->z;
	len = sqrt(x + y + z);
	return (len);
}

static void	specular_compute(t_ray *b, t_shapes *shp_cls,
							t_lights *lgts, t_xyz d_ray)
{
	t_xyz	calc;
	double	dot;
	double	len;
	double	power_func;

	mlty_sclr(&calc, &b->norml, 2.0);
	dot = dot_prod(&b->norml, &b->dir);
	mlty_sclr(&calc, &calc, dot);
	calc = sub_vect(&calc, &b->dir);
	dot = dot_prod(&calc, &d_ray);
	if (dot > 0.0)
	{
		len = vect_lenght(&calc);
		len *= vect_lenght(&d_ray);
		power_func = pow(dot / len, shp_cls->sp);
		b->spcl_intn += lgts->intns * power_func;
	}
}

static void	compute_shadow(t_ray *b, t_shapes *shp_cls,
							t_lights *lgts, t_xyz d_ray)
{
	double	calc;
	double	len;

	b->shps_clt = NULL;
	b->toch_clt = 0.0;
	is_hit_shape(b, b->shps);
	if (b->shps_clt == NULL)
	{
		calc = dot_prod(&b->norml, &b->dir);
		if (calc > 0)
		{
			len = vect_lenght(&b->norml);
			len *= vect_lenght(&b->dir);
			b->dfs_intn += (lgts->intns * calc) / len;
		}
		if (shp_cls->sp > 0.0)
			specular_compute(b, shp_cls, lgts, d_ray);
	}
}

void		point_direct_shadow(t_ray *r, t_lights *lgts, t_ray *buf)
{
	t_xyz	dir_lgt;

	if (lgts->id == L_POINT)
	{
		dir_lgt = sub_vect(&lgts->pos, &buf->point);
		buf->max = 1.0;
	}
	else
	{
		dir_lgt = lgts->pos;
		buf->max = MAX;
	}
	buf->min = EPSILON;
	buf->orgn = buf->point;
	buf->dir = dir_lgt;
	compute_shadow(buf, r->shps_clt, lgts, r->dir);
}

void		light_compute(t_ray *r, t_lights *lgts)
{
	t_ray	buf;

	buf = *r;
	buf.dfs_intn = 0.0;
	buf.spcl_intn = 0.0;
	while (lgts)
	{
		if (lgts->id == L_AMBNT)
			buf.dfs_intn += lgts->intns;
		else
			point_direct_shadow(r, lgts, &buf);
		lgts = lgts->nxt;
	}
	r->spcl_intn = buf.spcl_intn;
	r->dfs_intn = buf.dfs_intn;
}
