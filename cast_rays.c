/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:38:40 by yruda             #+#    #+#             */
/*   Updated: 2019/08/10 23:05:05 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_point	coords_to_block(t_point c, t_wolf *w)
{
	t_point	blk;

	blk.x = c.x / BLKSIZE;
	if (blk.x >= w->xwidth)
		blk.x = w->xwidth - 1;
	else if (blk.x < 0)
		blk.x = 0;
	blk.y = c.y / BLKSIZE;
	if (blk.y >= w->ylength)
		blk.y = w->ylength - 1;
	else if (blk.y < 0)
		blk.y = 0;
	return (blk);
}

int		point_iswall(t_point c, t_wolf *w)
{
	t_point	b;

	b = coords_to_block(c, w);
	if (ISWALL(w->map[b.y][b.x]))
		return (1);
	return (0);
}

/*
**	finding vertical intersections - working on 2D top-view plane:
*/

t_point	cast_vertical(t_wolf *w, float angle)
{
	int		right;
	t_point	c;
	t_point	d;
	int		delta_x;
	int		delta_y;

	right = (cos(angle) > 0) ? 1 : 0;
	delta_x = (right) ? BLKSIZE : (- BLKSIZE);
	delta_y = delta_x * tan(angle);
	c.x = (right) ? (w->xplayer / BLKSIZE) * BLKSIZE + BLKSIZE :
		(w->xplayer / BLKSIZE) * BLKSIZE - 1;
	c.y = w->yplayer + ((double)(c.x -w->xplayer) * tan(angle));//abs
	printf(COLOR_BLUE "y %d x %d : %d %d %.2f" COLOR_RESET, c.y, c.x, w->yplayer, (w->xplayer - c.x), tan(angle));
	if (point_iswall(c, w))
		return (c);
	printf("🦒");
	while (!point_iswall(c, w))
	{
		d.y = c.y + delta_y;
		d.x = c.x + delta_x;
		c.y = d.y;
		c.x = d.x;
	}
	return (c);
}

/*
**	working on 2D top-view plane:
**	finding horisontal intersections, references to function finding vertical
**	RETURNS the point of fidst intersiction on top-view 2D plane 
*/
t_point	cast_oneray(t_wolf *w, float angle)
{
	int		up;
	int		delta_x;
	int		delta_y;
	t_point	a;
	t_point	b;
	t_point	vertical;

	up = (sin(angle) > 0) ? 1 : 0;
	delta_x = BLKSIZE / tan(angle);
	delta_y = (up) ? (- BLKSIZE) : BLKSIZE;
	a.y = (up) ? (w->yplayer / BLKSIZE) * BLKSIZE - 1 :
		(w->yplayer / BLKSIZE) * BLKSIZE + BLKSIZE;
	a.x = w->xplayer + (w->yplayer - a.y) / tan(angle);
//	printf(COLOR_BLUE "%d " COLOR_RESET, a.y);
	vertical = cast_vertical(w, angle);
	printf(COLOR_YELLOW " ver %d " COLOR_RESET, vertical.y);
	if (point_iswall(a, w))
		return (abs(vertical.x - w->xplayer) >= abs(a.x - w->xplayer)) ?/*тут можливо ще треба одну точку перевіряти*/
			(a) : (vertical);
	while (!point_iswall(a, w))
	{
		b.y = a.y + delta_y;
		b.x = a.x + delta_x;
		a.y = b.y;
		a.x = b.x;
	}
	return (abs(vertical.x - w->xplayer) >= abs(a.x - w->xplayer)) ?
		(a) : (vertical);
}

int		cast_rays(t_wolf *w)
{
	double	angle;
	t_point p;
	int		i;
	int		wall_height;

	i = 0;
	wall_height = 0;
	angle = w->angle - w->set.fov / 2;
	image_background(w, CWALL_N);
	while (i < WIN_W)
	{
		p = cast_oneray(w, angle);
		printf("%d %d %d %d\n", p.y, p.x, coords_to_block(p, w).y, coords_to_block(p, w).x);
		wall_height = projected_height(w, p, angle);
		draw_ray(w, wall_height, i);
		angle += w->set.neighrays;
		i++;
	}
	printf("-------------------------\nOVER\n");
	mlx_put_image_to_window(w->mlx, w->win, w->img->ptr, 0, 0);
	return (1);
}
