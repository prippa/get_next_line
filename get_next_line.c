/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:47:04 by prippa            #+#    #+#             */
/*   Updated: 2017/11/22 17:47:18 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		gnl_sub_line(t_gnl *file, char **line)
{
	return (1);
}

static int		gnl_get_line(t_gnl *file, char **line)
{
	ssize_t	ret;
	char	read_buf[BUFF_SIZE + 1];
	// char	big_buf[]

	if (file->s && ft_strchr(file->s, '\n'))
		return (gnl_sub_line(file, line));
	while ((ret = read(file->fd, read_buf, BUFF_SIZE)) > 0)
	{

	}
	if (!file->s || ret == -1)
		return (ret);
	return (gnl_sub_line(file, line));
}

static t_gnl	*gnl_add_or_get_file(t_gnl **g, int fd)
{
	t_gnl *file;

	file = *g;
	while (file)
	{
		if (file->fd == fd)
			return (file);
		file = file->next;
	}
	if (!(file = (t_gnl *)malloc(sizeof(t_gnl))))
		return(NULL);
	file->s = NULL;
	file->fd = fd;
	file->next = *g;
	*g = file;
	return (file);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl	*g;
	static t_gnl	*curent;

	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	if (!g || curent->fd != fd)
		if (!(curent = gnl_add_or_get_file(&g, fd)))
			return (-1);
	return (gnl_get_line(curent, line));
}
