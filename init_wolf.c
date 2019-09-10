/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 13:46:50 by yruda             #+#    #+#             */
/*   Updated: 2019/09/09 18:34:30 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_settings(t_settings *set)
{
	set->fov = 60.0 * ANGLE;
	set->distance = CENTRE_W / tan(set->fov / 2);
	set->view_distance = 2 * set->distance;
	set->player_height = BLKSIZE / 2;
	set->horison = WIN_H / 2;
	set->fish_eye = 0;
	set->neighrays = set->fov / WIN_W;
	set->speed = 0; //9;
	set->shadows = 1;
	set->textures_on = 0;//
}

void	set_angle(t_wolf *w, double angle)
{
	w->angle = angle;
	w->angle_cos = cos(w->angle);
	w->angle_sin = sin(w->angle);
	w->angle_tan = tan(w->angle);
}

void	init_colors_textures(t_wolf *w)
{
	int height;
	int width;

	height = 0;
	width = 0;
	w->colors[0] = CWALL_N;
	w->colors[1] = CWALL_S;
	w->colors[2] = CWALL_E;
	w->colors[3] = CWALL_W;
	w->colors[4] = CFLOOR;
	w->colors[5] = CCEILING;
	w->textures[0] = mlx_xpm_file_to_image(w->mlx,
		"./assets/textures/black-brick-wall-texture.xpm",
		&width, &height);
	w->textures[1] = mlx_xpm_file_to_image(w->mlx,
		"./assets/textures/metallic_squares.xpm",
		&width, &height);
}

int		init_wolf(t_wolf *w)
{	
	w->map = NULL;
	w->map_img = NULL;
	w->xwidth = 0;
	w->ylength = 1;
	set_angle(w, 270.0 * ANGLE);
	w->mlx = NULL;
	w->win = NULL;
	ft_bzero(w->keys, 280);
	w->set = malloc(sizeof(t_settings));
	init_settings(w->set);
	w->mouse = malloc(sizeof(w->mouse));///////////
	w->mouse->x = 0;
	w->mouse->previous_x = 0;
	w->now_time = get_now_time();
	w->prev_time = w->now_time;
	w->frametime = 0.018;
	return (1);
}

void	fov_changed(t_settings *set)
{
	set->distance = CENTRE_W / tan(set->fov / 2);
	set->neighrays = set->fov / WIN_W;
}
