/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 22:14:31 by yruda             #+#    #+#             */
/*   Updated: 2019/08/12 21:31:03 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	dot_to_img(t_wolf *w, int x, int y, int color)
{
	if (x >= 0 && x < IMAGE_W && y >= 0 && y < IMAGE_H)
		ft_memcpy(&(w->img->addr[(y * IMAGE_W + x) * 4]), &color, 4);
}

void	image_background(t_wolf *w, int color)
{
	int		i;
	int		j;

	i = 0;
	j = IMAGE_H * IMAGE_W * 4;
	while (i < j)
	{
		ft_memcpy(&(w->img->addr[i]), &color, 4);
		i += 4;
	}
}

void	draw_wall_ray(t_wolf *w, int wall_height, int raynum)
{
	int		min;
	int		i;

	min = w->set.horison - wall_height / 2;
	i = 0;
	while(i < wall_height)
	{
		dot_to_img(w, raynum, min, CWALL_S);
		min++;
		i++;
	}
}

void	draw_ray(t_wolf *w, int wall_height, int raynum)
{
	draw_wall_ray(w, wall_height, raynum);
}
