/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:51:05 by agouby            #+#    #+#             */
/*   Updated: 2017/03/24 17:46:46 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "ft_printf.h"
# include "fcntl.h"
# include "filler.h"
# include <mlx.h>

# define WIDTH	1000
# define HEIGHT 1000
# define ESC_M	53
# define ESC_L	65307
# define SP_L	32
# define SP_M	49

typedef struct	s_v
{
	void	*mlx;
	void	*win;
	void	*img;
	int	sq_s;
	char	*pixel_img;
	int	bpp;
	int	s_line;
	int	ed;
	t_list *lst;
	t_coord	map_s;
	char	p;
	int	fd;
}		t_v;

void	create_win(t_v *v);
void	read_file(t_v *v);
void	get_infos(int fd, t_v *v, char *line);
int	key_hook(int key, t_v *v);
void	draw_square(t_v *v, t_coord pos, int color);
void	reload(t_v *v);
void	init_v(t_v *v);
void	draw_all_square(t_v *v);
void	do_shit(t_v *v);

#endif
