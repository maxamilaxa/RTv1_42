/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_valid_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:28:17 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 14:51:40 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_shapes		*shapes_node_malloc(t_shapes *shps)
{
	t_shapes	*buf;

	buf = NULL;
	if (!shps)
	{
		if (!(shps = (t_shapes *)malloc(sizeof(t_shapes))))
			get_error(-42, FAIL_MALLOC);
		ft_bzero(shps, sizeof(t_shapes));
		return (shps);
	}
	else
	{
		buf = (t_shapes *)malloc(sizeof(t_shapes));
		if (!buf)
			get_error(-42, FAIL_MALLOC);
		ft_bzero(buf, sizeof(t_shapes));
		buf->nxt = shps;
		return (buf);
	}
}

t_lights		*light_node_malloc(t_lights *light)
{
	t_lights	*buf;

	buf = NULL;
	if (!light)
	{
		if (!(light = (t_lights *)malloc(sizeof(t_lights))))
			get_error(-42, FAIL_MALLOC);
		ft_bzero(light, sizeof(t_lights));
		return (light);
	}
	else
	{
		buf = (t_lights *)malloc(sizeof(t_lights));
		if (!buf)
			get_error(-42, FAIL_MALLOC);
		ft_bzero(buf, sizeof(t_lights));
		buf->nxt = light;
		return (buf);
	}
}

void			open_read_valid(char **argv, t_rtv *rtv)
{
	int			fd;

	fd = open(argv[1], O_RDONLY);
	read_scene(fd, rtv);
	close(fd);
	valid_rows_scene(rtv->lst);
	value_parsing(rtv);
}
