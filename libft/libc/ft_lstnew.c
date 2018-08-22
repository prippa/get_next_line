/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:36:41 by prippa            #+#    #+#             */
/*   Updated: 2017/11/08 13:36:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_obj;
	void	*data;

	if ((data = ft_memalloc(content_size + 1)) == NULL)
		return (NULL);
	if (content)
		ft_memcpy(data, content, content_size);
	else
	{
		data = NULL;
		content_size = 0;
	}
	if ((new_obj = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new_obj->content = data;
	new_obj->content_size = content_size;
	new_obj->next = NULL;
	return (new_obj);
}
