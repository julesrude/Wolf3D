/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:34:45 by yruda             #+#    #+#             */
/*   Updated: 2019/09/10 14:18:56 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_floor_texture_ray(t_wolf *w, t_wall wall, int raynum)
{
	double	frac;
	int		pixel;
	int		maxpixel;
	double		distancex;
	double		distancey;
	int			x;
	int			y;

	pixel = 1;
	maxpixel = WIN_H - wall.min;
	distancex = wall.point.x - w->xplayer;
	distancey = wall.point.y - w->yplayer;
	x = (int)(w->xplayer + distancex) % BLKSIZE;
	y = (int)(w->yplayer + distancey) % BLKSIZE;
	while (pixel < maxpixel)
	{
		frac = wall.min / wall.min + pixel;
		dot_to_img(w, raynum, wall.min, get_texture_color(w, wall, x, y));
		pixel++;
	}
}

void	draw_wall_texture_ray(t_wolf *w, t_wall wall, int raynum)
{
	int		x;
	int	diff;
	int	y;

	mult = (double)w->textures[0]->height / (double)wall.height;

	y = (wall.height > WIN_H) ? ((wall.height / 2) - (WIN_H / 2)) * mult : 0.0;
	if (wall.side == south || wall.side == north)
		x = wall.point.x % BLKSIZE;
	else
		x = wall.point.y % BLKSIZE;
	x = x * w->textures[0]->width / (double)BLKSIZE;/////////
	while (wall.min < wall.max)
	{
		dot_to_img(w, raynum, wall.min, get_texture_color(w, wall, x, (int)y));
		y += mult;
		wall.min++;
	}
}

// void	draw_wall_texture_ray(t_wolf *w, t_wall wall, int raynum)
// {
// 	int		x;
// 	double	mult;
// 	double	y;

// 	mult = (double)w->textures[0]->height / (double)wall.height;
// 	y = (wall.height > WIN_H) ? ((wall.height / 2) - (WIN_H / 2)) * mult : 0.0;
// 	if (wall.side == south || wall.side == north)
// 		x = wall.point.x % BLKSIZE;
// 	else
// 		x = wall.point.y % BLKSIZE;
// 	x = x * w->textures[0]->width / (double)BLKSIZE;/////////
// 	while (wall.min < wall.max)
// 	{
// 		dot_to_img(w, raynum, wall.min, get_texture_color(w, wall, x, (int)y));
// 		y += mult;
// 		wall.min++;
// 	}
// }

int		get_texture_color(t_wolf *w, t_wall wall, int x, int y)
{
	int		color;

	ft_memcpy(&color,
		&(w->textures[0]->buffer[(y * w->textures[0]->width + x) * 4]), 4);
	if (w->set->shadows)
		color = get_shadedcolor(wall, color);
	return (color);
}
