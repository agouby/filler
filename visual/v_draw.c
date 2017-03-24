#include "visual.h"

static void		draw_pixel(t_coord p, t_v *v, int color)
{
	int i;

	if ((int)p.x < 0 || (int)p.x >= WIDTH || (int)p.y < 0 || (int)p.y >= HEIGHT)
		return ;
	i = ((int)p.x * 4) + ((int)p.y * v->s_line);
	v->pixel_img[i] = color;
	v->pixel_img[++i] = color >> 8;
	v->pixel_img[++i] = color >> 16;
}

void	get_square_size(t_v *v)
{
	if (v->map_s.y > v->map_s.x)
		v->sq_s = (WIDTH / v->map_s.y);
	else
		v->sq_s = (HEIGHT / v->map_s.x);
}

void	draw_grid(t_v *v)
{
	t_coord dist;
	t_coord pos;
	t_coord i;

	dist.y = v->sq_s * v->map_s.y;
	dist.x = v->sq_s * v->map_s.x;
	pos.y = 0;
	i.y = 0;
	while (i.y <= v->map_s.y)
	{
		pos.x = 0;
		while (pos.x <= dist.x + 0)
		{
			draw_pixel(pos, v, 0xFFFFFF);
			pos.x++;
		}
		pos.y += v->sq_s;
		i.y++;
	}
	pos.x = 0;
	i.x = 0;
	while (i.x <= v->map_s.x)
	{
		pos.y = 0;
		while (pos.y <= dist.y)
		{
			draw_pixel(pos, v, 0xFFFFFF);
			pos.y++;
		}
		pos.x += v->sq_s;
		i.x++;
	}
}

void	draw_square(t_v *v, t_coord pos, int color)
{
	t_coord i;
	t_coord p;

	i.y = 0;
	get_square_size(v);
	while (i.y < v->sq_s)
	{
		i.x = 0;
		while (i.x < v->sq_s)
		{
			p.x = pos.x + i.x;
			p.y = pos.y + i.y;
			draw_pixel(p, v, color);
			i.x++;
		}
		i.y++;
	}
}

int	get_color(t_coord i, t_list *lst)
{
	int color;

	if (((char **)lst->content)[i.y][i.x] == 'O')
		color = 0x0000FF;
	else if (((char **)lst->content)[i.y][i.x] == 'X')
		color = 0xFF0000;
	else
		color = 0x000000;
	return (color);
}
void	draw_all_square(t_v *v)
{
	t_coord p;
	t_coord i;
	int color;

	p.y = 0;
	i.y = 0;
	while (i.y < v->map_s.y)
	{
		i.x = 0;
		p.x = 0;
		while (i.x < v->map_s.x)
		{
			color = get_color(i, v->lst);
			draw_square(v, p, color);
			p.x += v->sq_s;
			i.x++;
		}
		p.y += v->sq_s;
		i.y++;
	}
	draw_grid(v);
}
