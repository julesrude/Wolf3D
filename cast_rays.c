/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:38:40 by yruda             #+#    #+#             */
/*   Updated: 2019/08/12 21:30:36 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_point	coords_to_block(t_dpoint c, t_wolf *w)
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

int		point_iswall(t_dpoint c, t_wolf *w)
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

t_dpoint	cast_vertical(t_wolf *w, float angle)
{
	int			right;
	t_dpoint	c;
	t_dpoint	d;
	double		delta_x;
	double		delta_y;

	right = (cos(angle) > 0) ? 1 : 0;
	delta_x = (right) ? BLKSIZE : (- BLKSIZE);
	delta_y = delta_x * tan(angle);
	c.x = (right) ? (w->xplayer / BLKSIZE) * BLKSIZE + BLKSIZE :
		(w->xplayer / BLKSIZE) * BLKSIZE - 1;
	if (right)
		c.y = w->yplayer + ((double)(c.x - w->xplayer + 1) * tan(angle));//abs
	else
		c.y = w->yplayer + ((double)(c.x - w->xplayer - 1) * tan(angle));//abs
	if (point_iswall(c, w))
		return (c);
	while (!point_iswall(c, w))
	{
		d.y = c.y + delta_y;//
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
t_dpoint	cast_oneray(t_wolf *w, float angle)
{
	int		up;
	double		delta_x;//
	double		delta_y;//
	t_dpoint	a;
	t_dpoint	b;
	t_dpoint	vertical;

	up = (sin(angle) < 0) ? 1 : 0;
	delta_y = (up) ? (- BLKSIZE) : BLKSIZE;
	delta_x = delta_y / tan(angle);
	a.y = (up) ? (w->yplayer / BLKSIZE) * BLKSIZE - 1 :
		(w->yplayer / BLKSIZE) * BLKSIZE + BLKSIZE;
	a.x = w->xplayer + (a.y - w->yplayer) / tan(angle);
	vertical = cast_vertical(w, angle);
	if (point_iswall(a, w))
		return (fabs(vertical.x - w->xplayer) >= fabs(a.x - w->xplayer)) &&
			fabs(vertical.y - w->yplayer) >= fabs(a.y - w->yplayer) ?/*тут можливо ще треба одну точку перевіряти, а може не треба*/
			(a) : (vertical);
	while (!point_iswall(a, w))
	{
		b.y = a.y + delta_y;
		b.x = a.x + delta_x;
		a.y = b.y;
		a.x = b.x;
	}
	return ((fabs(vertical.x - w->xplayer) >= fabs(a.x - w->xplayer))) &&
		fabs(vertical.y - w->yplayer) >= fabs(a.y - w->yplayer) ?
		(a) : (vertical);
}

int		cast_rays(t_wolf *w)
{
	double		angle;
	t_dpoint	p;
	int			i;
	int			wall_height;

	i = 0;
	wall_height = 0;
	angle = w->angle - w->set.fov / 2;
	image_background(w, CFLOOR);
	while (i < WIN_W)
	{
		p = cast_oneray(w, angle);
		wall_height = projected_height(w, p, angle);
		draw_ray(w, wall_height, i);
		angle += w->set.neighrays;
		i++;
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img->ptr, 0, 0);
	return (1);
}
