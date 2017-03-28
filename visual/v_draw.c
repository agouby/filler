#include "visual.h"

void	draw_pixel(int y, int x, t_v *v, int color)
{
	int i;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	i = (x * 4) + (y * v->s_line);
	v->pixel_img[i] = color;
	v->pixel_img[++i] = color >> 8;
	v->pixel_img[++i] = color >> 16;
}

void	get_square_size(t_v *v)
{
	if (v->map_s.y > v->map_s.x)
		v->sq_s = (HEIGHT / v->map_s.y);
	else
		v->sq_s = (HEIGHT / v->map_s.x);
	v->of.y = (HEIGHT - (v->sq_s * v->map_s.y)) / 2;
	v->of.x = (HEIGHT - (v->sq_s * v->map_s.x)) / 2;
}

void	draw_grid(t_v *v)
{
	t_coord dist;
	t_coord pos;
	t_coord i;

	dist.y = v->sq_s * v->map_s.y;
	dist.x = v->sq_s * v->map_s.x;
	pos.y = (1000 - (v->map_s.y * v->sq_s)) / 2;
	int posx2 = pos.y;
	i.y = 0;
	while (i.y <= v->map_s.y)
	{
		pos.x = 0;
		while (pos.x <= dist.x)
		{
			draw_pixel(pos.y, pos.x, v, 0x292929);
			draw_pixel(pos.y - 1, pos.x, v, 0x292929);
			draw_pixel(pos.y + 1, pos.x, v, 0x292929);
			pos.x++;
		}
		pos.y += v->sq_s;
		i.y++;
	}
	pos.x = 0;
	i.x = 0;
	while (i.x <= v->map_s.x)
	{
		pos.y = (1000 - (v->map_s.y * v->sq_s)) / 2;
		while (pos.y <= dist.y + posx2)
		{
			draw_pixel(pos.y, pos.x, v, 0x292929);
			draw_pixel(pos.y, pos.x - 1, v, 0x292929);
			draw_pixel(pos.y, pos.x + 1, v, 0x292929);
			pos.y++;
		}
		pos.x += v->sq_s;
		i.x++;
	}
}


void	get_color(t_v *v, char letter, int *color)
{
	if (ft_toupper(letter) == 'O')
		*color = v->p1.color;
	else if (ft_toupper(letter) == 'X')
		*color = v->p2.color;
	else
		*color = v->bk_color;
}

void	draw_square(t_v *v, int y, int x, int color)
{
	t_coord i;

	i.y = 0;
	while (i.y <= v->sq_s)
	{
		i.x = 0;
		while (i.x <= v->sq_s)
		{
			draw_pixel(y + i.y, x + i.x, v, color);
			i.x++;
		}
		i.y++;
	}
}

void	tab_del(t_v *v)
{
	int i;

	i = 0;
	while (i < v->map_s.y)
	{
		ft_strdel(&v->map[i]);
		i++;
	}
	free(v->map);
}

void	v_draw_all_squares(t_v *v)
{
	t_coord i;
	t_coord p;
	int		color;

	i.y = 0;
	p.y = 0;
	p.y = (1000 - (v->map_s.y * v->sq_s)) / 2;
	color = 0;
	get_square_size(v);
	while (v->map[i.y])
	{
		p.x = 0;
		i.x = 0;
		while (v->map[i.y][i.x])
		{
			get_color(v, v->map[i.y][i.x], &color);
			draw_square(v, p.y, p.x, color);
			p.x += v->sq_s;
			i.x++;
		}
		i.y++;
		p.y += v->sq_s;
	}
	draw_grid(v);
}
