/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:29:49 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 14:51:40 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				len_to_char(const char *s, char symbl)
{
	int		len;

	len = 0;
	while (*s && *s != symbl)
	{
		s++;
		len++;
	}
	return (len);
}

static t_valid	*make_line(t_valid *line, char *string)
{
	if (!line)
	{
		if (!(line = (t_valid*)malloc(sizeof(t_valid))))
			get_error(-42, FAIL_MALLOC);
		ft_bzero(line, sizeof(t_valid));
		line->str = ft_strdup(string);
		line->length = len_to_char(string, CHAR);
		return (line);
	}
	else
	{
		if (!(line->nxt = (t_valid*)malloc(sizeof(t_valid))))
			get_error(-42, FAIL_MALLOC);
		line->nxt->str = ft_strdup(string);
		line->nxt->length = len_to_char(string, CHAR);
		line->nxt->nxt = NULL;
		line->nxt->prv = line;
		return (line->nxt);
	}
}

void			read_scene(int fd, t_rtv *rtv)
{
	int		rows;
	int		res;
	char	*str;

	res = 0;
	rows = 0;
	rtv->lst = NULL;
	while ((res = get_next_line_mod(fd, &str)) > 0)
	{
		rtv->lst = make_line(rtv->lst, str);
		if (rtv->lst->length > W_MAX)
			get_error(rows, FAIL_INVAL);
		ft_strdel(&str);
		rows++;
	}
	if ((!rtv->lst) || res == -1)
		get_error(-42, FAIL_INVAL);
	if (rows > 200)
		get_error(-42, FAIL_INVAL);
	while (rtv->lst->prv)
		rtv->lst = rtv->lst->prv;
}
