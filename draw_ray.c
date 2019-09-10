/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 22:14:31 by yruda             #+#    #+#             */
/*   Updated: 2019/09/10 16:06:53 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_ceiling_floor(t_wolf *w, t_wall wall, int raynum, int pixel_number,
	int sizeline)
{
	int		color;

	color = CCEILING;
	pixel_number -= sizeline;
	while (wall.min - 1 >= 0)
	{
		ft_memcpy(&(w->img->addr[pixel_number]), &color, 4);
		pixel_number -= sizeline;
		wall.min--;
	}
	
	color = CFLOOR;
	pixel_number = (wall.max + 1) * sizeline + raynum * 4;
	while (wall.max + 1 < WIN_H)
	{
		ft_memcpy(&(w->img->addr[pixel_number]), &color, 4);
		pixel_number += sizeline;
		wall.max++;
	}
}

void	draw_wall_ray(t_wolf *w, t_wall wall, /*int raynum, */int pixel_number)
{
	int		color;

	color = (w->set->shadows) ?
		get_shadedcolor(wall, w->colors[wall.side]) : w->colors[wall.side];
	if (!(w->set->textures_on))// цю умову перемістити, щоб він не щоразу перевіряв, а один раз
		while (wall.min <= wall.max)
			{
				ft_memcpy(&(w->img->addr[pixel_number]), &color, 4);
				pixel_number += w->img->size_line;
				wall.min++;
			}

}

void	draw_ray(t_wolf *w, t_wall wall, int raynum)
{
	int		pixel_number;
	int		sizeline;

	sizeline = w->img->size_line;
	wall.min = ft_max(w->set->horison - wall.height / 2, 0);
	wall.max = ft_min(wall.min + wall.height, WIN_H);
	pixel_number = wall.min * w->img->size_line + raynum * 4;
	if (!(w->set->textures_on))
	{
		draw_wall_ray(w, wall, pixel_number);
		draw_ceiling_floor(w, wall, raynum, pixel_number, sizeline);
	}
	else
	{
		draw_wall_texture_ray(w, wall, raynum);	
		draw_ceiling_floor(w, wall, raynum, pixel_number, sizeline);
	}
}
	

