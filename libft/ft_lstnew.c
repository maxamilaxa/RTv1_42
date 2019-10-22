/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:52:22 by mkopiika          #+#    #+#             */
/*   Updated: 2018/12/17 15:52:25 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*lst;

	if (!(lst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		lst->content = (void*)malloc(content_size);
		if (!lst->content)
		{
			free(lst);
			return (NULL);
		}
		lst->content_size = content_size;
		lst->content = ft_memcpy(lst->content, content, content_size);
	}
	lst->next = NULL;
	return (lst);
}
