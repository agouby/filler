#include "visual.h"

static void		draw_pixel(int y, int x, t_v *v, int color)
{
	int i;

	if ((int)x < 0 || (int)x >= WIDTH || (int)y < 0 || (int)y >= HEIGHT)
		return ;
	i = ((int)x * 4) + ((int)y * v->s_line);
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

/*void	draw_grid(t_v *v)
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
			draw_pixel(pos, v, 0x000000);
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
			draw_pixel(pos, v, 0x000000);
			pos.y++;
		}
		pos.x += v->sq_s;
		i.x++;
	}
}
*/

int	get_color(int i, char *line)
{
	int color;

	if (line[i] == 'O')
		color = 0x0000FF;
	else if (line[i] == 'X')
		color = 0xFF0000;
	else
		color = 0xFFFFFF;
	return (color);
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

void	draw_square_line(t_v *v, int y ,char *line)
{
	int i = 0;
	int sq_tmp;
	int color;

	sq_tmp = 0;
	while (line[i])
	{
		color = get_color(i, line);
		if (i == 0)
			draw_square(v, y, i, color);
		else
			draw_square(v, y, sq_tmp, color);
		sq_tmp += v->sq_s;
		i++;
	}
}









