/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:54:33 by yruda             #+#    #+#             */
/*   Updated: 2019/08/08 17:14:46 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		init_mlx(t_wolf *w)
{
	if (!(w->mlx = mlx_init()))
		put_error(ERR_MESSAGE,
			"wolf3d: failed to connect software and the display", 1);
	if (!(w->win = mlx_new_window(w->mlx, WIN_W, WIN_H, "wuf-wuf")))
		put_error(ERR_MESSAGE, "wolf3d: failed to create new window", 1);
	if (!(w->img = (t_image *)malloc(sizeof(t_image))))
		put_error(ERR_MESSAGE, "wolf3d: failed allocate memory", 1);
	if (!(w->img->ptr = mlx_new_image(w->mlx, WIN_W, WIN_H)))
		put_error(ERR_MESSAGE, "wolf3d: failed to create image", 1);
	if (!(w->img->addr = mlx_get_data_addr(w->img->ptr, &(w->img->bpp),
		&(w->img->size_line), &(w->img->endian))))
		put_error(ERR_MESSAGE, "wolf3d: failed to get image address", 1);
	return (1);
}
