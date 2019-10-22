/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:18:12 by mkopiika          #+#    #+#             */
/*   Updated: 2018/12/19 15:18:15 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*lst1;

	if (lst && f)
	{
		lst1 = lst;
		while (lst1)
		{
			f(lst1);
			lst1 = lst1->next;
		}
	}
}
