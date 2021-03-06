/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:11:54 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:11:57 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_wcharlen(wchar_t wc)
{
	if (wc <= 0x7f)
		return (1);
	else if (wc <= 0x7ff)
		return (2);
	return (3);
}

static size_t	ft_wstrlen(wchar_t *ws)
{
	size_t	len;

	len = 0;
	if (!ws)
		return (0);
	while (ws[len])
		len++;
	return (len);
}

static size_t	ft_wbytelen(wchar_t *ws)
{
	size_t	byte_len;
	size_t	len;

	byte_len = 0;
	len = ft_wstrlen(ws);
	while (len)
	{
		byte_len += ft_wcharlen(*ws);
		ws++;
		len--;
	}
	return (byte_len);
}

static int		ft_pull_wchar(wchar_t wc, char *new_obj, int i)
{
	int		size;

	size = ft_wcharlen(wc);
	if (size == 1)
		new_obj[i++] = wc;
	else if (size == 2)
	{
		new_obj[i++] = (wc >> 6) + 0xC0;
		new_obj[i++] = (wc & 0x3F) + 0x80;
	}
	else if (size == 3)
	{
		new_obj[i++] = (wc >> 12) + 0xE0;
		new_obj[i++] = ((wc >> 6) & 0x3F) + 0x80;
		new_obj[i++] = (wc & 0x3F) + 0x80;
	}
	else
	{
		new_obj[i++] = (wc >> 18) + 0xF0;
		new_obj[i++] = ((wc >> 12) & 0x3F) + 0x80;
		new_obj[i++] = ((wc >> 6) & 0x3F) + 0x80;
		new_obj[i++] = (wc & 0x3F) + 0x80;
	}
	return (i);
}

char			*ft_wstr_to_str(wchar_t *ws)
{
	char	*new_obj;
	int		i;
	int		len;

	if (!ws)
		return (NULL);
	len = ft_wbytelen(ws);
	if (!(new_obj = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	new_obj[len] = '\0';
	len = 0;
	i = 0;
	while (ws[i])
		len = ft_pull_wchar(ws[i++], new_obj, len);
	return (new_obj);
}
