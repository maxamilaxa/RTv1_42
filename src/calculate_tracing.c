/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_tracing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:25:17 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 15:15:14 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	print_pixel(int *img_data, t_xyz clr, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = W / 2 + x;
	new_y = H / 2 - y - 1;
	img_data[new_y * W + new_x] = (0 << 24 | (int)clr.x << 16 | (int)clr.y << 8
			| (int)clr.z);
}

static void	set_color(t_ray *r, t_xyz *clr)
{
	t_xyz	color;
	t_xyz	dfs_intn;
	t_xyz	spcl_intn;

	color = (t_xyz){255.0, 255.0, 255.0};
	mlty_sclr(&dfs_intn, &r->shps_clt->clr, r->dfs_intn);
	mlty_sclr(&spcl_intn, &color, r->spcl_intn);
	add_vect(clr, &spcl_intn, &dfs_intn);
	clamp_color(clr);
}

static void	ray_tracing(t_ray *r, t_xyz *clr)
{
	t_xyz	tmp;

	r->shps_clt = NULL;
	r->toch_clt = MAX;
	is_hit_shape(r, r->shps);
	if (r->shps_clt == NULL)
		*clr = (t_xyz){227, 254, 255};
	else
	{
		mlty_sclr(&r->point, &r->dir, r->toch_clt);
		add_vect(&r->point, &r->point, &r->orgn);
		calc_shapes_norml(r);
		mlty_sclr(&tmp, &r->norml, EPSILON);
		add_vect(&r->point, &r->point, &tmp);
		mlty_sclr(&r->dir, &r->dir, -1);
		light_compute(r, r->light);
		set_color(r, clr);
	}
}

void		get_ray_direction(t_xyz *direction, int x, int y)
{
	direction->x = x * 1.0 / W;
	direction->y = y * 1.0 / H;
	direction->z = 1.0;
}

void		calculate_tracing(t_rtv *rtv)
{
	t_xyz	clr;
	t_ray	r;
	int		y;
	int		x;

	rtv->sdl.img_data = rtv->sdl.srf_ptr->pixels;
	r.min = 1;
	r.max = MAX;
	r.shps = rtv->shps;
	r.light = rtv->light;
	r.orgn = rtv->cam.pos;
	y = -H / 2 - 1;
	while (++y < H / 2)
	{
		x = -W / 2;
		while (x < W / 2)
		{
			get_ray_direction(&r.dir, x, y);
			set_direction_for_cam(&r.dir, &rtv->cam.dir);
			ray_tracing(&r, &clr);
			print_pixel(rtv->sdl.img_data, clr, x, y);
			x++;
		}
	}
	SDL_UpdateWindowSurface(rtv->sdl.win_ptr);
}
