/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:39:21 by agouby            #+#    #+#             */
/*   Updated: 2017/03/14 09:42:17 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				get_next_line(const int fd, char **line)
{
	static char		*tail = NULL;
	int				ret;
	char			*nl;

	if ((ret = 1) && !line)
		return (-1);
	nl = NULL;
	*line = (tail != NULL) ? tail : ft_strnew(BUFF_SIZE);
	while (!nl && ret)
	{
		if ((nl = ft_strchr(*line, '\n')))
		{
			tail = ft_strdup(nl + 1);
			*nl = '\0';
			return (1);
		}
		tail = ft_strnew(BUFF_SIZE);
		if ((ret = read(fd, tail, BUFF_SIZE)) == -1)
			return (-1);
		if (ret == 0 && ft_strlen(*line))
			return (1);
		*line = (ret != 0) ? ft_strjoin_del(*line, tail, 0) : *line;
	}
	ft_strdel(&tail);
	return (0);
}
