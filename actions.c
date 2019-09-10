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

void	walking(t_wolf *w)
{
	double		delta_x;
	double		delta_y;
	double		temp_x;
	double		temp_y;

	delta_x = 0.0;
	delta_y = 0.0;
	if (w->keys[KEY_W] || w->keys[KEY_UP])
	{
		delta_x = w->set->speed * w->angle_cos;
		delta_y = w->set->speed * w->angle_sin;
	}
	if (w->keys[KEY_LEFT] || w->keys[KEY_A])
	{
		delta_y += - w->set->speed * w->angle_cos;
		delta_x += w->set->speed * w->angle_sin;
	}
	if (w->keys[KEY_RIGHT] || w->keys[KEY_D])
	{
		delta_x += - w->set->speed * w->angle_sin;
		delta_y += w->set->speed * w->angle_cos;
	}
	if (w->keys[KEY_S] || w->keys[KEY_DOWN])
	{
		delta_y += - w->set->speed * w->angle_sin;
		delta_x += - w->set->speed * w->angle_cos;
	}
	temp_y = (delta_y > 0) ? 4.0 : -4.0;
	temp_x = (delta_x > 0) ? 4.0 : -4.0;
	if (!point_iswall(w->xplayer + delta_x + temp_x, w->yplayer, w))
		w->xplayer += delta_x;
	if (!point_iswall(w->xplayer, w->yplayer + delta_y + temp_y, w))
		w->yplayer += delta_y;
}

void	other_actions(t_wolf *w)
{
	if (w->keys[KEY_E])
		set_angle(w, w->angle + 0.01 * w->frametime * 100);
	if (w->keys[KEY_Q])
		set_angle(w, w->angle - 0.01 * w->frametime * 100);
	if (w->keys[KEY_SHIFTL] || w->keys[KEY_SHIFTR])
		w->set->speed = 9.0 * w->frametime * 100;
	else
		w->set->speed = 5.0 * w->frametime * 100;
	if (w->keys[KEY_MINUS] || w->keys[KEY_NMINUS] ||
		w->keys[KEY_PLUS] || w->keys[KEY_NPLUS])
	{
		if ((w->keys[KEY_MINUS] || w->keys[KEY_NMINUS]) &&
			w->set->fov > 1.04719755)
			w->set->fov -= 0.05;
		else if ((w->keys[KEY_PLUS] || w->keys[KEY_NPLUS]) &&
			w->set->fov < 2.7)
			w->set->fov += 0.05;
		fov_changed(w->set);
	}
}

int		key_press(int key, t_wolf *w)
{
	if (key == KEY_ESC)
		ft_close(w);
	else if (key == KEY_R)
		w->set->shadows = (w->set->shadows) ? 0 : 1;
	else if (key == KEY_P)///////////////////////////////////////////////make
		w->set->psycho = (w->set->psycho) ? 0 : 1;
	if (key == KEY_T)
		w->set->textures_on = (w->set->textures_on) ? 0 : 1;
	w->keys[key] = 1;
	return (0);
}

int		key_release(int key, t_wolf *w)
{
	w->keys[key] = 0;
	return (0);
}

int		expose_hook(t_wolf *w)
{
	char		result[12];

	init_image(w);
	walking(w);
	other_actions(w);
	cast_rays(w);
	w->prev_time = w->now_time;
	w->now_time = get_now_time();
	w->frametime = (w->now_time - w->prev_time) / 1000000.0;
	ft_itoa((int)(1.0 / w->frametime), result);
	mlx_string_put(w->mlx, w->win, 10, 10, CWHITE, result);
	mlx_destroy_image(w->mlx, w->img->ptr);
	return (0);
}

int		mouse_move(int x, int y, t_wolf *w)/////////////a try that is failed
{
	w->mouse->previous_x = w->mouse->x;
	w->mouse->x = x;
	(void)y;
	w->angle += (w->mouse->x - w->mouse->previous_x) * 0.004;
	return (0);
}
