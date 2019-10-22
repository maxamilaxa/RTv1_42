/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:18:47 by mkopiika          #+#    #+#             */
/*   Updated: 2018/12/19 15:18:50 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*begin;
	t_list		*lst1;
	t_list		*newlst;

	if (!f || !lst)
		return (NULL);
	lst1 = f(lst);
	begin = ft_lstnew(lst1->content, lst1->content_size);
	if (!begin)
	{
		free(begin);
		begin = NULL;
	}
	newlst = begin;
	while ((lst = lst->next))
	{
		lst1 = f(lst);
		if (!(newlst->next = ft_lstnew(lst1->content, lst1->content_size)))
		{
			free(newlst->next);
			return (NULL);
		}
		newlst = newlst->next;
	}
	return (begin);
}
