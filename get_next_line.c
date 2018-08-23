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
	unsigned int start;

	start = (unsigned int)file->i;
	if (!file->s[file->i])
	{
		ft_strdel(&file->s);
		return (0);
	}
	while (file->s[file->i] && file->s[file->i] != '\n')
		++file->i;
	*line = ft_strsub(file->s, start,  file->i - start);
	if (file->s[file->i])
		++file->i;
	return (1);
}

static int		gnl_remainder(t_gnl *file)
{
	char *tmp;

	if (!file->s)
	{
		if (!(file->s = ft_strdup("")))
			return (-1);
		return (1);
	}
	if (!(tmp = ft_strdup(&file->s[file->i])))
		return (-1);
	free(file->s);
	if (!(file->s = ft_strdup(tmp)))
		return (-1);
	file->i = 0;
	return (1);
}

static int		gnl_get_line(t_gnl *file, char **line)
{
	ssize_t	r;
	char	read_buf[BUFF_SIZE + 1];
	char	*t;
	// char	big_buf[BIG_BUFF_SIZE + 1];

	if (file->s && ft_strchr(&file->s[file->i], '\n'))
		return (gnl_sub_line(file, line));
	if ((gnl_remainder(file)) == -1)
		return (-1);
	while ((r = read(file->fd, read_buf, BUFF_SIZE)) > 0)
	{
		read_buf[r] = 0;
		if (!(t = (char*)malloc(sizeof(char) * ((r + ft_strlen(file->s)) + 1))))
			return (-1);
		ft_strcpy(t, file->s);
		ft_strcat(t, read_buf);
		free(file->s);
		if (!(file->s = ft_strdup(t)))
			return (-1);
		free(t);
		if (ft_strchr(read_buf, '\n'))
			break ;
	}
	if (r == -1)
		return (-1);
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
	file->i = 0;
	file->fd = fd;
	file->next = *g;
	*g = file;
	return (file);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl	*g;
	t_gnl			*curent;

	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	if (!(curent = gnl_add_or_get_file(&g, fd)))
		return (-1);
	return (gnl_get_line(curent, line));
}
