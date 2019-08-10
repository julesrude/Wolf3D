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

int		key_press(int key, t_wolf *w)
{
	if (key == KEY_ESC)
		ft_close(w);
	if (key == KEY_W)
		w->yplayer -= 5;
	if (key == KEY_S)
		w->yplayer += 5;
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
