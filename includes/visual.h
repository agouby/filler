/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:51:05 by agouby            #+#    #+#             */
/*   Updated: 2017/03/26 16:39:41 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "ft_printf.h"
# include "filler.h"
# include <mlx.h>

# define WIDTH	2000
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
	char	*pixel_img;
	int		bpp;
	int		s_line;
	int		ed;
	int		sq_s;
	char	player;
	t_coord	map_s;
}				t_v;

void	create_win(t_v *v);
int		key_hook(int key, t_v *v);
//void	reload(t_v *v);

#endif
