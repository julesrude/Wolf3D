/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:38:40 by yruda             #+#    #+#             */
/*   Updated: 2019/08/08 19:58:04 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_point	coords_to_block(t_point c)
{
	t_point	b;

	b.x = c.x / BLKSIZE;
	b.y = c.y / BLKSIZE;
	return (b);
}

int		point_iswall(t_point c, t_wolf *w)
{
	t_point	b;

	b = coords_to_block(c);
	if (ISWALL(w->map[b.y][b.x]))
		return (1);
	return (0);
}

// int		cast_oneray(t_wolf *w)
// {
// 	(void *)w;
// 	return (1);
// }

int		cast_rays(t_wolf *w)
{
	int		y;
	int		x;

	y = (w->yplayer / BLKSIZE) * BLKSIZE - 1;
	x = w->xplayer + (w->yplayer - y) * tan(w->angle);
	printf(COLOR_BLUE "ray: w->yplayer %d | %d | %d\n", w->yplayer, y, x);
	return (1);
}
