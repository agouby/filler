/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:05:29 by agouby            #+#    #+#             */
/*   Updated: 2017/03/27 18:49:10 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	v_get_player(t_v *v, char *line)
{
	if (ft_atoi(line + 10) == 1 && ft_strstr(line, "agouby"))
	{
		v->me = 'O';
		v->him = 'X';
	}
	else
	{
		v->me = 'X';
		v->him = 'O';
	}
//	ft_strdel(&line);
}

void	v_get_size_map(t_v *v, char *line)
{
	v->map_s.y = ft_atoi(line + 8);
	v->map_s.x = ft_atoi(line + 8 + ft_count_digit(v->map_s.y, 10));
//	ft_strdel(&line);
}

void	v_get_map(t_v *v, char *line)
{
	int i;

	i = 0;
	get_next_line(0, &line);
//	ft_strdel(&line);
	v->map = (char **)malloc(sizeof(char *) * (v->map_s.y + 1));
	while (i < v->map_s.y && get_next_line(0, &line))
	{
		v->map[i++] = ft_strdup((&line[4]));
		ft_strdel(&line);
	}
	v->map[i] = NULL;
}

void	v_parse_file(t_v *v)
{
	char *line;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "$$$"))
			v_get_player(v, line);
		if (ft_strstr(line, "Plateau"))
		{
			v_get_size_map(v, line);
			v_get_map(v, line);
		}
		if (ft_strstr(line, "Piece"))
		{
//			ft_strdel(&line);
			return ;
		}
	}
}
