/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:02:16 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 16:12:12 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "SDL2/SDL.h"

# define COUNT_NBR	13
# define EPSILON	0.00001
# define W			800
# define H			800
# define W_MAX		150
# define MAX		1000000
# define CHAR		'*'

enum				e_shapes_light_and_camera
{
	SH_SPHR = 1,
	SH_CONE,
	SH_CLNDR,
	SH_PLANE,
	L_AMBNT,
	L_POINT,
	L_DIRCTNL,
	CAMR,
};

enum				e_errors
{
	FAIL_ARGC = 20,
	FAIL_MALLOC,
	FAIL_SDL,
	FAIL_INVAL,
	FAIL_SYMBL,
	FAIL_NUMBR,
	FAIL_MNS,
	FAIL_PARAM,
};

typedef struct		s_xyz
{
	double		x;
	double		y;
	double		z;
}					t_xyz;

typedef	struct		s_len
{
	double		t1;
	double		t2;
}					t_touch;

typedef struct		s_window
{
	SDL_Window		*win_ptr;
	SDL_Surface		*srf_ptr;
	int				*img_data;
}					t_window;

typedef struct		s_valid
{
	char			*str;
	int				length;
	struct s_valid	*nxt;
	struct s_valid	*prv;
}					t_valid;

typedef struct		s_lights
{
	t_xyz			pos;
	double			intns;
	int				id;
	struct s_lights	*nxt;
}					t_lights;

typedef struct		s_shapes
{
	t_xyz			pos;
	t_xyz			clr;
	t_xyz			dir;
	double			rds;
	double			angle;
	int				sp;
	int				is;
	struct s_shapes	*nxt;
}					t_shapes;

typedef struct		s_ray
{
	t_xyz			orgn;
	t_xyz			dir;
	t_shapes		*shps;
	t_lights		*light;
	t_shapes		*shps_clt;
	t_xyz			point;
	t_xyz			norml;
	double			toch_clt;
	double			min;
	double			max;
	double			dfs_intn;
	double			spcl_intn;
}					t_ray;

typedef struct		s_camera
{
	t_xyz			pos;
	t_xyz			dir;
}					t_camera;

typedef struct		s_rtv
{
	t_window		sdl;
	t_shapes		*shps;
	t_lights		*light;
	t_valid			*lst;
	t_camera		cam;
}					t_rtv;

void				get_error(int rows, int fail);
void				loop_rtv(t_rtv *rtv);
void				calculate_tracing(t_rtv *rtv);
double				dot_prod(t_xyz *v1, t_xyz *v2);
void				mlty_sclr(t_xyz *ret, t_xyz *vct, double scalar);
void				add_vect(t_xyz *ret, t_xyz *v1, t_xyz *v2);
t_xyz				sub_vect(t_xyz *v1, t_xyz *v2);
double				vect_lenght(t_xyz *v);
void				light_compute(t_ray *r, t_lights *lgts);
void				open_read_valid(char **argv, t_rtv *rtv);
void				read_scene(int fd, t_rtv *rtv);
void				valid_rows_scene(t_valid *lst);
void				value_parsing(t_rtv *rtv);
t_shapes			*shapes_node_malloc(t_shapes *shps);
t_lights			*light_node_malloc(t_lights *light);
void				node_initialization(t_rtv *rtv, t_valid	*lst, int id);
void				make_len_one(t_xyz *vct);
void				limit_for_xyz(double low, double high, t_xyz *vect);
void				limit_for_dbl(double low, double high, double *nbr);
void				limit_for_int(int low, int high, int *nbr);
void				is_hit_shape(t_ray *r, t_shapes *shps);
void				get_discrim(t_xyz *calc, t_touch *tch);
void				set_closest_shps_touch(t_ray *r, t_touch tch,
											t_shapes *shps);
void				calc_shapes_norml(t_ray *r);
void				clamp_color(t_xyz *color);
int					get_next_line_mod(const int fd, char **line);
void				set_direction_for_cam(t_xyz *dir, t_xyz *rot);

#endif
