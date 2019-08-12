/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:22:24 by yruda             #+#    #+#             */
/*   Updated: 2019/08/12 21:30:47 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double		find_distance(t_wolf *w, t_dpoint p, double angle)//cos or sin instead of this, but precomputed
{
	double	dist;

	dist = sqrt(pow(w->yplayer - p.y, 2) + pow(w->xplayer - p.x, 2));
	dist = dist * cos(angle - w->angle);
	return (dist);
}

int		projected_height(t_wolf *w, t_dpoint p, double angle)
{
	int		p_height;

	p_height = (double)BLKSIZE / find_distance(w, p, angle)
		* (double)w->set.distance;
	return (p_height);
}
