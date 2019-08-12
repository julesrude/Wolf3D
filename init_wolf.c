/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 13:46:50 by yruda             #+#    #+#             */
/*   Updated: 2019/08/12 17:56:26 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_settings(t_settings *set)
{
	set->fov = 60.0 * ANGLE;
	set->distance = CENTRE_W / tan(set->fov / 2);
	set->player_height = BLKSIZE / 2;
	set->horison = WIN_H / 2;
	set->fish_eye = 0;
	set->blksize = 128;
	set->neighrays = set->fov / WIN_W;
	set->speed = 5;
}

int		init_wolf(t_wolf *w)
{	
	w->map = NULL;
	w->xwidth = 0;
	w->ylength = 1;
	w->angle = 270.0 * ANGLE;
	w->mlx = NULL;
	w->win = NULL;
	init_settings(&(w->set));
	return (1);
}
