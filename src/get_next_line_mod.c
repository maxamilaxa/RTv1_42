/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_mod.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:15:21 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 14:51:40 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static char		*ft_srch_char(const char *s, int c)
{
	char		*chr;
	char		sim;
	int			i;

	chr = (char*)s;
	sim = (char)c;
	i = 0;
	if (!s)
		return (NULL);
	while (chr[i] != '\0')
	{
		if (chr[i] == sim)
			return (chr + i);
		i++;
	}
	if (sim == '\0')
		return (chr + i);
	return (NULL);
}

static t_lst	*ft_make_node(t_lst *node, const int fd)
{
	if (!node)
	{
		node = (t_lst *)malloc(sizeof(t_lst));
		if (!node)
			return (NULL);
		ft_bzero(node->b, BUFF_SIZE + 1);
		node->fd = fd;
		node->rd = 0;
		node->sl = NULL;
		node->p_nl = NULL;
		node->next = NULL;
	}
	return (node);
}

static t_lst	*ft_get_node(t_lst *firs_node, const int fd)
{
	t_lst		*p_node;

	p_node = firs_node;
	if (p_node->fd == fd)
		return (p_node);
	while (p_node->next)
	{
		if (p_node->next->fd == fd)
			return (p_node->next);
		p_node = p_node->next;
	}
	p_node->next = ft_make_node(p_node->next, fd);
	return (p_node->next);
}

static void		ft_wr(char **line, t_lst *node, const int fd)
{
	int len;

	len = 0;
	while (ft_srch_char(node->sl, '\n') == NULL && len < 700
		&& (node->rd = read(fd, node->b, BUFF_SIZE)) > 0)
	{
		len += node->rd;
		node->ptr = node->sl;
		node->b[node->rd] = '\0';
		node->sl = ft_strjoin(node->ptr, node->b);
		ft_strdel(&node->ptr);
	}
	if (len >= 700)
		node->rd = 0;
	if ((node->p_nl = ft_srch_char(node->sl, '\n')) == NULL)
		node->p_nl = ft_srch_char(node->sl, '\0');
	*line = ft_strsub(node->sl, 0, node->p_nl - node->sl);
	if (node->p_nl && *node->p_nl == '\n')
		node->sl = ft_strcpy(node->sl, node->p_nl + 1);
	else if (node->p_nl && *node->p_nl == '\0')
		ft_strdel(&node->sl);
}

int				get_next_line_mod(const int fd, char **line)
{
	t_lst			*node;
	static t_lst	*first;

	if (fd < 0 || fd > 4864 || line == NULL || BUFF_SIZE <= 0
		|| (read(fd, NULL, 0) < 0))
		return (-1);
	if (!first)
	{
		first = ft_make_node(first, fd);
		if (!first)
			return (-1);
	}
	node = ft_get_node(first, fd);
	if (!node)
		return (-1);
	ft_wr(line, node, fd);
	if (node->rd == 0 && *line == NULL && (!node->p_nl || !*node->p_nl))
		return (0);
	return (1);
}
