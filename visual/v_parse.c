/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:05:29 by agouby            #+#    #+#             */
/*   Updated: 2017/10/11 03:55:48 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	v_get_player(t_v *v, char *line)
{
	char *s;
	char *e;

	s = ft_strrchr(line, '/');
	e = ft_strrchr(line, '.');
	*e = '\0';
	if (ft_atoi(line + 10) == 1 && s && e)
		v->p1.name = ft_strdup(s + 1);
	else if (s && e)
		v->p2.name = ft_strdup(s + 1);
	v->p1.c = 'O';
	v->p2.c = 'X';
	ft_strdel(&line);
}

void	v_get_size_map(t_v *v, char *line)
{
	v->map_s.y = ft_atoi(line + 8);
	v->map_s.x = ft_atoi(line + 8 + ft_count_digit(v->map_s.y, 10));
	ft_strdel(&line);
}

void	v_get_map(t_v *v, char *line)
{
	int i;
	int n;

	i = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	v->p1.nb_pos = 0;
	v->p2.nb_pos = 0;
	while (i < v->map_s.y && get_next_line(0, &line))
	{
		n = 0;
		v->map[i] = ft_strdup(line + 4);
		while (v->map[i][n])
		{
			if (ft_toupper(v->map[i][n]) == v->p1.c)
				v->p1.nb_pos++;
			else if (ft_toupper(v->map[i][n]) == v->p2.c)
				v->p2.nb_pos++;
			n++;
		}
		ft_strdel(&line);
		i++;
	}
	v->map[i] = NULL;
}

void	v_read_stdin(t_v *v)
{
	char *line;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Plateau"))
			v_get_map(v, line);
		if (ft_strstr(line, "Piece"))
		{
			ft_strdel(&line);
			return ;
		}
	}
}
