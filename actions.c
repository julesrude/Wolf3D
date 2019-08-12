/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:50:12 by yruda             #+#    #+#             */
/*   Updated: 2019/08/08 19:52:29 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	walking(int key, t_wolf *w)
{
	int		delta_x;
	int		delta_y;

	delta_x = 0;
	delta_y = 0;
	if (key == KEY_W || key == KEY_UP)
	{
		delta_x = w->set.speed * cos(w->angle);
		delta_y = w->set.speed * sin(w->angle);
	}
	if (key == KEY_LEFT || key == KEY_A)
	{
		delta_y = - w->set.speed * cos(w->angle);
		delta_x = w->set.speed * sin(w->angle);
	}
	if	(key == KEY_RIGHT || key == KEY_D)
	{
		delta_x = - w->set.speed * sin(w->angle);
		delta_y = w->set.speed * cos(w->angle);
	}
	if (key == KEY_S || key == KEY_DOWN)
	{
		delta_y = - w->set.speed * sin(w->angle);
		delta_x = - w->set.speed * cos(w->angle);
	}
	w->xplayer += delta_x;
	w->yplayer += delta_y;
}

int		key_press(int key, t_wolf *w)
{
	if (key == KEY_ESC)
		ft_close(w);
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN ||
		key == KEY_W || key == KEY_S || key == KEY_D || key == KEY_A)
		walking(key, w);
	if (key == KEY_E)
		w->angle += 0.017;
	if (key == KEY_Q)
		w->angle -= 0.017;
	cast_rays(w);
	return (0);
}

// int		mouse_press(int key, int x, int y, t_mlx *m)
// {
// 	if (key == 4 || key == 5)
// 		mouse_scroll(key, x, y, m);
// 	if (key == 1)
// 		m->mouse->is_pressed = 1;
// 	return (0);
// }
