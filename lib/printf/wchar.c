/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 21:13:14 by agouby            #+#    #+#             */
/*   Updated: 2017/03/08 00:00:11 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_charlen(wchar_t wchar)
{
	if (wchar <= 0x7f)
		return (1);
	else if (wchar <= 0x7ff)
		return (2);
	else if (wchar <= 0xffff)
		return (3);
	else
		return (4);
}

size_t		get_wstrlen(wchar_t *wstr)
{
	size_t	len;

	len = 0;
	if (!wstr)
		return (0);
	while (*(wstr++))
		len++;
	return (len);
}

size_t		get_byte_len(wchar_t *wstr)
{
	size_t	len;
	size_t	byte;

	len = get_wstrlen(wstr);
	byte = 0;
	while (len > 0)
	{
		byte += get_charlen(*wstr);
		wstr++;
		len--;
	}
	return (byte);
}

int			transform_char(wchar_t wchar, char *new, int i)
{
	int		size;

	size = get_charlen(wchar);
	if (size == 1)
		new[i++] = wchar;
	else if (size == 2)
	{
		new[i++] = (wchar >> 6) + 0xC0;
		new[i++] = (wchar & 0x3F) + 0x80;
	}
	else if (size == 3)
	{
		new[i++] = (wchar >> 12) + 0xE0;
		new[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		new[i++] = (wchar & 0x3F) + 0x80;
	}
	else
	{
		new[i++] = (wchar >> 18) + 0xF0;
		new[i++] = ((wchar >> 12) & 0x3F) + 0x80;
		new[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		new[i++] = (wchar & 0x3F) + 0x80;
	}
	return (i);
}

char		*transform_wstr(wchar_t *wstr)
{
	char	*new;
	int		i;
	int		k;
	int		len;

	if (!wstr)
		return (0);
	i = 0;
	k = 0;
	len = get_byte_len(wstr);
	new = (char*)malloc(sizeof(char) * len);
	new[len] = '\0';
	while (wstr[k])
	{
		i = transform_char(wstr[k], new, i);
		k++;
	}
	return (new);
}
