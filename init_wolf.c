/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 13:46:50 by yruda             #+#    #+#             */
/*   Updated: 2019/08/08 19:46:21 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_settings(t_wolf *w)
{
	w->set.fov = 60.0;
	w->set.distance = CENTRE_W / tan(w->set.fov / 2);
	w->set.player_height = BLKSIZE / 2;
	w->set.fish_eye = 0;
	w->set.neighrays = w->set.fov / WIN_W;
}

int		init_wolf(t_wolf **w)
{
	*w = (t_wolf *)malloc(sizeof(t_wolf));
	(*w)->map = NULL;
	(*w)->xwidth = 0;
	(*w)->ylength = 1;
	(*w)->angle = 0.0;
	init_settings(*w);
	return (1);
}
