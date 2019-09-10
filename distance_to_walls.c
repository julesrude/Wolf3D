/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:22:24 by yruda             #+#    #+#             */
/*   Updated: 2019/09/09 15:15:00 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double		find_distance(t_wolf *w, t_dpoint p)//cos or sin instead of this, but precomputed
{
	double	dist;

	dist = sqrt(pow((double)w->yplayer - p.y, 2) + pow((double)w->xplayer - p.x, 2));
	return (dist);
}

double		find_corrected_distance(t_wolf *w, double angle, double dist)//cos or sin instead of this, but precomputed
{
	dist = dist * cos(angle - w->angle);
	return (dist);
}

int		projected_height(t_wolf *w, double distance)//////////not needed?
{
	return(((double)BLKSIZE / distance) * (double)w->set->distance);
}
