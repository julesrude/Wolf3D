/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:22:24 by yruda             #+#    #+#             */
/*   Updated: 2019/08/10 21:49:45 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		find_distance(t_wolf *w, t_point p, double angle)//cos or sin instead of this, but precomputed
{
	int		dist;

	dist = sqrt(pow(w->yplayer - p.y, 2) + pow(w->xplayer - p.x, 2));
	dist = dist * cos(angle - w->angle);
	return (dist);
}

int		projected_height(t_wolf *w, t_point p, double angle)
{
	int		p_height;

	p_height = (double)BLKSIZE / (double)find_distance(w, p, angle)
		* (double)w->set.distance;
	return (p_height);
}
