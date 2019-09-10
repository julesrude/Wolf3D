/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:38:40 by yruda             #+#    #+#             */
/*   Updated: 2019/09/10 12:53:46 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	finding vertical intersections - working on 2D top-view plane:
*/

t_dpoint	cast_vertical(t_wolf *w, float angle, float angle_tan)
{
	int			right;
	t_dpoint	c;
	t_dpoint	d;
	double		delta_x;
	double		delta_y;

	right = (cos(angle) > 0) ? 1 : 0;
	delta_x = (right) ? BLKSIZE : (- BLKSIZE);
	delta_y = delta_x * angle_tan;
	c.x = (right) ? ((int)w->xplayer / BLKSIZE) * BLKSIZE + BLKSIZE :
		((int)w->xplayer / BLKSIZE) * BLKSIZE - 1.0;
	if (right)
		c.y = w->yplayer + ((c.x - w->xplayer) * angle_tan);
	else
		c.y = w->yplayer + ((c.x + 1.0 - w->xplayer) * angle_tan);
	while (!point_iswall(c.x, c.y, w))
	{
		d = (t_dpoint){.x = c.x + delta_x, .y = c.y + delta_y };
		c = (t_dpoint){ d.x, d.y };
	}
	if (!right)
		c.x++;
	return (c);
}

t_dpoint	cast_horisontal(t_wolf *w, float angle, float angle_tan)
{
	t_dpoint	a;
	t_dpoint	b;
	int			up;
	double		delta_x;//
	double		delta_y;//

	up = (sin(angle) < 0) ? 1 : 0;
	delta_y = (up) ? (- BLKSIZE) : BLKSIZE;
	delta_x = delta_y / angle_tan;
	a.y = (up) ? ((int)w->yplayer / BLKSIZE) * BLKSIZE - 1.0 :
		((int)w->yplayer / BLKSIZE) * BLKSIZE + BLKSIZE;
	if (up)
		a.x = w->xplayer + (a.y + 1.0 - w->yplayer) / angle_tan;
	else
		a.x = w->xplayer + (a.y - w->yplayer) / angle_tan;
	while (!point_iswall(a.x, a.y, w))
	{
		b = (t_dpoint){.x = a.x + delta_x, .y = a.y + delta_y};
		a = (t_dpoint){ .x = b.x, .y = b.y };
	}
	if (up)
		a.y++;
	return (a);
}

/*
**	working on 2D top-view plane:
**	finding horisontal intersections, references to function finding vertical
**	RETURNS the point of fidst intersiction on top-view 2D plane 
*/
t_dpoint	cast_oneray(t_wolf *w, t_wall *wall, float angle, float angle_tan)
{
	t_dpoint	vertical;
	t_dpoint	horisontal;
	double		dist_ver;
	double		dist_hor;

	vertical = cast_vertical(w, angle, angle_tan);
	horisontal = cast_horisontal(w, angle, angle_tan);
	dist_ver = find_distance(w, vertical);
	dist_hor = find_distance(w, horisontal); 
	if (dist_hor < dist_ver)
	{
		wall->distance = dist_hor;
		wall->side = (sin(angle) <= 0) ? north : south;
		return (horisontal);
	}
	else
	{
		wall->distance = dist_ver;
		wall->side = (cos(angle) <= 0) ? west : east;
		return (vertical);
	}
	return (vertical);
}

int		cast_rays(t_wolf *w)
{
	double		angle;
	t_wall		wall;
	t_dpoint	p;
	int			i;

	i = 0;
	wall.height = 0;
	angle = w->angle - w->set->fov / 2;
	while (i < WIN_W)
	{
		p = cast_oneray(w, &wall, angle, tan(angle));
		wall.distance = find_corrected_distance(w, angle, wall.distance);
		wall.height = ((double)BLKSIZE / wall.distance) * (double)w->set->distance;//projected_height(w, wall.distance);
		wall.point = (t_point){ p.x, p.y };
		draw_ray(w, wall, i);
		angle += w->set->neighrays;
		i++;
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img->ptr, 0, 0);
	return (1);
}
