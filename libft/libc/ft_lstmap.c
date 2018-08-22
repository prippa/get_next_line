/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:38:55 by prippa            #+#    #+#             */
/*   Updated: 2017/11/08 13:39:04 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *link;
	t_list *new_obj;

	if (!lst)
		return (NULL);
	if ((new_obj = ft_lstnew(lst->content, lst->content_size)) == NULL)
		return (NULL);
	new_obj = f(lst);
	link = new_obj;
	while (lst->next)
	{
		link->next = f(lst->next);
		link = link->next;
		lst = lst->next;
	}
	return (new_obj);
}
