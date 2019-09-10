/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:46:14 by yruda             #+#    #+#             */
/*   Updated: 2019/09/07 17:31:26 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	dot_to_img(t_wolf *w, int x, int y, int color)
{
	if (x >= 0 && x < IMAGE_W && y >= 0 && y < IMAGE_H)
		ft_memcpy(&(w->img->addr[y * w->img->size_line + x * 4]), &color, 4);
}

void	image_background(t_wolf *w, int color)
{
	int		i;
	int		j;

	i = 0;
	j = IMAGE_H * IMAGE_W * 4;
	while (i < j)
	{
		ft_memcpy(&(w->img->addr[i]), &color, 4);
		i += 4;
	}
}
