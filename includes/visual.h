/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:51:05 by agouby            #+#    #+#             */
/*   Updated: 2017/03/22 22:25:16 by agouby           ###   ########.fr       */
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
# define ESC	53

typedef struct	s_v
{
	void	*mlx;
	void	*win;
	t_coord	map_s;
	char	p;
}				t_v;

#endif
