/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:54:33 by yruda             #+#    #+#             */
/*   Updated: 2019/09/08 21:08:38 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	if returns (-1) - error
*/

void	init_image(t_wolf *w)
{
	if (!(w->img->ptr = mlx_new_image(w->mlx, IMAGE_W, IMAGE_H)))
		put_error(ERR_MESSAGE, "wolf3d: failed to create image", 1);
	if (!(w->img->addr = mlx_get_data_addr(w->img->ptr, &(w->img->bpp),
		&(w->img->size_line), &(w->img->endian))))
		put_error(ERR_MESSAGE, "wolf3d: failed to get image address", 1);
}

void	init_mlx(t_wolf *w)
{
	if (!(w->mlx = mlx_init()))
		put_error(ERR_MESSAGE,
			"wolf3d: failed to connect software and the display", 1);
	if (!(w->win = mlx_new_window(w->mlx, WIN_W, WIN_H, "wuf-wuf")))
		put_error(ERR_MESSAGE, "wolf3d: failed to create new window", 1);
	if (!(w->img = (t_image *)malloc(sizeof(t_image))))
		put_error(ERR_MESSAGE, "wolf3d: failed allocate memory", 1);
	init_image(w);
	
}

int		init_map_img(t_wolf *w)
{
	if (!(w->map_img = (t_image *)malloc(sizeof(t_image))))
		put_error(ERR_MESSAGE, "wolf3d: failed allocate memory", 1);
	if (!(w->map_img->ptr = mlx_new_image(w->mlx, MAPIMG_W, MAPIMG_H)))
		put_error(ERR_MESSAGE, "wolf3d: failed to create image", 1);
	if (!(w->map_img->addr = mlx_get_data_addr(w->map_img->ptr, &(w->map_img->bpp),
		&(w->map_img->size_line), &(w->map_img->endian))))
		put_error(ERR_MESSAGE, "wolf3d: failed to get image address", 1);
	return (1);
}
