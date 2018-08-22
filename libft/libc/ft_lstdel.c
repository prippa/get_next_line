/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:37:46 by prippa            #+#    #+#             */
/*   Updated: 2017/11/08 13:40:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new_obj;

	if (alst && del)
	{
		new_obj = *alst;
		while (new_obj)
		{
			del(new_obj->content, new_obj->content_size);
			free(new_obj);
			new_obj = new_obj->next;
		}
		*alst = NULL;
	}
}
